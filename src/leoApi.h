#ifndef __LEOAPI_H
#define __LEOAPI_H

#include "curl/curl.h"
#include "httpRequest.h"
#include "libcurl.h"

class LeoApi : public HttpRequest {

    public:
	std::string getToken(const std::string& studentId, const std::string& passwd);
	bool	    reservateSeat(uint64_t seatId, std::string& startTime, std::string& endTime,
				  const std::string& date, std::string& token);
	int	    getSeatId(int roomId, int seatNo, std::string& token);

    private:
	void		  addFixedHeader();
	const std::string m_rootUrl	 = "https://seat.lib.whu.edu.cn:8443";
	const std::string m_loginUrl = "/rest/auth?";
	const std::string m_reservateUrl = "/rest/v2/freeBook";
	const std::string m_layoutUrl	 = "/rest/v2/room/layoutByDate";  // + roomId/date
};

#endif