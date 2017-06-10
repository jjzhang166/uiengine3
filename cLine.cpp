#include "stdafx.h"
#include "cLine.h"
using namespace MyEngine;

cLine::cLine()
{
	m_startPoint.x = 0;
	m_startPoint.y = 0;
	m_endSPoint.x = 0;
	m_endSPoint.y = 0;
	m_width = 3;
	m_color = RGB(255, 255, 0);
	m_style = PS_SOLID;
}

cLine::cLine(const POINT & start, const POINT & end):m_startPoint(start),m_endSPoint(end),m_width(3),m_color(RGB(255,255,0))
{
	m_style = PS_SOLID;
}

cLine::cLine(const int & startx, const int & starty, const int & endx, const int & endy)
{
	m_startPoint.x = startx;
	m_startPoint.y = starty;
	m_endSPoint.x = endx;
	m_endSPoint.y = endy;
	m_width = 1;
	m_color = RGB(0, 0, 0);
	m_style = PS_SOLID;
}

cLine::~cLine()
{
}

void cLine::SetStartPoint(const POINT & start)
{
	m_startPoint = start;
}

void cLine::SetEndPoint(const POINT & end)
{
	m_endSPoint = end;
}

const POINT & cLine::GetStartPoint() const
{
	return m_startPoint;
}

const POINT & cLine::GetEndPoint() const
{
	return m_endSPoint;
}

void cLine::SetStartPoint(const int & x, const int & y)
{
	m_startPoint.x = x;
	m_startPoint.y = y;
}

void cLine::SetEndPoint(const int & x, const int & y)
{
	m_endSPoint.x = x;
	m_endSPoint.y = y;
}

void cLine::SetWidth(const int & w)
{
	m_width = w;
}

const int & cLine::GetWidth() const
{
	return m_width;
}

void cLine::SetColor(const UINT & rgb)
{
	m_color = rgb;
}

const UINT & cLine::GetColor() const
{
	return m_color;
}

void MyEngine::cLine::SetStyle(const UINT & style)
{
	m_style = style;
}

const UINT & MyEngine::cLine::GetStyle() const
{
	return m_style;
}

bool MyEngine::cLine::Draw(HDC hDc)
{
	HPEN hPen = CreatePen(m_style, m_width, m_color);
	SelectObject(hDc, hPen);
	if (!MoveToEx(hDc, m_startPoint.x, m_startPoint.y, nullptr))
	{
		DeleteObject(hPen);
		return false;
	}
	if (!LineTo(hDc, m_endSPoint.x, m_endSPoint.y))
	{
		DeleteObject(hPen);
		return false;
	}
	DeleteObject(hPen);
	return true;
}

const RECT MyEngine::cLine::GetRect() const
{
	RECT rect;
	rect.left = m_startPoint.x;
	rect.top = m_startPoint.y;
	rect.right = m_endSPoint.x;
	rect.bottom = m_endSPoint.y;
	return rect;
}