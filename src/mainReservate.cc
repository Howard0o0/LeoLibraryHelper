#include "curl/curl.h"
#include "httpRequest.h"
#include "leoApi.h"
#include "libcurl.h"
#include "muduo/base/Logging.h"
#include "rapidjson/document.h"	 // rapidjson's DOM-style API
#include "rapidjson/stringbuffer.h"
#include "student.h"
#include "util.h"
#include <iostream>
#include <string>
/*
	    'Content-Tyep': 'application/x-www-form-urlencoded;charset=UTF-8',
	    'Host': 'seat.lib.whu.edu.cn:8443',
	    'Connection': 'Connection',
	    'User-Agent': 'Mozilla/5.0 (Linux; Android 7.0; HUAWEI NXT-TL00
   Build/HUAWEINXT-TL00) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0
   Mobile Safari/534.30'
*/
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
	LOG_INFO << zsq.reservate();
}
int main() {
	muduo::Logger::setLogLevel(muduo::Logger::DEBUG);
	// test_json();
	// http_test2();
	// http_test3();
	// test_leoApi();
	test_student();

	return 0;
}