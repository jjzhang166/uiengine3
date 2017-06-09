#include "stdafx.h"
#include "cCircle.h"

using namespace MyEngine;

cCircle::cCircle()
{
	m_width = 0;
	m_height = 0;
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_LineColor = RGB(0, 0, 0);
	m_width = 1;
	m_lineStyle = PS_SOLID;
}

MyEngine::cCircle::cCircle(const int & startx, const int & starty, const int & endx, const int & endy)
{
	SetX(startx);
	SetY(starty);
	m_width = abs(endx - startx);
	m_height = abs(endy - starty);
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_LineColor = RGB(0, 0, 0);
	m_width = 1;
	m_lineStyle = PS_SOLID;
}


MyEngine::cCircle::cCircle(const RECT & rect)
{
	SetX(rect.left);
	SetY(rect.top);
	m_width =abs(rect.right - rect.left);
	m_height =abs(rect.bottom - rect.top);
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_LineColor = RGB(0, 0, 0);
	m_width = 1;
	m_lineStyle = PS_SOLID;
}

cCircle::~cCircle()
{
}

void MyEngine::cCircle::SetCircleArea(const RECT & rect)
{
	SetX(rect.left);
	SetY(rect.top);
	m_width = abs(rect.right - rect.left);
	m_height = abs(rect.bottom - rect.top);
}

void MyEngine::cCircle::SetCircleArea(const int & startx, const int & starty, const int & endx, const int & endy)
{
	SetX(startx);
	SetY(starty);
	m_width = abs(endx - startx);
	m_height = abs(endy - starty);
}

void MyEngine::cCircle::SetHeight(const int & height)
{
	m_height = height;
}

const int & MyEngine::cCircle::GetHeight() const
{
	return m_width;
}

void MyEngine::cCircle::SetWidth(const int & w)
{
	m_width = w;
}

const int & MyEngine::cCircle::GetWidth() const
{
	return m_width;
}

void MyEngine::cCircle::SetLineColor(const UINT & rgb)
{
	m_LineColor = rgb;
}

const UINT & MyEngine::cCircle::GetLineColor() const
{
	return m_LineColor;
}

void MyEngine::cCircle::SetIsFill(bool && ok)
{
	m_isFill = ok;
}

void MyEngine::cCircle::SetIsFill(const bool & ok)
{
	m_isFill = ok;
}

const bool & MyEngine::cCircle::GetIsFill() const
{
	return m_isFill;
}

void MyEngine::cCircle::SetFillColor(const UINT & rgb)
{
	m_fillColor = rgb;
}

const UINT & MyEngine::cCircle::GetFillColor() const
{
	return m_fillColor;
}

void MyEngine::cCircle::SetLineStyle(const UINT & style)
{
	m_lineStyle = style;
}

const UINT & MyEngine::cCircle::GetLineStyle(const UINT & style)
{
	return m_lineStyle;
}

const RECT && MyEngine::cCircle::GetRect() const
{
	RECT rect;
	rect.left = GetX();
	rect.right = GetX() + m_width;
	rect.top = GetY();
	rect.bottom = GetY() + m_height;
	return std::move(rect);
}

bool MyEngine::cCircle::Draw(HDC hDc)
{
	HBRUSH hBrush;
	HPEN hPen = CreatePen(m_lineStyle,m_width,m_LineColor);
	SelectObject(hDc, hPen);
	if (m_isFill)
	{
		hBrush = CreateSolidBrush(m_fillColor);
		SelectObject(hDc, hBrush);
	}
	if (!Ellipse(hDc,GetX(),GetY(),GetX()+m_width,GetY()+m_height))
	{
		DeleteObject(hPen);
		DeleteObject(hBrush);
		return false;
	}
	DeleteObject(hPen);
	DeleteObject(hBrush);
	return true;
}
