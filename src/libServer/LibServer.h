#ifndef _LIB_SERVER_
#define _LIB_SERVER_

#include "muduo/net/http/HttpServer.h"
#include "muduo/net/http/HttpRequest.h"
#include "muduo/net/http/HttpResponse.h"
#include "muduo/net/EventLoop.h"

#include "redisTool.h"
#include "stuInfo.pb.h"

struct ServerInfo{
    std::string servername_;
    muduo::net::InetAddress serveraddr_;
};

struct RedisInfo{
    std::string redisIp_;
    uint16_t redisPort_;
    std::string redisPwd_;
};

const static ServerInfo srvInfo_ = {"LibServer", muduo::net::InetAddress(8000)};
const static RedisInfo rdsInfo_ = {"127.0.0.1", 6379, ""};

class LibServer : muduo::noncopyable
{
public:
    LibServer(ServerInfo srvInfo = srvInfo_, RedisInfo rdsInfo = rdsInfo_);
    void startWithThreads(int threadnum);

private:
    void onRequest(const muduo::net::HttpRequest& req,
                    muduo::net::HttpResponse* resp);
    StuInfo HttpParesr(const std::string &query);
    
    muduo::net::EventLoop loop_;
    muduo::net::HttpServer server_;
    RedisTool redis_;
};





#endif 
