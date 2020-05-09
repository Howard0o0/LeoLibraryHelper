#include "stuPool.h"
#include "muduo/base/Logging.h"

void StuPool::loginAndPresetSeatId() {
	resetPoolIdx();
	for (int i = 0; i < m_parallelJobNum; i++)
		m_threadPool.run(std::bind(&StuPool::jobLoginAndPresetSeatId, this));
}

void StuPool::reservate() {
	while (!readyToReservate())
		;
	resetPoolIdx();
	for (int i = 0; i < m_parallelJobNum; i++)
		m_threadPool.run(std::bind(&StuPool::jobReservate, this));
}
void StuPool::jobLoginAndPresetSeatId() {
	Student* stu = NULL;
	bool	 loginRes, presetSeatIdRes;
	while ((stu = getStudent()) != NULL) {
		loginRes	= stu->login();
		presetSeatIdRes = stu->presetSeatId();
		LOG_INFO << stu->getStuId() << ":"
			 << "login(" << loginRes << ") presetSeatId(" << presetSeatIdRes << ")";
		increaseLoginCnt();
	}
}
void StuPool::jobReservate() {
	Student* stu = NULL;
	bool	 res;
	while ((stu = getStudent()) != NULL) {
		res = stu->reservate();
		LOG_INFO << stu->getStuId() << ": reservate(" << res << ")";
	}
}