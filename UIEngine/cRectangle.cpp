#include "stdafx.h"
#include "cRectangle.h"
using namespace MyEngine;

cRectangle::cRectangle()
{
	m_type = UI_Rectangle;
	m_rect.left = 0;
	m_rect.right = 0;
	m_rect.top = 0;
	m_rect.bottom = 0;
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_lineColor = RGB(255, 0, 0);
	m_Linewidth = 3;
	m_lineStyle = PS_SOLID;
}

MyEngine::cRectangle::cRectangle(const RECT & rect)
{
	m_type = UI_Rectangle;
	m_rect = rect;
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_lineColor = RGB(255, 0, 0);
	m_Linewidth = 3;
	m_lineStyle = PS_SOLID;
	m_hPen = CreatePen(m_lineStyle, m_Linewidth, m_lineColor);
	m_hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
}


MyEngine::cRectangle::cRectangle(const int & left, const int & right, const int & top, const int & bottom)
{
	m_type = UI_Rectangle;
	m_rect.left = left;
	m_rect.right = right;
	m_rect.top = top;
	m_rect.bottom = bottom;
	m_fillColor = RGB(255, 255, 255);
	m_isFill = false;
	m_lineColor = RGB(255, 0, 0);
	m_Linewidth = 3;
	m_lineStyle = PS_SOLID;
	m_hPen = CreatePen(m_lineStyle, m_Linewidth, m_lineColor);
	m_hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
}

cRectangle::~cRectangle()
{
	m_hPen ? DeleteObject(m_hPen) : 1;
	m_hBrush ? DeleteObject(m_hBrush) : 1;
}

void MyEngine::cRectangle::SetRect(const RECT & rect)
{
	m_rect = rect;
}

void MyEngine::cRectangle::SetRect(const int & left, const int & right, const int & top, const int & bottom)
{
	m_rect.left = left;
	m_rect.right = right;
	m_rect.top = top;
	m_rect.bottom = bottom;
}

const RECT MyEngine::cRectangle::GetRect() const
{
	return m_rect;
}

int MyEngine::cRectangle::GetWidth() const
{
	return m_rect.right - m_rect.left;
}

int MyEngine::cRectangle::GetHeight() const
{
	return m_rect.bottom-m_rect.top;
}

void MyEngine::cRectangle::SetLineColor(const UINT & rgb)
{
	m_lineColor = rgb;
	DeleteObject(m_hPen);
	m_hPen = CreatePen(m_lineStyle, m_Linewidth, m_lineColor);
}

const UINT & MyEngine::cRectangle::GetLineColor() const
{
	return m_lineColor;
}

void MyEngine::cRectangle::SetIsFill(const bool & ok)
{
	m_isFill = ok;
	if (!m_isFill)
	{
		DeleteObject(m_hBrush);
		m_hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
}

const bool & MyEngine::cRectangle::isFIll() const
{
	return m_isFill;
}

void MyEngine::cRectangle::SetFillColor(const UINT & rgb)
{
	m_fillColor = rgb;
	DeleteObject(m_hBrush);
	m_hBrush = CreateSolidBrush(m_fillColor);
}

const UINT & MyEngine::cRectangle::GetFillColor() const
{
	return m_fillColor;
}

void MyEngine::cRectangle::SetLineStyle(const UINT & style)
{
	m_lineStyle = style;
	DeleteObject(m_hPen);
	m_hPen = CreatePen(m_lineStyle, m_Linewidth, m_lineColor);
}

const UINT & MyEngine::cRectangle::GetLineStyle() const
{
	return m_lineStyle;
}

bool MyEngine::cRectangle::Draw(HDC hDc)
{
	HPEN hPen=(HPEN)SelectObject(hDc, m_hPen);
	HBRUSH hBrush=(HBRUSH)SelectObject(hDc, m_hBrush);
	Rectangle(hDc, m_rect.left, m_rect.top, m_rect.right, m_rect.bottom);
	SelectObject(hDc, hPen);
	SelectObject(hDc,hBrush);
	return true;
}
