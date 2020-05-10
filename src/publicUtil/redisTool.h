#ifndef __REDISTOOL_
#define __REDISTOOL_

/* thread unsafe! */

extern "C" {
#include "hiredis/hiredis.h"
}
#include "string"
#include "stuInfo.pb.h"
#include <vector>

class RedisTool {
    public:
	RedisTool(const std::string& ip, uint16_t port, const std::string passwd)
		: m_ip(ip), m_port(port), m_passwd(passwd) {
	}
	~RedisTool() {
	}
	bool connect();
	void disconnect();
	bool setAdd(std::string key, const StuInfo& stuInfo);
	bool setGet(std::string key, std::vector< StuInfo >& stuInfoUnion);

    private:
	redisContext* m_rContext = NULL;
	std::string   m_ip;
	uint16_t      m_port;
	std::string   m_passwd;
	// struct redisReply* m_reply = NULL;
	char* m_serializedStr;
};

class AutoCharStr {
    public:
	AutoCharStr(int len) : m_len(len) {
		m_cstr = ( char* )malloc(len + 1);
	}
	~AutoCharStr() {
		if (m_cstr)
			free(m_cstr);
	}
	char* cstr() {
		return m_cstr;
	}
	int len() {
		return m_len;
	}

    private:
	char* m_cstr = NULL;
	int   m_len;
};

class RedisRpl {
    public:
	RedisRpl(redisReply* reply) {
		m_reply = reply;
	}
	~RedisRpl() {
		if (m_reply) {
			freeReplyObject(m_reply);
			m_reply = NULL;
		}
	}

	redisReply* getReply() {
		return m_reply;
	}

    private:
	redisReply* m_reply = NULL;
};

#endif