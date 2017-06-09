#include "stdafx.h"
#include "cAmination.h"
using namespace MyEngine;

cAmination::cAmination()
{
}

MyEngine::cAmination::cAmination(const std::initializer_list<LPWSTR>& initlist,int x,int y)
{
	if (initlist.size() == 0)
	{
		return;
	}
	for (auto it : initlist)
	{
		m_Amination.emplace_back((HBITMAP)LoadImage(NULL, it, IMAGE_BITMAP, x, y, LR_LOADFROMFILE));
	}
}


cAmination::~cAmination()
{
}

void MyEngine::cAmination::SetAmination(const std::initializer_list<PWSTR>& initlist,int x,int y)
{
	if (initlist.size() == 0)
	{
		return;
	}
	for (auto it : initlist)
	{
		m_Amination.push_back((HBITMAP)LoadImage(NULL, it, IMAGE_BITMAP, x, y, LR_LOADFROMFILE));
	}
}

const std::vector<HBITMAP>& MyEngine::cAmination::GetAmination() const
{
	return m_Amination;
}

const RECT && MyEngine::cAmination::GetRect() const
{
	RECT rect;
	return std::move(rect);
}

bool MyEngine::cAmination::Draw(HDC hDc)
{
	return false;
}

void MyEngine::cAmination::SetAmiConfig()
{
}
