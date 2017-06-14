#include "stdafx.h"
#include "cIDDialogBase.h"
#include"resource.h"

cIDDialogBase::cIDDialogBase()
{
}

cIDDialogBase::cIDDialogBase(const UINT & IDD, HINSTANCE hInst, HWND hPWnd)
{
	m_hInst = hInst;
	m_IDD = IDD;
	m_PhWnd = hPWnd;
}

cIDDialogBase::~cIDDialogBase()
{
}

bool cIDDialogBase::initDialog(HWND hWnd)
{
	m_hWnd = hWnd;
	if (!m_hWnd)
	{
		return false;
	}
	return true;
}