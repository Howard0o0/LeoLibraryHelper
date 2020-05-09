#include "leoApi.h"
#include "muduo/base/Logging.h"
#include "rapidjson/document.h"	 // rapidjson's DOM-style API
#include "util.h"
#include <string>
// #include "rapidjson/prettywriter.h"  // for stringify JSON
#include <string>

static bool rsp_success(std::string rsp) {
	rapidjson::Document doc;
	char*		    cstr = const_cast< char* >(rsp.data());
	if (doc.ParseInsitu(cstr).HasParseError()) {
		LOG_WARN << "rsp parse error";
		return false;
	}
	if (doc.HasMember("status")
	    && std::string(doc[ "status" ].GetString()).compare("success") == 0)
		return true;
	else {
		LOG_WARN << "status fail";
		return false;
	}
}

void LeoApi::addFixedHeader() {
	HttpRequest::clearHeader();
	HttpRequest::appendHeader("Content-Tyep:application/"
				  "x-www-form-urlencoded;charset=UTF-8");
	HttpRequest::appendHeader("Host: seat.lib.whu.edu.cn:8443");
	HttpRequest::appendHeader("Connection: Keep-Alive");
}
std::string LeoApi::getToken(const std::string& studentId, const std::string& passwd) {
	std::string token = "";

	addFixedHeader();

	std::string url = m_rootUrl + m_loginUrl + "username=" + studentId + "&password=" + passwd;
	// LOG_DEBUG << "url:" << url;

	long retCode = HttpRequest::get(url.c_str());
	// LOG_DEBUG << "status code :" << retCode;

	std::string rsp = getResponse();
	LOG_DEBUG << studentId << " " << rsp;

	if (retCode != 200 || !rsp_success(rsp))
		return token;

	rapidjson::Document doc;
	char*		    cstr = const_cast< char* >(rsp.data());
	if (doc.ParseInsitu(cstr).HasParseError())
		return token;
	if (doc.HasMember("data") && doc[ "data" ].HasMember("token"))
		token = doc[ "data" ][ "token" ].GetString();

	return token;
}
bool LeoApi::reservateSeat(uint64_t seatId, std::string& startTime, std::string& endTime,
			   const std::string& date, std::string& token) {
	std::string form = "t=1&startTime=" + startTime + "&endTime=" + endTime
			   + "&seat=" + std::to_string(seatId) + "&date=" + date + "&t2=2";

	setForm(form);
	addFixedHeader();
	std::string content = "token:" + token;
	appendHeader(content);
	std::string url		 = m_rootUrl + m_reservateUrl;
	const char* reservateUrl = url.data();
	long	    retCode	 = post(reservateUrl);
	std::string rsp(getResponse());
	LOG_DEBUG << "token: " << token << "--->" << rsp;

	if (retCode != 200 || !rsp_success(rsp))
		return false;

	return true;
}

static int fetchSeatId(std::string& rsp, std::string seatNo) {
	rapidjson::Document doc;
	char*		    cstr = const_cast< char* >(rsp.data());
	if (doc.ParseInsitu(cstr).HasParseError()) {
		LOG_WARN << "rsp parse error";
		return -1;
	}
	if (doc.HasMember("data") && doc[ "data" ].HasMember("layout")) {
		const rapidjson::Value& layout = doc[ "data" ][ "layout" ].GetObject();
		for (rapidjson::Value::ConstMemberIterator itr = layout.MemberBegin();
		     itr != layout.MemberEnd(); ++itr) {
			const rapidjson::Value& tmpObj = itr->value;
			if (strstr(tmpObj.GetObject()[ "type" ].GetString(), "seat") == NULL)
				continue;
			if (tmpObj.GetObject()[ "name" ].GetString() == seatNo)
				return tmpObj[ "id" ].GetInt();
		}
	}
	return -1;
}

int LeoApi::getSeatId(int roomId, int seatNo, std::string& token) {
	std::string url =
		m_rootUrl + m_layoutUrl + "/" + std::to_string(roomId) + "/" + util::getDate();

	addFixedHeader();
	std::string content = "token:" + token;
	appendHeader(content);
	const char* cUrl     = url.data();
	long	    retCode  = get(cUrl);
	std::string response = getResponse();
	LOG_DEBUG << "token:" << token << "--> " << response;
	if (retCode != 200 || !rsp_success(response))
		return -1;

	int seatId = fetchSeatId(response, std::to_string(seatNo));

	return seatId;
}