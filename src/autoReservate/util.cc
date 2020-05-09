#include "util.h"
std::string util::getDate() {
	char   buf[ 80 ];
	time_t rawtime;
	time(&rawtime);
	strftime(buf, 80, "%Y-%m-%d", localtime(&rawtime));
	return std::string(buf);
}

static void addDay(time_t& time1, int days) {
	time1 += (days - 1) * 60 * 60 * 24 + 28800;
}
std::string util::getTommorrowDate() {
	char   buf[ 80 ];
	time_t rawtime;
	time(&rawtime);
	addDay(rawtime, 1);
	strftime(buf, 80, "%Y-%m-%d", localtime(&rawtime));
	return std::string(buf);
}