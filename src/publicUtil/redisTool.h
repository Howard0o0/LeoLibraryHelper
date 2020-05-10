#ifndef __REDISTOOL_
#define __REDISTOOL_

/* thread unsafe! */

extern "C" {
#include "hiredis/hiredis.h"
}
#include "string"

class RedisTool {
    public:
	RedisTool(const string& ip, uint16_t port) {
		m_rContext = redisConnect(ip, port);
	}
	~RedisTool() {
	}

    private:
	redisContext* m_rContext = NULL;
	std::string   m_ip;
	uint16_t      m_port;
}

#endif