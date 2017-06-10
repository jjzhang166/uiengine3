#include "stdafx.h"
#include "cPolygon.h"

using namespace MyEngine;

cPolygon::cPolygon()
{
	m_pointList.clear();
	m_lineColor = RGB(0, 255, 255);
	m_sideNums = 0;
	m_width = 4;
	m_fillColor = RGB(0, 0, 0);
	m_isFill = FALSE;
}


MyEngine::cPolygon::cPolygon(const std::initializer_list<POINT> pointList)
{
	m_pointList.resize(pointList.size());
	m_pointList.assign(pointList);
	m_lineColor = RGB(0, 255, 255);
	m_sideNums = m_pointList.size();
	m_width = 4;
	m_fillColor = RGB(0, 0, 0);
	m_isFill = FALSE;
}

cPolygon::~cPolygon()
{
}

const RECT MyEngine::cPolygon::GetRect() const
{
	RECT rect;
	return rect;
}

void MyEngine::cPolygon::SetPolygon(const std::initializer_list<POINT>& pointList)
{
	m_pointList.resize(pointList.size());
	m_pointList.assign(pointList);
	m_sideNums = m_pointList.size();
}

void MyEngine::cPolygon::AlterOnePoint(const POINT & oldPoint, const POINT & newPoint)
{
	for (auto it = std::begin(m_pointList); it != std::end(m_pointList); ++it)
	{
		if (it->x == oldPoint.x&&it->y == oldPoint.y)
		{
			*it = newPoint;
		}
	}
}

bool MyEngine::cPolygon::Draw(HDC hDc)
{
	if (hDc == NULL)
	{
		return false;
	}
	bool bRet = true;
	POINT *apt = new POINT[m_sideNums];
	HPEN hPen = CreatePen(PS_SOLID, m_width, m_lineColor);
	hPen = (HPEN)SelectObject(hDc, hPen);
	HBRUSH hBrush = NULL;
	if (m_isFill)
	{
		hBrush = CreateSolidBrush(m_fillColor);
	}
	else
	{
		hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	}
	hBrush = (HBRUSH)SelectObject(hDc, hBrush);
	for (size_t i = 0; i < m_sideNums ; ++i)
	{
		apt[i] = m_pointList[i];
	}
	SetPolyFillMode(hDc,WINDING);
	if (!Polygon(hDc, apt, m_sideNums))
	{
		bRet = false;
	}
	SelectObject(hDc, hPen);
	SelectObject(hDc, hBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	delete[] apt;
	apt = nullptr;
	return bRet;
}

void MyEngine::cPolygon::SetWidth(const unsigned & width)
{
	m_width = width;
}

const unsigned & MyEngine::cPolygon::GetWidth() const
{
	return m_width;
}

void MyEngine::cPolygon::SetLineColor(const UINT & rgb)
{
	m_lineColor = rgb;
}

const UINT & MyEngine::cPolygon::GetLineColor() const
{
	return m_lineColor;
}

void MyEngine::cPolygon::SetFill(const BOOL & b)
{
	m_isFill = b;
}

const BOOL & MyEngine::cPolygon::IsFill() const
{
	return m_isFill;
}

void MyEngine::cPolygon::SetFillColor(const UINT & rgb)
{
	m_fillColor = rgb;
}

const UINT & MyEngine::cPolygon::GetFillColor() const
{
	return m_fillColor;
}