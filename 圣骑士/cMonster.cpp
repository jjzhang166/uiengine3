#include "stdafx.h"
#include "cMonster.h"


cMonster::cMonster()
{
}

cMonster::~cMonster()
{
}

void cMonster::SetSpeed(const int & speed)
{
	m_speed = speed;
}

const int & cMonster::GetSpeed() const
{
	return m_speed;
}

int cMonster::move(Dir_Type dir, bool b)
{
	m_dir = dir;
	return 0;
}

