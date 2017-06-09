#include "stdafx.h"
#include "cMyTimer.h"
#include "windows.h"
#include "process.h"

cMyTimer::cMyTimer()
{

}

cMyTimer::~cMyTimer()
{

}

void CheckTimerRun(void* p)
{
	cMyTimer* pTimer = (cMyTimer*)p;
	if (pTimer == NULL)
	{
		_endthread();
		return;
	}
	while(1)
	{
		
		pTimer->CheckAddTimer();
		//删除需要删除的定时器
		pTimer->CheckDelTimer();

		//检测是否有定时器要运行

		if(!pTimer->TimerRun())
		{
			_endthread();
		}

	}
}

//添加定时器
void cMyTimer::AddTimer(unsigned timeId,unsigned timeElapse,int param,char* p)
{
	if (timeElapse == 0)
	{
		return;
	}
	stTimer stTimerTemp;
	stTimerTemp.bDel = false;
	stTimerTemp.id = timeId;
	stTimerTemp.iParam = param;
	stTimerTemp.timeElapse = timeElapse;
	stTimerTemp.timeLastRun = GetTickCount();//获取从开机的时间，毫秒级
	if (p != NULL)
	{
		stTimerTemp.strParam = p;
	}
	m_tempList.push_back(stTimerTemp);
	//m_timerList.push_back(stTimerTemp);
	if (m_tempList.size() == 1)
	{
		//说明此时是第一个定时器
		_beginthread(CheckTimerRun,0,this);
	}
}

//删除定时器
void cMyTimer::DeleteTimer(unsigned id)
{
	for (itTimerLisst it = m_timerList.begin();it != m_timerList.end();++it)
	{
		if (it->id == id)
		{
			it->bDel = true;
			return;
		}
	}
}

void cMyTimer::CheckDelTimer()
{
	for (itTimerLisst it = m_timerList.begin();it != m_timerList.end();)
	{
		if (it->bDel)
		{
			m_timerList.erase(it);
			it = m_timerList.begin();
			continue;
		}
		++it;
	}
}

bool cMyTimer::TimerRun()
{
	if (m_timerList.size() == 0)
	{
		return false;
	}
	//比较定时器上次运行的时间和现在的时间是否经历了timeElapse
	unsigned timeNow = GetTickCount();
	for (itTimerLisst it = m_timerList.begin();it != m_timerList.end();++it)
	{
		if (timeNow - it->timeLastRun >= it->timeElapse)
		{
			it->timeLastRun = timeNow;
			int newTimeElapse = OnTimer(it->id,it->iParam,it->strParam);
			
			if(newTimeElapse==0)
			{
				it->bDel = true;
			}
		}
	}
	return true;
}

void cMyTimer::CheckAddTimer()
{
	if (m_tempList.size() == 0)
	{
		return;
	}

	for (itTimerLisst it = m_tempList.begin();it != m_tempList.end();++it)
	{
		m_timerList.push_back(*it);
	}
	m_tempList.clear();
}