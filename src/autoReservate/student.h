#ifndef __STUDENT_H
#define __STUDENT_H

#include "leoApi.h"
#include "muduo/base/StringPiece.h"

class Student {
    public:
	enum date_t { TODAY, TOMMORROW };
	Student() = default;
	Student(std::string stuId, std::string passwd)
		: m_token(""), m_stuId(stuId), m_passwd(passwd), m_seatId(-1) {
	}
	Student(std::string stuId, std::string passwd, int seatNo, int roomId,
		std::string startTime, std::string endTime, std::string date)
		: m_token(""), m_stuId(stuId), m_passwd(passwd), m_seatNo(seatNo), m_roomId(roomId),
		  m_startTime(startTime), m_endTime(endTime), m_date(date), m_seatId(-1) {
	}
	Student(const Student& stu)
		: m_token(stu.m_token), m_stuId(stu.m_stuId), m_passwd(stu.m_passwd),
		  m_seatNo(stu.m_seatNo), m_roomId(stu.m_roomId), m_startTime(stu.m_startTime),
		  m_endTime(stu.m_endTime), m_date(stu.m_date), m_seatId(stu.m_seatId),
		  m_leoApi(stu.m_leoApi) {
	}

	bool	    login();
	bool	    presetSeatId();
	bool	    reservate();
	std::string getToken() {
		return m_token;
	}
	std::string getStuId() {
		return m_stuId;
	}

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