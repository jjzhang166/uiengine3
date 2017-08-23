#include "stdafx.h"
#include "cMyTimer.h"
#include "windows.h"
#include "process.h"

cMyTimer::cMyTimer()
{
	m_pThread = nullptr;
}

cMyTimer::~cMyTimer()
{
	m_lock.Lock();
	m_timerList.clear();
	m_lock.UnLock();
	if (m_pThread != nullptr)
	{
		m_pThread->join();
		delete m_pThread;
		m_pThread = nullptr;
	}
}

//��Ӷ�ʱ��
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
	stTimerTemp.timeLastRun = GetTickCount();//��ȡ�ӿ�����ʱ�䣬���뼶
	if (p != NULL)
	{
		stTimerTemp.strParam = p;
	}
	m_lock.Lock();
	m_timerList.push_back(stTimerTemp);
	m_lock.UnLock();
	//m_timerList.push_back(stTimerTemp);
	if (m_timerList.size()== 1)
	{
		//˵����ʱ�ǵ�һ����ʱ��
		if (m_pThread != nullptr)
		{
			m_pThread->join();
			delete m_pThread;
			m_pThread = nullptr;
		}
		m_pThread = new thread{ &cMyTimer::OnThread,this };
	}
}

//ɾ����ʱ��
void cMyTimer::DeleteTimer(unsigned id)
{
	m_lock.Lock();
	for (itTimerLisst it = m_timerList.begin();it != m_timerList.end();++it)
	{
		if (it->id == id)
		{
			it->bDel = true;
			m_lock.UnLock();
			return;
		}
	}
	m_lock.UnLock();
}

void cMyTimer::CheckDelTimer()
{
	m_lock.Lock();
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
	m_lock.UnLock();
}

void cMyTimer::TimerRun()
{
	//�Ƚ϶�ʱ���ϴ����е�ʱ������ڵ�ʱ���Ƿ�����timeElapse
	unsigned timeNow = GetTickCount();
	m_lock.Lock();
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
	m_lock.UnLock();
}

bool cMyTimer::IsQuitThread()
{
	bool bRet = m_timerList.size() == 0 ? true : false;
	return bRet;
}

void cMyTimer::CloseThread()
{
	m_lock.Lock();
	m_timerList.clear();
	m_lock.UnLock();
}

void cMyTimer::OnThread()
{
	while (true)
	{
		if (IsQuitThread()==true)
		{
			break;
		}
		//ɾ����Ҫɾ���Ķ�ʱ��
		CheckDelTimer();

		//����Ƿ��ж�ʱ��Ҫ����
		TimerRun();
	}
}

