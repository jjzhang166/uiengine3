#include "stdafx.h"
#include "cCircle.h"

using namespace MyEngine;

cCircle::cCircle()
{
	m_type = UI_Circle;
	m_width = 0;
	m_height = 0;
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_LineColor = RGB(0, 0, 0);
	m_lineWidth = 3;
	m_lineStyle = PS_SOLID;
	m_hPen = CreatePen(m_lineStyle, m_lineWidth, m_LineColor);
	m_hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
}

MyEngine::cCircle::cCircle(const int & startx, const int & starty, const int & endx, const int & endy)
{
	m_type = UI_Circle;
	SetX(startx);
	SetY(starty);
	m_width = abs(endx - startx);
	m_height = abs(endy - starty);
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_LineColor = RGB(0, 0, 0);
	m_lineWidth = 3;
	m_lineStyle = PS_SOLID;
	m_hPen = CreatePen(m_lineStyle, m_lineWidth, m_LineColor);
	m_hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
}


MyEngine::cCircle::cCircle(const RECT & rect)
{
	m_type = UI_Circle;
	SetX(rect.left);
	SetY(rect.top);
	m_width =abs(rect.right - rect.left);
	m_height =abs(rect.bottom - rect.top);
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_LineColor = RGB(0, 0, 255);
	m_lineWidth = 3;
	m_lineStyle = PS_SOLID;
	m_hPen = CreatePen(m_lineStyle, m_lineWidth, m_LineColor);
	m_hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
}

cCircle::~cCircle()
{
	m_hPen ? DeleteObject(m_hPen) : 1;
	m_hBrush ? DeleteObject(m_hBrush) : 1;
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

const int & MyEngine::cCircle::GetHeight() const
{
	return m_width;
}

const int & MyEngine::cCircle::GetWidth() const
{
	return m_width;
}

void MyEngine::cCircle::SetLineColor(const UINT & rgb)
{
	m_LineColor = rgb;
	DeleteObject(m_hPen);
	m_hPen = CreatePen(m_lineStyle, m_lineWidth, m_LineColor);
}

const UINT & MyEngine::cCircle::GetLineColor() const
{
	return m_LineColor;
}

void MyEngine::cCircle::SetIsFill(const bool & ok)
{
	m_isFill = ok;
	if (!m_isFill)
	{
		DeleteObject(m_hBrush);
		m_hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
}

const bool & MyEngine::cCircle::GetIsFill() const
{
	return m_isFill;
}

void MyEngine::cCircle::SetFillColor(const UINT & rgb)
{
	m_fillColor = rgb;
	if (m_isFill)
	{
		DeleteObject(m_hBrush);
		m_hBrush = CreateSolidBrush(m_fillColor);
	}
}

const UINT & MyEngine::cCircle::GetFillColor() const
{
	return m_fillColor;
}

void MyEngine::cCircle::SetLineStyle(const UINT & style)
{
	m_lineStyle = style;
	DeleteObject(m_hPen);
	m_hPen = CreatePen(m_lineStyle, m_lineWidth, m_LineColor);
}

const UINT & MyEngine::cCircle::GetLineStyle(const UINT & style)
{
	return m_lineStyle;
}

const RECT MyEngine::cCircle::GetRect() const
{
	RECT rect;
	rect.left = GetX();
	rect.right = GetX() + m_width;
	rect.top = GetY();
	rect.bottom = GetY() + m_height;
	return rect;
}

bool MyEngine::cCircle::Draw(HDC hDc)
{
	bool bRet = true;
	HPEN hPen=(HPEN)SelectObject(hDc, m_hPen);
	HBRUSH hBrush=(HBRUSH)SelectObject(hDc, m_hBrush);
	if (!Ellipse(hDc,GetX(),GetY(),GetX()+m_width,GetY()+m_height))
	{
		bRet = false;
	}
	SelectObject(hDc, hPen);
	SelectObject(hDc, hBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	return bRet;
}