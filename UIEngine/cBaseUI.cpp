#include "stdafx.h"
#include "cBaseUI.h"
using namespace MyEngine;

cBaseUI::cBaseUI():m_x(0),m_y(0)
{
	m_type = UI_Base;
}

MyEngine::cBaseUI::cBaseUI(const int& x,const int& y):m_x(x),m_y(y)
{
	m_type = UI_Base;
}


cBaseUI::~cBaseUI()
{
}

void MyEngine::cBaseUI::SetX(const int & x)
{
	m_x = x;
}

const int & MyEngine::cBaseUI::GetX() const
{
	return m_x;
}

void MyEngine::cBaseUI::SetY(const int & y)
{
	m_y = y;
}

const int & MyEngine::cBaseUI::GetY() const
{
	return m_y;
}

const UI_Type & MyEngine::cBaseUI::GetType() const
{
	return m_type;
}

const UINT_PTR & MyEngine::cBaseUI::GetID() const
{
	return m_Uid;
}
