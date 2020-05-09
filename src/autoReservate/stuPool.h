#ifndef __STUPOOL_H
#define __STUPOOL_H

#include "muduo/base/Mutex.h"
#include "student.h"
#include <muduo/base/ThreadPool.h>
#include <mutex>
#include <vector>

class StuPool {
    public:
	StuPool() : m_poolIdx(-1), m_loginCnt(0) {
		m_threadPool.start(m_threadNum);
	}
	void addStu(const Student& stu) {
		m_stuPool.push_back(stu);
	}
	void loginAndPresetSeatId();

	void reservate();

    private:
	static const int       m_parallelJobNum = 4;
	static const int       m_threadNum	= 4;
	std::vector< Student > m_stuPool;
	std::mutex	       m_lockPoolIdx;
	int		       m_poolIdx;
	muduo::ThreadPool      m_threadPool;
	uint32_t	       m_loginCnt;
	std::mutex	       m_lockLoginCnt;

	bool readyToReservate() {
		return m_loginCnt == m_stuPool.size();
	}
	void increaseLoginCnt() {
		std::lock_guard< std::mutex > lock(m_lockLoginCnt);
		++m_loginCnt;
	}

	void resetPoolIdx() {
		std::lock_guard< std::mutex > lock(m_lockPoolIdx);
		m_poolIdx = -1;
	}
	Student* getStudent() {
		std::lock_guard< std::mutex > lock(m_lockPoolIdx);
		if (++m_poolIdx >= static_cast< int >(m_stuPool.size()))
			return NULL;
		return &(m_stuPool[ m_poolIdx ]);
	}
	void jobLoginAndPresetSeatId();
	void jobReservate();
};

#endif