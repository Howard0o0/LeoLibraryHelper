#include "muduo/net/http/HttpServer.h"
#include "muduo/net/http/HttpRequest.h"
#include "muduo/net/http/HttpResponse.h"
#include "muduo/net/EventLoop.h"
#include "muduo/base/Logging.h"

#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <string>

#include "stuInfo.pb.h"
#include "LibServer.h"

LibServer::LibServer(ServerInfo srvInfo, RedisInfo rdsInfo):
						server_(&loop_, srvInfo.serveraddr_, srvInfo.servername_), 
						redis_(rdsInfo.redisIp_, rdsInfo.redisPort_, rdsInfo.redisPwd_)
{
	server_.setHttpCallback(std::bind(&LibServer::onRequest, this, std::placeholders::_1, std::placeholders::_2));
	redis_.connect();
}

void LibServer::startWithThreads(int threadnum)
{
	server_.setThreadNum(threadnum);
	server_.start();
	loop_.loop();
}

void LibServer::onRequest(const muduo::net::HttpRequest& req,
							muduo::net::HttpResponse* resp)
{
	showHttpRequest(req);

	if(req.methodString() == "GET" && req.query().size()){
		StuInfo stu = HttpParesr(req.query());
		funcGet(resp, stu);
	}else if(req.methodString() == "POST" && req.query().size()){
		StuInfo stu = HttpParesr(req.query());
		funcPost(resp, stu);
	}else{
		funcError(resp);
	}

}

StuInfo LibServer::HttpParesr(const std::string &query)
{
	std::string query_(query, 1);
	int offset = 0;
	StuInfo res;

	do{
		int i = query_.find('&' , offset);
		std::string keyvalue;
		if(i == -1){
			keyvalue = std::string(query_, offset);
			offset = 0;
		}else{
			keyvalue = std::string(query_, offset, i-offset);
			offset = i+1;
		}

		int l = keyvalue.find('=', 0);
		std::string key(keyvalue, 0, l);
		std::string value(keyvalue, l+1);

		if(key == "stuId"){
			res.set_stuid(value);
		}else if(key == "passwd"){
			res.set_passwd(value);
		}else if(key == "seatNo"){
			res.set_seatno(atoi(value.c_str()));
		}else if(key == "roomId"){
			res.set_roomid(atoi(value.c_str()));
		}else if(key == "startTime"){
			res.set_starttime(value);
		}else if(key == "endTime"){
			res.set_endtime(value);
		}else if(key == "date"){
			res.set_date(value);
		}else{
			;
		}
	}while(offset);

	return res;
}

void LibServer::showHttpRequest(const muduo::net::HttpRequest &req)
{
	LOG_INFO << "Headers :" << req.methodString();
	LOG_INFO << "path :" << req.path();
	LOG_INFO << "query :" << req.query();
	
	const std::map<std::string, std::string>& headers = req.headers();
	for (const auto& header : headers)
	{
		LOG_INFO << header.first << ": " << header.second;
	}
}

void LibServer::funcGet(muduo::net::HttpResponse* resp, StuInfo &stu)
{
	std::vector<StuInfo> stus;
	std::string res;

	redis_.setGet(stu.stuid(), stus);
	resp->setStatusCode(muduo::net::HttpResponse::k200Ok);
	resp->setStatusMessage("OK");
	resp->setContentType("text/plain");
	resp->addHeader("Server", "LibServer");
	for(auto i : stus){
		res += "StuID:" + i.stuid() + "\n"
				"PassWord:" + i.passwd() + "\n"
				"SeatNo:" + std::to_string(i.seatno()) + "\n"
				"RoomId:" + std::to_string(i.roomid()) + "\n"
				"StartTime:" + i.starttime() + "\n"
				"EndTime:" + i.endtime() + "\n"
				"Date:" + i.date() + "\n\n";
	}
	resp->setBody(res);
}

void LibServer::funcPost(muduo::net::HttpResponse* resp, StuInfo &stu)
{
	resp->setStatusCode(muduo::net::HttpResponse::k200Ok);
	resp->setStatusMessage("OK");
	resp->setContentType("text/plain");
	resp->addHeader("Server", "LibServer");
	if(redis_.setAdd(stu.stuid(), stu)){
		resp->setBody("add stuinfo success!\n");
	}else{
		resp->setBody("add stuinfo failed!\n");
	}
}

void LibServer::funcError(muduo::net::HttpResponse* resp)
{
	resp->setStatusCode(muduo::net::HttpResponse::k400BadRequest);
	resp->setStatusMessage("Only GET/POST");
	resp->setCloseConnection(true);
}



