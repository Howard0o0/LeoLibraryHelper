#include "mainTest.h"
#include "muduo/base/Logging.h"

#include "LibServer.h"

using namespace std;
using namespace muduo;
using namespace muduo::net;

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
	// test_protobuf_redis();
	// test_redisTool();
	// test_timer();
	// test_timerReservate();

	LibServer server;
	server.startWithThreads(4);


	return 0;
}