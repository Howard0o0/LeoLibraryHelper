#include "mainTest.h"
#include "boost/bind.hpp"
#include "curl/curl.h"
#include "redisTool.h"
#include "stuInfo.pb.h"
#include "timer.h"
#include <functional>
extern "C" {
#include "hiredis/hiredis.h"
}
#include "httpRequest.h"
#include "leoApi.h"
#include "libcurl.h"
#include "muduo/base/Logging.h"
#include "muduo/base/Mutex.h"
#include "rapidjson/document.h"	 // rapidjson's DOM-style API
#include "rapidjson/stringbuffer.h"
#include "stuPool.h"
#include "student.h"
#include "util.h"
#include <iostream>
#include <muduo/base/ThreadPool.h>
#include <queue>
#include <string>
muduo::MutexLock   g_mutex;
std::vector< int > nums;
void		   print() {
	      muduo::MutexLockGuard lock(g_mutex);
	      std::cout << nums.back() << std::endl;
	      nums.pop_back();
}

void print2() {
	std::cout << "print2" << std::endl;
}
void test_multiThread() {
	muduo::ThreadPool pool("test pool");
	pool.start(5);
	nums.push_back(1);
	nums.push_back(2);
	pool.run(boost::bind(print));
	pool.run(boost::bind(print));
	pool.stop();
	pool.run(std::bind(print2));
}
void test_multiReservate() {

	Student howard("2019282110139", "17871X", 16, 101, "1320", "1350", "2020-05-07");
	Student zsq("2016301110055", "173722", 10, 101, "1320", "1350", "2020-05-07");
	Student lz("2019202140084", "070043", 11, 101, "1320", "1350", "2020-05-07");

	StuPool stuPool;
	stuPool.addStu(howard);
	stuPool.addStu(zsq);
	stuPool.addStu(lz);
	stuPool.loginAndPresetSeatId();
	stuPool.reservate();
}

void test_leoApi() {
	LeoApi	    la;
	std::string token = la.getToken("2019282110139", "17871X");
	LOG_INFO << token;
	std::string stime = "1320";
	std::string etime = "1380";
	LOG_INFO << "seat id:" << la.getSeatId(101, 12, token);
	la.reservateSeat(60208, stime, etime, "2020-05-06", token);
}
void test_student() {
	Student howard("2019282110139", "17871X", 16, 101, "1260", "1320", "2020-05-06");
	howard.login();
	howard.presetSeatId();
	LOG_INFO << howard.reservate();

	Student zsq("2016301110055", "173722", 10, 101, "1260", "1320", "2020-05-06");
	zsq.login();
	zsq.presetSeatId();
}
void test_redis() {

	redisContext* c = redisConnect("127.0.0.1", 9900);
	if (c == NULL || c->err) {
		if (c) {
			printf("Error: %s\n", c->errstr);
			// handle error
		}
		else {
			printf("Can't allocate redis context\n");
		}
	}
	LOG_INFO << "redis connected";

	struct redisReply* reply = NULL;
	reply			 = ( redisReply* )redisCommand(c, "AUTH %s", "howard5279");
	if (reply->type == REDIS_REPLY_STATUS && strstr(reply->str, "OK") != NULL)
		LOG_INFO << "status:" << reply->str;
	freeReplyObject(reply);
	// reply = ( struct redisReply* )redisCommand(c, "SADD peoples %s",
	// 					   reinterpret_cast< std::string >(p1));
	// ;
	// LOG_INFO << "reply type:" << reply->type;
	// if (reply->type == 6)
	// 	LOG_ERROR << "redisCommand error : " << reply->str;
	// for (int i = 0; i < reply->elements; i++)
	// 	LOG_INFO << reply->element[ i ]->str;
}
void test_redisTool() {
	RedisTool rt("127.0.0.1", 9900, "howard5279");
	LOG_INFO << "connect:" << rt.connect();

	StuInfo s1;
	s1.set_stuid("2019282110139");
	s1.set_passwd("17871X");
	s1.set_roomid(101);
	s1.set_seatno(6);
	s1.set_starttime("540");
	s1.set_endtime("600");
	s1.set_date("2020-05-10");
	StuInfo s2;
	s2.set_stuid("2016301110055");
	s2.set_passwd("173722");
	s2.set_roomid(101);
	s2.set_seatno(8);
	s2.set_starttime("540");
	s2.set_endtime("600");
	s2.set_date("2020-05-10");

	LOG_INFO << rt.setAdd("tommorrow", s1);
	LOG_INFO << rt.setAdd("tommorrow", s2);
	std::vector< StuInfo > stuInfoUnion;
	bool		       res = rt.setGet("tommorrow", stuInfoUnion);
	if (!res)
		return;
	for (auto it = stuInfoUnion.begin(); it != stuInfoUnion.end(); it++)
		LOG_INFO << (*it).stuid() << "," << (*it).passwd();
}

void test_protobuf() {
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	StuInfo s1;
	s1.set_stuid("2016301110055");
	s1.set_passwd("173722");
	s1.set_roomid(101);
	s1.set_seatno(8);
	s1.set_starttime("540");
	s1.set_endtime("600");
	s1.set_date("2020-05-10");

	char serializedStr[ 512 ];
	s1.SerializeToArray(serializedStr, s1.ByteSizeLong());

	StuInfo s2;
	s2.ParseFromArray(serializedStr, s1.ByteSizeLong());
	LOG_INFO << s2.stuid();
}

void test_protobuf_redis() {
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	StuInfo s1;
	s1.set_stuid("2019282110139");
	s1.set_passwd("17871X");
	s1.set_roomid(101);
	s1.set_seatno(14);
	s1.set_starttime("1260");
	s1.set_endtime("1320");
	s1.set_date("2020-05-11");

	StuInfo s2;
	s2.set_stuid("2016301110055");
	s2.set_passwd("173722");
	s2.set_roomid(101);
	s2.set_seatno(12);
	s2.set_starttime("1260");
	s2.set_endtime("1320");
	s2.set_date("2020-05-11");

	char serializedStr[ 512 ];
	s1.SerializeToArray(serializedStr, s1.ByteSizeLong());

	redisContext* c = redisConnect("127.0.0.1", 9900);
	if (c == NULL || c->err) {
		if (c) {
			printf("Error: %s\n", c->errstr);
			// handle error
		}
		else {
			printf("Can't allocate redis context\n");
		}
	}
	LOG_INFO << "redis connected";

	struct redisReply* reply = NULL;
	reply			 = ( redisReply* )redisCommand(c, "AUTH %s", "howard5279");
	freeReplyObject(reply);

	/* insert */
	reply = ( redisReply* )redisCommand(c, "SADD tommorrow %b", serializedStr,
					    s1.ByteSizeLong());
	LOG_INFO << "reply type:" << reply->type;
	freeReplyObject(reply);
	s2.SerializeToArray(serializedStr, s2.ByteSizeLong());
	reply = ( redisReply* )redisCommand(c, "SADD tommorrow %b", serializedStr,
					    s2.ByteSizeLong());
	LOG_INFO << "reply type:" << reply->type;
	freeReplyObject(reply);

	/* read */
	reply		   = ( redisReply* )redisCommand(c, "SMEMBERS tommorrow");
	uint32_t reply_len = reply->elements;
	for (uint32_t i = 0; i < reply_len; i++) {
		struct redisReply* tmp_reply = reply->element[ i ];
		StuInfo		   tmpStuInfo;
		if (!tmpStuInfo.ParseFromArray(tmp_reply->str, tmp_reply->len))
			LOG_ERROR << "parse error";
		LOG_INFO << tmpStuInfo.stuid() << "," << tmpStuInfo.passwd();
		freeReplyObject(tmp_reply);
	}
}

void test_timer() {
	Timer timer;
	timer.SyncWait(5000, print2);
}

void test_timerReservate() {

	RedisTool rt("127.0.0.1", 9900, "howard5279");
	LOG_INFO << "connect:" << rt.connect();

	std::vector< StuInfo > stuInfoUnion;
	bool		       res = rt.setGet("tommorrow", stuInfoUnion);
	if (!res)
		return;
	LOG_INFO << "got set";

	StuPool stuPool;
	for (auto it = stuInfoUnion.begin(); it != stuInfoUnion.end(); it++) {
		stuPool.addStu(Student((*it).stuid(), (*it).passwd(), (*it).seatno(),
				       (*it).roomid(), (*it).starttime(), (*it).endtime(),
				       (*it).date()));
	}
	stuPool.loginAndPresetSeatId();

	LOG_INFO << "login and preset seatId done";
	Timer t;
	t.SyncWait(5000, std::bind(&StuPool::reservate, &stuPool));
}