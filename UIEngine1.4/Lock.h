#pragma once

/*
*class CLock
*������
*/
class CLock
{
public:
	CLock();
	virtual ~CLock();
	/*
	*Lock();
	*����
	*/
	void Lock();

	/*
	*UnLock();
	*����
	*/
	void UnLock();
private:
	CRITICAL_SECTION m_criticalSection;
};