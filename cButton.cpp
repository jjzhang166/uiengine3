#include "stdafx.h"
#include "cButton.h"
#include"Tool.h"
using namespace MyEngine;

cButton::cButton()
{
	m_BountColor = RGB(0, 255, 0);
	m_firstColor = RGB(153,217,234);
	m_font = L"楷体";
	m_fontColor = RGB(63, 72, 204);
	m_height = 30;
	m_Name = L"Button";
	m_nBount = 3;
	m_secondColor= RGB(255, 255, 255);
	m_width = 100;
}

MyEngine::cButton::cButton(const LPWSTR & Name, const int & width, const int & height)
{
	m_BountColor = RGB(0, 255, 0);
	m_firstColor = RGB(153, 217, 234);
	m_font = L"楷体";
	m_fontColor = RGB(63, 72, 204);
	m_height = height;
	m_Name = Name;
	m_nBount = 3;
	m_secondColor = RGB(255, 255, 255);
	m_width = width;
}

cButton::~cButton()
{
}

void MyEngine::cButton::SetName(const LPWSTR & Name)
{
	m_Name = Name;
}

const LPWSTR & MyEngine::cButton::GetName() const
{
	return m_Name;
}

void MyEngine::cButton::SetWidth(const int & width)
{
	m_width = width;
}

const int & MyEngine::cButton::GetWidth() const
{
	return m_width;
}

void MyEngine::cButton::SetHeight(const int & Height)
{
	m_height = Height;
}

const int & MyEngine::cButton::GetHeight() const
{
	return m_height;
}

void MyEngine::cButton::SetnBount(const int & n)
{
	m_nBount = n;
}

const int & MyEngine::cButton::GetBount() const
{
	return m_nBount;
}

void MyEngine::cButton::SetBountColor(const UINT & rgb)
{
	m_BountColor = rgb;
}

const UINT & MyEngine::cButton::GetBountColor() const
{
	return m_BountColor;
}

void MyEngine::cButton::SetfirstColor(const UINT & rgb)
{
	m_firstColor = rgb;
}

const UINT & MyEngine::cButton::GetfirstColor() const
{
	return m_BountColor;
}

void MyEngine::cButton::SetsecondColor(const UINT & rgb)
{
	m_secondColor = rgb;
}

const UINT & MyEngine::cButton::GetsecondColor() const
{
	return m_secondColor;
}

const RECT && MyEngine::cButton::GetRect() const
{
	RECT rect;
	rect.left = GetX();
	rect.right = GetX() + m_width;
	rect.top = GetY();
	rect.bottom = GetY() + m_height;
	return std::move(rect);
}

bool MyEngine::cButton::Draw(HDC hDc)
{
	if (hDc == NULL)
	{
		return false;
	}
	unsigned wordLen = lstrlenW(m_Name);  //字符个输
	unsigned wordHei = m_height - 8;   //文字高度
	unsigned wordWid = wordHei/2;  //文字宽度
	int num = WcharArrayChineseNums(m_Name);
	HFONT hFont = CreateFont(wordHei, wordWid, NULL, NULL, 400, FALSE,
		FALSE, FALSE, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, m_font);
	hFont=(HFONT)SelectObject(hDc, hFont);
	HPEN hPen = CreatePen(PS_SOLID, m_nBount, m_BountColor);
	hPen=(HPEN)SelectObject(hDc, hPen);
	HBRUSH hBrush = CreateSolidBrush(m_firstColor);
	hBrush=(HBRUSH)SelectObject(hDc, hBrush);
	RECT rect = GetRect();
	Rectangle(hDc, rect.left, rect.top, rect.right, rect.bottom);
	SetBkMode(hDc, NULL);
	SetTextColor(hDc, m_fontColor);
	TextOut(hDc, rect.left+(m_width-wordWid*(wordLen+2))/2, rect.top + 4, m_Name, wordLen);
	SelectObject(hDc, hPen);
	SelectObject(hDc, hBrush);
	SelectObject(hDc, hFont);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	DeleteObject(hFont);
	return true;
}

void MyEngine::cButton::SetFont(const LPWSTR & font)
{
	m_font = font;
}

const LPWSTR & MyEngine::cButton::GetFont() const
{
	return m_font;
}

void MyEngine::cButton::SetFontColor(const UINT & rgb)
{
	m_fontColor = rgb;
}

const UINT & MyEngine::cButton::GetFontColor() const
{
	return m_fontColor;
}
