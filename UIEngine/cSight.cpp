#include "stdafx.h"
#include "cSight.h"
using namespace MyEngine;

cSight::cSight()
{
}


cSight::~cSight()
{
	for (auto it : m_uiList)
	{
		delete it;
		it = nullptr;
	}
	m_uiList.clear();
}

const RECT MyEngine::cSight::GetRect() const
{
	return RECT();
}

bool MyEngine::cSight::Draw(HDC hDc)
{
	for (auto it : m_uiList)
	{
		it->Draw(hDc);
	}
	return false;
}

void MyEngine::cSight::addChild(cBaseUI * ui)
{
	m_uiList.push_back(ui);
}
