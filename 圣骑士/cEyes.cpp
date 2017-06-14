#include "stdafx.h"
#include "cEyes.h"


cEyes::cEyes()
{
	m_fps = 0;
	m_life = 0;
	m_maxFps = 0;
	m_pos = { 0,0 };
	m_type = Type_Eyes;
}


cEyes::~cEyes()
{
}

void cEyes::SetPos(const tagPOINT & pos)
{
	m_pos = pos;
}

void cEyes::SetPos(const tagPOINT && pos)
{
	m_pos = pos;
}

const tagPOINT & cEyes::GetPos() const
{
	return m_pos;
}

void cEyes::SetLife(const int & life)
{
	m_life = life;
}

void cEyes::SetLife(const int && life)
{
	m_life = life;
}

const int & cEyes::GetLife() const
{
	return m_life;
}

void cEyes::SetFps(const unsigned & fps)
{
	m_fps = fps;
}

void cEyes::SetFps(const unsigned && fps)
{
	m_fps = fps;
}

const unsigned & cEyes::GetFps() const
{
	return m_fps;
}

void cEyes::SetMaxFps(const unsigned & fps)
{
	m_maxFps = fps;
}

void cEyes::SetMaxFps(const unsigned && fps)
{
	m_maxFps = fps;
}

const unsigned & cEyes::GetMaxFps() const
{
	return m_maxFps;
}

const Eyes_Type & cEyes::GetType()
{
	return m_type;
}
