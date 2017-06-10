#include "stdafx.h"
#include "cBaseUI.h"
using namespace MyEngine;

cBaseUI::cBaseUI():m_x(0),m_y(0)
{

}

MyEngine::cBaseUI::cBaseUI(const int& x,const int& y):m_x(x),m_y(y)
{
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