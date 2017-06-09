#include "stdafx.h"
#include "cGameEngine.h"
#include"Tool.h"

using namespace MyEngine;

cGameEngine *g_pEngine;

HHOOK g_hMouseHook;
HHOOK g_KeyHook;

/*
*全局鼠标事件hook回调函数
*/
LRESULT CALLBACK HookMouseProc(int code, WPARAM wParam, LPARAM lParam)
{
	if (GetActiveWindow() != g_pEngine->GethWnd())
	{
		return CallNextHookEx(g_hMouseHook, code, wParam, lParam);
	}
	switch (wParam)
	{
	case WM_LBUTTONUP:
		MessageBox(NULL, L"", L"", MB_OK);
		break;
	case WM_LBUTTONDOWN:
		break;
	}
	return CallNextHookEx(g_hMouseHook, code, wParam, lParam);
}

/*
*全局键盘事件hook回调函数
*/
LRESULT CALLBACK KeyHookProc(int code, WPARAM wParam, LPARAM lParam)
{
	if (GetActiveWindow() != g_pEngine->GethWnd())
	{
		return CallNextHookEx(g_KeyHook, code, wParam, lParam);
	}
	KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT*)lParam;
	switch (wParam)
	{
	case WM_KEYUP:
		if (pkbhs->vkCode == UVK_DELETE)
		{
			MessageBox(NULL, L"DELETE", L"", MB_OK);
		}
		break;
	case WM_KEYDOWN:
		break;
	}
	return CallNextHookEx(g_KeyHook, code, wParam, lParam);
}

cGameEngine::cGameEngine(HWND hWnd)
{
	m_hWnd = hWnd;
	if (m_hWnd == nullptr)
	{
		m_wError = L"绑定窗口失败或传入无效窗口句柄";
	}
	g_pEngine = this;
	g_hMouseHook = SetWindowsHookEx(WH_MOUSE_LL,HookMouseProc, nullptr, 0);
	g_KeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyHookProc, nullptr, 0);
	AddTimer(1, 50);
}


cGameEngine::~cGameEngine()
{
	UnhookWindowsHookEx(g_hMouseHook);
	UnhookWindowsHookEx(g_KeyHook);
	for (auto it : m_uiList)
	{
		delete it;
		it = nullptr;
	}
	g_pEngine = nullptr;
}

int cGameEngine::OnTimer(int id, int iParam, string str)
{
	DrawUI();
	return 1;
}

int cGameEngine::CenterWindow()
{
	RECT clientRect;
	GetClientRect(m_hWnd, &clientRect);
	if (!MoveToCenter(m_hWnd,clientRect.right - clientRect.left, clientRect.bottom - clientRect.top, TRUE))
	{
		m_wError = L"居中窗口失败";
		return -1;
	}
	return 0;
}

const LPWSTR & cGameEngine::GetLastError() const
{
	return m_wError;
}

cText * MyEngine::cGameEngine::CreateText(const LPWSTR & text, const int & x, const int & y)
{
	cText* pText = new cText(text);
	if (pText == nullptr)
	{
		return nullptr;
	}
	pText->SetX(x);
	pText->SetY(y);
	m_uiList.push_back(pText);
	return pText;
}

cLine * MyEngine::cGameEngine::CreateLine(const POINT & start, const POINT & end)
{
	cLine *pLine = new cLine;
	if (pLine == nullptr)
	{
		return nullptr;
	}
	pLine->SetStartPoint(start);
	pLine->SetEndPoint(end);
	m_uiList.push_back(pLine);
	return pLine;
}

cButton * MyEngine::cGameEngine::CreateButton(const LPWSTR & Name, const int & x, const int & y)
{
	cButton *pButton = new cButton;
	if (pButton == nullptr)
	{
		return nullptr;
	}
	pButton->SetName(Name);
	pButton->SetX(x);
	pButton->SetY(y);
	m_uiList.push_back(pButton);
	return pButton;
}

cCircle * MyEngine::cGameEngine::CreateCircle(const RECT & rect)
{
	cCircle *pCirecle = new cCircle(rect);
	m_uiList.push_back(pCirecle);
	return pCirecle;
}

cPicture * MyEngine::cGameEngine::CreatePicture(const LPWSTR & name, const int & x, const int & y)
{
	cPicture *pPic = new cPicture(name);
	pPic->SetX(x);
	pPic->SetY(y);
	m_uiList.push_back(pPic);
	return pPic;
}

cPicture * MyEngine::cGameEngine::CreatePicture(const HBITMAP & bitmap, const int & x, const int & y)
{
	cPicture *pPic = new cPicture(bitmap);
	pPic->SetX(x);
	pPic->SetY(y);
	m_uiList.push_back(pPic);
	return pPic;
}

cRectangle * MyEngine::cGameEngine::CreateRectangle(const RECT & rect)
{
	cRectangle *pRect = new cRectangle(rect);
	m_uiList.push_back(pRect);
	return pRect;
}

cTriangle * MyEngine::cGameEngine::CreateTriangle(const POINT & p1, const POINT & p2, const POINT & p3)
{
	cTriangle *pTri = new cTriangle(p1, p2, p3);
	m_uiList.push_back(pTri);
	return pTri;
}

cPolygon * MyEngine::cGameEngine::CreatePolygon(std::initializer_list<POINT> pointList)
{
	cPolygon * pPoly = new cPolygon(pointList);
	return pPoly;
}

int MyEngine::cGameEngine::DeleteUI(cBaseUI * pDel)
{
	for (auto it = m_uiList.begin(); it != m_uiList.end(); ++it)
	{
		if (pDel == *it)
		{
			m_uiList.erase(it);
			delete pDel;
			pDel = nullptr;
			return 1;
		}
	}
	return 0;
}

void MyEngine::cGameEngine::DrawUI()
{
	HDC hDc = GetDC(m_hWnd);
	HDC hMemDc = CreateCompatibleDC(hDc);
	RECT rect;
	GetClientRect(m_hWnd, &rect);
	HBITMAP hBitMap = CreateCompatibleBitmap(hDc, rect.right - rect.left, rect.bottom - rect.top);
	SelectObject(hMemDc, hBitMap);
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(hMemDc, &rect, hBrush);

	for (auto it : m_uiList)
	{
		it->Draw(hMemDc);
	}

	BitBlt(hDc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hMemDc, 0, 0, SRCCOPY);
	
	DeleteObject(hBitMap);
	DeleteDC(hMemDc);
	ReleaseDC(m_hWnd, hDc);
}

void MyEngine::cGameEngine::DoMouseMsg()
{
}

void MyEngine::cGameEngine::DoKeyMsg()
{
}

const HWND & MyEngine::cGameEngine::GethWnd() const
{
	return m_hWnd;
}
