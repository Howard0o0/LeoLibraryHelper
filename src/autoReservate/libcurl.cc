#include "libcurl.h"
#include "curl/curl.h"
#include "muduo/base/Logging.h"
#include <iostream>
#include <string>

static char   error_buffer[ CURL_ERROR_SIZE ];
static size_t writer(char*, size_t, size_t, std::string*);
static bool   init(CURL*&, const char*, std::string*);
const long    g_timeout = 5;

static bool init(CURL*& conn, const char* url, std::string* p_buffer) {
	CURLcode code;

	// conn = curl_easy_init();
	if (NULL == conn) {
		LOG_ERROR << " Failed to create CURL connection";
		exit(EXIT_FAILURE);
	}

	code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, error_buffer);
	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to set error buffer " << code;
		return false;
	}

	code = curl_easy_setopt(conn, CURLOPT_URL, url);
	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to set URL "
			  << "-->" << error_buffer;
		return false;
	}

	code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1);
	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to set redirect option "
			  << "-->" << error_buffer;
		return false;
	}

	code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to set writer "
			  << "-->" << error_buffer;
		return false;
	}

	code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, p_buffer);
	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to set write data "
			  << "-->" << error_buffer;
		return false;
	}

	curl_easy_setopt(conn, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(conn, CURLOPT_SSL_VERIFYHOST, 0L);

	curl_easy_setopt(conn, CURLOPT_TIMEOUT, g_timeout);
	curl_easy_setopt(conn, CURLOPT_NOSIGNAL, 1L);

	return true;
}

static size_t writer(char* data, size_t size, size_t nmemb, std::string* writer_data) {
	size_t sizes = size * nmemb;

	if (NULL == writer_data) {
		return 0;
	}

	writer_data->append(data, sizes);

	return sizes;
}

// int libcurl_get(const char* url, std::string& buffer, std::string& errinfo) {
long libcurl_get(const char* url, struct curl_slist* header, std::string& buffer) {

	CURL*	 conn = NULL;
	CURLcode code;
	long	 status_code = -1;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	conn = curl_easy_init();
	buffer.clear();
	if (!init(conn, url, &buffer)) {
		LOG_ERROR << " Connection initializion failed";

		return status_code;
	}

	curl_easy_setopt(conn, CURLOPT_HTTPHEADER, header);
	code = curl_easy_perform(conn);

	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to get" << url << "-->" << error_buffer;

		return status_code;
	}

	curl_easy_getinfo(conn, CURLINFO_RESPONSE_CODE, &status_code);
	curl_easy_cleanup(conn);

	return status_code;
}

long libcurl_post(const char* url, struct curl_slist* header, const char* data,
		  std::string& buffer) {
	CURL*	 conn = NULL;
	CURLcode code;
	long	 status_code = -1;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	conn = curl_easy_init();

	buffer.clear();
	if (!init(conn, url, &buffer)) {
		LOG_ERROR << " Connection initializion failed";

		return status_code;
	}

	code = curl_easy_setopt(conn, CURLOPT_POST, true);

	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to set CURLOPT_POST ";
		return status_code;
	}

	code = curl_easy_setopt(conn, CURLOPT_POSTFIELDS, data);
	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to set CURLOPT_POSTFIELDS ";
		return status_code;
	}

	curl_easy_setopt(conn, CURLOPT_HTTPHEADER, header);
	code = curl_easy_perform(conn);

	if (code != CURLE_OK) {
		LOG_ERROR << " Failed to post " << url << "-->" << error_buffer;

		return status_code;
	}

	curl_easy_getinfo(conn, CURLINFO_RESPONSE_CODE, &status_code);
	curl_easy_cleanup(conn);

	return status_code;
}
