#include "redisTool.h"
#include "muduo/base/Logging.h"
bool RedisTool::connect() {
	m_rContext = redisConnect(m_ip.c_str(), m_port);
	if (m_rContext == NULL || m_rContext->err) {
		if (m_rContext) {
			LOG_ERROR << "redis connect error:" << m_rContext->errstr;
			disconnect();
		}
		else {
			LOG_ERROR << "Can't allocate redis context";
		}
		return false;
	}
	LOG_DEBUG << "redis connected";

	bool		   res	 = false;
	struct redisReply* reply = NULL;
	reply = ( redisReply* )redisCommand(m_rContext, "AUTH %s", m_passwd.c_str());
	if (reply->type == REDIS_REPLY_STATUS && strstr(reply->str, "OK") != NULL)
		res = true;
	freeReplyObject(reply);
	return res;
}

void RedisTool::disconnect() {
	if (m_rContext) {
		redisFree(m_rContext);
		m_rContext = NULL;
	}
}
bool RedisTool::setAdd(std::string key, const StuInfo& stuInfo) {
	StuInfo	    sinfo(stuInfo);
	AutoCharStr serializedStr(sinfo.ByteSizeLong());
	sinfo.SerializeToArray(serializedStr.cstr(), sinfo.ByteSizeLong());

	RedisRpl rdsRpl(( redisReply* )redisCommand(m_rContext, "SADD %s %b", key.c_str(),
						    serializedStr.cstr(), serializedStr.len()));
	if (rdsRpl.getReply()->type == REDIS_REPLY_INTEGER && rdsRpl.getReply()->integer == 1)
		return true;
	else
		return false;
}
bool RedisTool::setGet(std::string key, std::vector< StuInfo >& stuInfoUnion) {

	RedisRpl rdsRpl(( redisReply* )redisCommand(m_rContext, "SMEMBERS %s", key.c_str()));
	if (rdsRpl.getReply()->type != REDIS_REPLY_ARRAY || rdsRpl.getReply()->elements <= 0) {
		LOG_ERROR << rdsRpl.getReply()->str;
		return false;
	}
	for (uint32_t i = 0; i < rdsRpl.getReply()->elements; i++) {
		RedisRpl tmpReply(rdsRpl.getReply()->element[ i ]);
		StuInfo	 tmpStuInfo;
		if (!tmpStuInfo.ParseFromArray(tmpReply.getReply()->str,
					       tmpReply.getReply()->len)) {
			LOG_ERROR << "parse error";
			return false;
		}
		stuInfoUnion.push_back(tmpStuInfo);
	}
	return true;
}
