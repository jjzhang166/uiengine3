#include "stdafx.h"
#include "cSelectRowRank.h"
#include"resource.h"
#include"Tool.h"

cSelectRowRank* g_this;

INT_PTR CALLBACK DiaProc(HWND hWnd,  UINT message, WPARAM wParam,  LPARAM lParam) 
{
	switch (message)
	{
	case WM_INITDIALOG:
		g_this->initDialog(hWnd);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_OK:
		{
			g_this->SetQuitStatus(Quit_OK);
		    unsigned row = SendDlgItemMessage(hWnd, IDC_ROW, CB_GETCURSEL, NULL,NULL);
			unsigned rank= SendDlgItemMessage(hWnd, IDC_RANK, CB_GETCURSEL, NULL, NULL);
			unsigned terrianSpecies = SendDlgItemMessage(hWnd, IDC_TERRIAN, CB_GETCURSEL, NULL, NULL);
			g_this->SetRow(row + 1);
			g_this->SetRank(rank + 1);
			g_this->SetTerrianSpecies(terrianSpecies + 1);
			EndDialog(hWnd, LOWORD(wParam));
		}
			return (INT_PTR)TRUE;
		case IDC_CANCEL:
			g_this->SetQuitStatus(Quit_Cancel);
			EndDialog(hWnd, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	case WM_CLOSE:
		g_this->SetQuitStatus(Quit_Cancel);
		EndDialog(hWnd, LOWORD(wParam));
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}


cSelectRowRank::cSelectRowRank(const UINT& IDD, HINSTANCE hInst, HWND hPWnd)
{
	m_hInst = hInst;
	m_IDD = IDD;
	m_PhWnd = hPWnd;
	m_quitStatus = Quit_Cancel;
	g_this = this;
}

cSelectRowRank::~cSelectRowRank()
{
}

void cSelectRowRank::SetRow(const unsigned& row)
{
	m_row = row;
}

void cSelectRowRank::SetRank(const unsigned& rank)
{
	m_rank = rank;
}

void cSelectRowRank::SetTerrianSpecies(const unsigned TerrianSpecies)
{
	m_terrianSpecies = TerrianSpecies;
}

const unsigned & cSelectRowRank::GetTerrianSpecies() const
{
	return m_terrianSpecies;
}

const unsigned & cSelectRowRank::GetRow() const
{
	return m_row;
}

const unsigned & cSelectRowRank::GetRank() const
{
	return m_rank;
}

void cSelectRowRank::Show()
{
	DialogBox(m_hInst, MAKEINTRESOURCE(m_IDD), m_PhWnd, DiaProc);
}

bool cSelectRowRank::initDialog(HWND hWnd)
{
	m_hWnd = hWnd;
	if (!m_hWnd)
	{
		return false;
	}
	AddItemToComBox();
	return true;
}

void cSelectRowRank::AddItemToComBox()
{
	for (SIZE_T num=0;num<100;++num)
	{
		WCHAR wNum[5] = { 0 };
		wsprintfW(wNum, L"%d", num+1);
		SendDlgItemMessage(m_hWnd, IDC_ROW, CB_ADDSTRING, 0, (LPARAM)wNum);
		SendDlgItemMessage(m_hWnd, IDC_RANK, CB_ADDSTRING, 0, (LPARAM)wNum);
	}
	for (SIZE_T num = 0; num<20; ++num)
	{
		WCHAR wNum[5] = { 0 };
		wsprintfW(wNum, L"%d", num + 1);
		SendDlgItemMessage(m_hWnd, IDC_TERRIAN, CB_ADDSTRING, 0, (LPARAM)wNum);
	}
}

void cSelectRowRank::SetQuitStatus(const Quit_Status & status)
{
	m_quitStatus = status;
}

const Quit_Status & cSelectRowRank::GetStatus()
{
	return m_quitStatus;
}