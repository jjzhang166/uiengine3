#include "stdafx.h"
#include "cAmination.h"
using namespace MyEngine;

cAmination::cAmination()
{
	m_type = UI_Amination;
	m_amiConfig = BITMAP();
	m_Amination.clear();
	m_isLucency = FALSE;
	m_lucencyRgb = RGB(0, 0, 0);
	m_maxFrame = 0;
	m_curFrame = 0;
	m_isAutoRun = TRUE;
}

MyEngine::cAmination::cAmination(const std::initializer_list<LPWSTR>& initlist,const int& w,const int& h)
{
	m_type = UI_Amination;
	m_isLucency = FALSE;
	m_lucencyRgb = RGB(0, 0, 0);
	for (auto it : initlist)
	{
		m_Amination.emplace_back((HBITMAP)LoadImage(NULL, it, IMAGE_BITMAP, w, h, LR_LOADFROMFILE));
	}
	m_maxFrame = m_Amination.size();
	m_curFrame = 0;
	InitAmiConfig();
	m_isAutoRun = TRUE;
}


cAmination::~cAmination()
{
	DeleteAmination();
}

void MyEngine::cAmination::SetAmination(const std::initializer_list<PWSTR>& initlist,const int& w,const int& h)
{
	if (initlist.size() == 0)
	{
		return;
	}
	DeleteAmination();
	for (auto it : initlist)
	{
		m_Amination.push_back((HBITMAP)LoadImage(NULL, it, IMAGE_BITMAP, w, h, LR_LOADFROMFILE));
	}
	InitAmiConfig();
}

const std::vector<HBITMAP>& MyEngine::cAmination::GetAmination() const
{
	return m_Amination;
}

const RECT MyEngine::cAmination::GetRect() const
{
	RECT rect;
	rect.left = GetX();
	rect.right = GetX() + m_amiConfig.bmWidth;
	rect.top = GetY();
	rect.bottom = GetY() + m_amiConfig.bmHeight;
	return rect;
}

bool MyEngine::cAmination::Draw(HDC hDc)
{
	if (hDc == NULL)
	{
		return false;
	}
	HDC hMemDc = CreateCompatibleDC(hDc);
	SelectObject(hMemDc, m_Amination[m_curFrame]);
	if (m_isLucency)
	{
		TransparentBlt(hDc, GetX(), GetY(), m_amiConfig.bmWidth, m_amiConfig.bmHeight, hMemDc, 0, 0, m_amiConfig.bmWidth, m_amiConfig.bmHeight, m_lucencyRgb);
	}
	else
	{
		BitBlt(hDc, GetX(), GetY(), m_amiConfig.bmWidth, m_amiConfig.bmHeight, hMemDc, 0, 0, SRCCOPY);
	}
	if (m_isAutoRun)
	{
		IncFrame();
	}
	DeleteDC(hMemDc);
	return true;
}

void MyEngine::cAmination::SetIsLucnecy(const BOOL & b)
{
	m_isLucency = b;
}

const BOOL & MyEngine::cAmination::GetIsLucency() const
{
	return m_isLucency;
}

void MyEngine::cAmination::SetLucnecyColor(const UINT & rgb)
{
	m_lucencyRgb = rgb;
}

const UINT & MyEngine::cAmination::GetLucnecyColor() const
{
	return m_lucencyRgb;
}

const BITMAP & MyEngine::cAmination::GetConfig() const
{
	return m_amiConfig;
}

void MyEngine::cAmination::IncFrame()
{
	if (!m_maxFrame)
	{
		return;
	}
	m_curFrame = (m_curFrame + 1) % m_maxFrame;
}

void MyEngine::cAmination::SetAutoRun(const BOOL & b)
{
	m_isAutoRun = b;
}

const BOOL & MyEngine::cAmination::IsAutoRun() const
{
	return m_isAutoRun;
}

void MyEngine::cAmination::InitAmiConfig()
{
	GetObject(m_Amination[0], sizeof(BITMAP), &m_amiConfig);
}

void MyEngine::cAmination::DeleteAmination()
{
	for (auto it : m_Amination)
	{
		DeleteObject(it);
	}
	m_Amination.clear();
}
