#include "mainTest.h"
#include "muduo/base/Logging.h"

int main() {

	muduo::Logger::setLogLevel(muduo::Logger::DEBUG);
	// test_json();
	// http_test2();
	// http_test3();
	// test_leoApi();
	// test_student();
	// test_multiThread();
	// test_multiReservate();
	// test_redis();
	// test_protobuf();
	test_protobuf_redis();

	return 0;
}