#ifndef __STUDENT_H
#define __STUDENT_H

#include "leoApi.h"
#include "muduo/base/StringPiece.h"

class Student {
    public:
	enum date_t { TODAY, TOMMORROW };

	Student(std::string stuId, std::string passwd)
		: m_token(""), m_stuId(stuId), m_passwd(passwd), m_seatId(-1) {
	}
	Student(std::string stuId, std::string passwd, int seatNo, int roomId,
		std::string startTime, std::string endTime, std::string date)
		: m_token(""), m_stuId(stuId), m_passwd(passwd), m_seatNo(seatNo), m_roomId(roomId),
		  m_startTime(startTime), m_endTime(endTime), m_date(date), m_seatId(-1) {
	}

	bool login();
	bool presetSeatId();
	bool reservate();

    private:
	std::string m_token;
	std::string m_stuId;
	std::string m_passwd;
	int	    m_seatNo;
	int	    m_roomId;
	std::string m_startTime;
	std::string m_endTime;
	std::string m_date;
	int	    m_seatId;
	LeoApi	    m_leoApi;
};

#endif