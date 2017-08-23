#pragma once
#include <string>
#include <list>
#include<thread>
#include"Lock.h"
using namespace std;

struct stTimer
{
	unsigned id;//id��
	unsigned timeElapse;	//��ʱ�����еļ��ʱ��
	unsigned timeLastRun;	//��ʱ���ϴ����е�ʱ��
	int iParam;				//Ԥ������
	string strParam;		//Ԥ������
	bool bDel;				//�Ƿ�Ҫ��ɾ��
	stTimer()
	{
		timeElapse = 0;
		timeLastRun = 0;
		id = 0;
		iParam = 0;
		bDel = false;
	}
};

typedef list<stTimer> TimerList;
typedef list<stTimer>::iterator itTimerLisst;

class cMyTimer
{
public:
	cMyTimer();
	virtual ~cMyTimer();
	//��Ӷ�ʱ��
	void AddTimer(unsigned timeId,unsigned timeElapse,int param = 0,char* p = NULL);

	//ɾ����ʱ��
	void DeleteTimer(unsigned id);

	//��ʱ���߼�����
	//���ص�ֵ���Ǹö�ʱ���µļ��ʱ��
	virtual int OnTimer(int id,int iParam,string str) = 0;

	//����Ƿ��ж�ʱ����Ҫɾ��
	void CheckDelTimer();

	//��Ⲣ���ж�ʱ��
	void TimerRun();

	bool IsQuitThread();
protected:
	void CloseThread();
	void OnThread();

	TimerList m_timerList;	//�������ж�ʱ��

	bool m_isClose;

	thread* m_pThread;

	CLock m_lock;
};