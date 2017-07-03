#pragma once
#include"cEyes.h"
#include<cAmination.h>


class cPlayer :public cEyes
{
public:
	cPlayer();
	
	/*
	有参构造函数，初始化关联动画
	@Param：
		cAmination* correlationAmnation:与人物相关联的动画
	*/
	cPlayer(MyEngine::cAmination* correlationAmnation);

	virtual ~cPlayer();

	/*
	*Move()
	*
	*定义如何移动人物
	*
	*@return int：
	*/
	virtual int move(Dir_Type dir,bool b) override;

	/*
	SetSpeed()
	设置玩家行走速度
	@Param:
		int speed:玩家的速度
	*/
	void SetSpeed(const int& speed);

	/*
	GetSpeed()
	获取玩家速度
	@return:
		玩家速度
	*/
	const int& GetSpeed() const;
	
	/*
	SetcorrelationAmnation(cAmination* ami);
	设置人物动画
	@Param：
		cAmination* ami：人物关联动画
	*/
	void SetcorrelationAmnation(MyEngine::cAmination* ami);

	/*
	GetDir()
	获取方向
	@return Dir_Type：
		人物方向
	*/
	const Dir_Type& GetDir() const override;
private:
	/*
	SetDir(Dir_Type dir)
	设置方向
	@Param：
	Dir_Type dir:方向
	*/
	void SetDir(const Dir_Type& dir);

	int m_speed;

	MyEngine::cAmination* m_correlationAmnation;
};

