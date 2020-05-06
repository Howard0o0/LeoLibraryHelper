#include "student.h"
#include "muduo/base/Logging.h"
#include "rapidjson/document.h"	 // rapidjson's DOM-style API
#include "util.h"

bool Student::login() {
	std::string token;
	int	    errCnt = 0;
	do {
		token = m_leoApi.getToken(m_stuId, m_passwd);
		if (token.size() > 0)
			break;
		LOG_DEBUG << "login failed";
	} while (errCnt++ < 3);

	if (token.size() <= 0)
		return false;

	m_token = token;
	return true;
}
bool Student::presetSeatId() {
	int errCnt = 0;
	int seatId = -1;

	if (m_token.size() <= 0)
		return false;
	do {

		seatId = m_leoApi.getSeatId(m_roomId, m_seatNo, m_token);
		if (seatId != -1)
			break;

	} while (errCnt++ < 3);

	if (m_seatId == -1)
		return false;
	m_seatId = seatId;
	return true;
}
bool Student::reservate() {
	bool res    = false;
	int  errCnt = 0;

	if (m_seatId == -1 || m_token.size() <= 0)
		return false;

	do {
		res = m_leoApi.reservateSeat(m_seatId, m_startTime, m_endTime, m_date, m_token);
		if (res)
			break;
	} while (errCnt++ < 3);

	if (!res)
		return false;

	return true;
}