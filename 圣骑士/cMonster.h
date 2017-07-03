#pragma once
#include"cEyes.h"
#include"../UIEngine/cAmination.h"

class cMonster:public cEyes 
{
public:
	cMonster();

	~cMonster();
	
	/*
	SetSpeed(const int& speed);
	设置怪物速度
	@Param：
		int speed:怪物速度
	*/
	void SetSpeed(const int& speed);

	/*
	GetSpeed();
	获取怪物速度
	@return int：
		怪物速度
	*/
	const int& GetSpeed() const;

	/*
	Move(Dir_Type dir,bool b)
	移动怪物
	@Param
		Dir_Type dir：移动方向
		bool b：是否移动
	*/
	virtual int move(Dir_Type dir, bool b)  override;
private:
	int m_speed;
};

