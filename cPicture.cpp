#include "stdafx.h"
#include "cPicture.h"
#include<iostream>
#include<mmsystem.h>
using namespace MyEngine;
#pragma comment(lib,"msimg32.lib")


cPicture::cPicture()
{
}

MyEngine::cPicture::cPicture(const HBITMAP& hBitmap)
{
	m_hBitmap = hBitmap;
	SetPicConfig();
}

MyEngine::cPicture::cPicture(const LPWSTR& name,int x,int y)
{
	m_hBitmap = (HBITMAP)LoadImage(NULL, name, IMAGE_BITMAP, x, y, LR_LOADFROMFILE);
	SetPicConfig();
}


cPicture::~cPicture()
{
}

const RECT && MyEngine::cPicture::GetRect() const
{
	RECT rect;
	rect.left = GetX();
	rect.right = GetX() + m_bmpConfig.bmWidth;
	rect.top = GetY();
	rect.bottom = GetY() + m_bmpConfig.bmHeight;
	return std::move(rect);
}

bool MyEngine::cPicture::Draw(HDC hDc)
{
	if (hDc == nullptr)
	{
		return false;
	}
	HDC hMemDc = CreateCompatibleDC(hDc);
	SelectObject(hMemDc, m_hBitmap);
	if (m_isLucency)
	{
		TransparentBlt(hDc, GetX(), GetY(), m_bmpConfig.bmWidth, m_bmpConfig.bmHeight, hMemDc, 0, 0, m_bmpConfig.bmWidth, m_bmpConfig.bmHeight, m_licencyRgb);
	}
	else
	{
		BitBlt(hDc, GetX(), GetY(), m_bmpConfig.bmWidth, m_bmpConfig.bmHeight, hMemDc, 0, 0, SRCCOPY);
	}
	DeleteDC(hMemDc);
	return true;
}

void MyEngine::cPicture::SetBitmap(const HBITMAP & hBitmap)
{
	m_hBitmap= hBitmap;
	SetPicConfig();
}

void MyEngine::cPicture::SetBitmap(const LPWSTR & name,int  x,int  y)
{
	m_hBitmap = (HBITMAP)LoadImage(NULL, name, IMAGE_BITMAP, x, y, LR_LOADFROMFILE);
	SetPicConfig();
}

const HBITMAP & MyEngine::cPicture::GetBitmap() const
{
	return m_hBitmap;
}

void MyEngine::cPicture::SetPicConfig()
{
	GetObject(m_hBitmap, sizeof(BITMAP), &m_bmpConfig);
}