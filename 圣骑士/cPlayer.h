#pragma once
#include"cEyes.h"
#include<cAmination.h>

class cPlayer :public cEyes
{
public:
	cPlayer();
	virtual ~cPlayer();

	/*
	*Move()
	*
	*定义如何移动人物
	*
	*@return int：
	*/
	virtual int move() override;
private:

};

