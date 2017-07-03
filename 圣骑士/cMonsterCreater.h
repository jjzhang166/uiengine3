#pragma once
#include"cMonster.h"
#include"cMonsterAma.h"
#include"cMonsterBull.h"
#include"cMonsterQiu.h"
#include"cMonsterStar.h"
#include<cAmination.h>

static class cMonsterCreater
{
public:
	cMonsterCreater();
	~cMonsterCreater();

	/*
	CreateMonsterStar(tagPOINT pt,MyEngine::cAmination corretionAmination);
	创造怪物星星
	@Param：
		tagPOINT pt：怪物位置
		cAmination corretionAmination：与怪物关联的动图
	@return cMonster*：
		创造的怪物对象指针
	*/
	cMonster* CreateMonsterStar(const tagPOINT& pt,MyEngine::cAmination* corretionAmination);

	/*
	CreateMonsterBull(tagPOINT pt, MyEngine::cAmination corretionAmination);
	创建怪物公牛
	@Param：
		tagPOINT pt：怪物位置
		cAmination corretionAmination：与怪物关联的动图
	@return cMonster*：
		创造的怪物对象指针
	*/
	cMonster* CreateMonsterBull(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);

	/*
	CreateMonsterQiu(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);
	创造怪物球球
	@Param：
		tagPOINT pt：怪物位置
		cAmination corretionAmination：与怪物关联的动图
	@return cMonster*：
		创造的怪物对象指针
	*/
	cMonster* CreateMonsterQiu(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);

	/*
	CreateMonsterAma(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);
	创造怪物奇葩
	@Param：
		tagPOINT pt：怪物位置
		cAmination corretionAmination：与怪物关联的动图
	@return cMonster*：
		创造的怪物对象指针
	*/
	cMonster* CreateMonsterAma(const tagPOINT& pt, MyEngine::cAmination* corretionAmination);
};

