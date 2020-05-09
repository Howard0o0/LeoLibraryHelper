#include "mainTest.h"
#include "boost/bind.hpp"
#include "curl/curl.h"
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
// StuPool g_stuPool;
void taskReservate() {
	//    Student* stu = NULL;
	//    while ((stu = g_stuPool.getStudent()) != NULL) {
	// 	   LOG_INFO << stu->getStuId() << ":" << stu->reservate();
	//    }
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

	// howard.login();
	// LOG_INFO << "howard seat Id:" << howard.presetSeatId();
	// zsq.login();
	// LOG_INFO << "zsq get seatId: " << zsq.presetSeatId();
	// LOG_INFO << "lz login:" << lz.login();
	// LOG_INFO << "lz seat Id:" << lz.presetSeatId();

	// LOG_INFO << howard.reservate();
	// LOG_INFO << zsq.reservate();

	// g_stuPool.addStudent(howard);
	// g_stuPool.addStudent(zsq);
	// g_stuPool.addStudent(lz);
	// muduo::ThreadPool pool("reservate pool");
	// pool.start(5);
	// pool.run(boost::bind(taskReservate));
	// pool.run(boost::bind(taskReservate));
}

// void test_json() {
// 	rapidjson::StringBuffer			     s;
// 	rapidjson::Writer< rapidjson::StringBuffer > json(s);
// 	json.StartObject();
// 	json.Key("start");
// 	json.Int64(18);
// 	json.EndObject();

// 	std::cout << s.GetString() << std::endl;
// }
// void test_http() {

// 	std::string	   resp	  = "";
// 	struct curl_slist* header = NULL;
// 	header			  = curl_slist_append(
// 		   header, "Content-Tyep:"
// 			   "application/x-www-form-urlencoded;charset=UTF-8");
// 	header = curl_slist_append(header, "Host': 'seat.lib.whu.edu.cn:8443");
// 	header = curl_slist_append(header, "Connection': 'Connection");
// 	header = curl_slist_append(
// 		header, "User-Agent: Mozilla/5.0 (Linux; Android 7.0; HUAWEI "
// 			"NXT-TL00 Build/HUAWEINXT-TL00) AppleWebKit/534.30 "
// 			"(KHTML, like Gecko) Version/4.0 Mobile Safari/534.30");

// 	libcurl_get("https://seat.lib.whu.edu.cn:8443/rest/"
// 		    "auth?username=2019282110139&password=17871X",
// 		    header, resp);

// 	LOG_INFO << resp;
// }

// void http_test2() {
// 	HttpRequest request;
// 	request.append_header(
// 		"Content-Tyep:application/x-www-form-urlencoded;charset=UTF-8");
// 	request.append_header("Host: seat.lib.whu.edu.cn:8443");

// 	request.append_header("Connection: Connection");
// 	request.append_header(
// 		"User-Agent: Mozilla/5.0 (Linux; Android 7.0; HUAWEI "
// 		"NXT-TL00 Build/HUAWEINXT-TL00) AppleWebKit/534.30 "
// 		"(KHTML, like Gecko) Version/4.0 Mobile Safari/534.30");
// 	request.get("https://seat.lib.whu.edu.cn:8443/rest/"
// 		    "auth?username=2019282110139&password=17871X");
// 	LOG_INFO << request.get_response();
// }
// void http_test3() {
// 	HttpRequest request;
// 	request.append_header("token:ID5RBVN5I305030542");
// 	request.append_header(
// 		"Content-Type: application/x-www-form-urlencoded; "
// 		"charset=UTF-8");
// 	request.append_header("Host: seat.lib.whu.edu.cn:8443");
// 	request.append_header("Connection: Keep-Alive");

// 	int	    startTime = 10 * 60;
// 	int	    endTime   = 12 * 60;
// 	std::string body      = "t=1";
// 	body += "&startTime=";
// 	body += std::to_string(startTime);
// 	body += "&endTime=";
// 	body += std::to_string(endTime);
// 	body += "&seat=55271";
// 	body += "&date=2020-05-03&t2=2";

// 	request.set_form(body);

// 	request.post("https://seat.lib.whu.edu.cn/rest/v2/freeBook/");

// 	LOG_INFO << request.getResponse();
// }
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
struct people {
	std::string m_name;
	int	    m_age;
};
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

	struct people p1 = { .m_name = "howard", .m_age = 22 };
	struct people p2 = { .m_name = "zsq", .m_age = 20 };

	struct redisReply* reply = NULL;
	reply			 = ( redisReply* )redisCommand(c, "AUTH %s", "howard5279");
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