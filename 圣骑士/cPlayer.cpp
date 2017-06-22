#include "stdafx.h"
#include "cPlayer.h"

cPlayer::cPlayer()
{
	m_type = Type_Player;
	m_correlationAmnation = NULL;
}

cPlayer::cPlayer(MyEngine::cAmination * correlationAmnation)
{
	m_correlationAmnation = correlationAmnation;
}

cPlayer::~cPlayer()
{
	
}

int cPlayer::move(Dir_Type dir,bool b)
{
	SetDir(dir);
	switch (dir)
	{
	case Dir_Left:
	{
		int curFrame = m_correlationAmnation->GetCurFrame();
		if (curFrame >= 4&&curFrame < 8)
		{
			b == true ? m_pos.x -= m_speed : 1;
			m_correlationAmnation->SetCurFrame(++curFrame < 8 ? curFrame : 4);
			m_correlationAmnation->SetX(m_pos.x);
			m_correlationAmnation->SetY(m_pos.y);
		}
		else
		{
			m_correlationAmnation->SetCurFrame(4);
		}
	}
		break;
	case Dir_Right:
	{
		int curFrame = m_correlationAmnation->GetCurFrame();
		if (curFrame >= 8 && curFrame < 12)
		{
			b == true ? m_pos.x += m_speed : 1;
			m_correlationAmnation->SetCurFrame(++curFrame < 12 ? curFrame : 8);
			m_correlationAmnation->SetX(m_pos.x);
			m_correlationAmnation->SetY(m_pos.y);
		}
		else
		{
			m_correlationAmnation->SetCurFrame(8);
		}
	}
		break;
	case Dir_Up:
	{
		int curFrame = m_correlationAmnation->GetCurFrame();
		if (curFrame >= 12 && curFrame < 16)
		{
			b == true ? m_pos.y -= m_speed : 1;
			m_correlationAmnation->SetCurFrame(++curFrame < 16 ? curFrame : 12);
			m_correlationAmnation->SetX(m_pos.x);
			m_correlationAmnation->SetY(m_pos.y);
		}
		else
		{
			m_correlationAmnation->SetCurFrame(12);
		}
	}
		break;
	case Dir_Down:
	{
		int curFrame = m_correlationAmnation->GetCurFrame();
		if (curFrame >= 0 && curFrame < 4)
		{
			b == true ? m_pos.y += m_speed : 1;
			m_correlationAmnation->SetCurFrame(++curFrame < 4 ? curFrame : 0);
			m_correlationAmnation->SetX(m_pos.x);
			m_correlationAmnation->SetY(m_pos.y);
		}
		else
		{
			m_correlationAmnation->SetCurFrame(0);
		}
	}
		break;
	default:
		break;
	}
	return 0;
}

void cPlayer::SetSpeed(const int & speed)
{
	m_speed = speed;
}

const int & cPlayer::GetSpeed() const
{
	return m_speed;
}

void cPlayer::SetcorrelationAmnation(MyEngine::cAmination * ami)
{
	m_correlationAmnation = ami;
}

const Dir_Type & cPlayer::GetDir() const
{
	return m_dir;
}

void cPlayer::SetDir(const Dir_Type & dir)
{
}

