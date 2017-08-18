#include "stdafx.h"
#include "cGameEngine.h"
#include"Tool.h"

using namespace MyEngine;

UINT_PTR cGameEngine::m_Uid = 0;

cGameEngine *g_pEngine;

HHOOK g_hMouseHook;
HHOOK g_KeyHook;

/*
*全局鼠标事件hook回调函数
*/
LRESULT CALLBACK HookMouseProc(int code, WPARAM wParam, LPARAM lParam)
{
	if (GetActiveWindow() == g_pEngine->GethWnd())
	{
		g_pEngine->DoMouseMsg(wParam);
	}
	return CallNextHookEx(g_hMouseHook, code, wParam, lParam);
}

/*
*全局键盘事件hook回调函数
*/
LRESULT CALLBACK KeyHookProc(int code, WPARAM wParam, LPARAM lParam)
{
	if (GetActiveWindow() ==g_pEngine->GethWnd())
	{
		KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT*)lParam;
		switch (wParam)
		{
		case WM_KEYUP:
			g_pEngine->DoKeyUpMsg(lParam);
			break;
		case WM_KEYDOWN:
			g_pEngine->DoKeyDownMsg(lParam);
			break;
		}
	}
	return CallNextHookEx(g_KeyHook, code, wParam, lParam);
}

MyEngine::cGameEngine::cGameEngine()
{
	m_hWnd = NULL;
	g_hMouseHook = SetWindowsHook/*Ex*/(WH_MOUSE/*_LL*/, HookMouseProc/*, nullptr, 0*/);
	g_KeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyHookProc, nullptr, 0);
	AddTimer(1, 50);
	g_pEngine = this;
}

cGameEngine::cGameEngine(HWND hWnd)
{
	m_hWnd = hWnd;
	if (m_hWnd == nullptr)
	{
		m_wError = L"绑定窗口失败或传入无效窗口句柄";
	}
	g_hMouseHook = SetWindowsHook/*Ex*/(WH_MOUSE/*_LL*/,HookMouseProc/*, nullptr, 0*/);
	g_KeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyHookProc, nullptr, 0);
	AddTimer(1, 50);
	g_pEngine = this;
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
	m_uiList.clear();
	m_evnetList.clear();
	g_pEngine = nullptr;
}

int cGameEngine::OnTimer(int id, int iParam, string str)
{
	switch (id)
	{
	case 1:
		DrawUI();
		CheckButtonGetOrLostFocus();
		break;
	}
	return 1;
}

int cGameEngine::CenterWindow(int w, int h)
{
	if (w == 0 || h == 0)
	{
		RECT clientRect;
		GetClientRect(m_hWnd, &clientRect);
		w = clientRect.right - clientRect.left;
		h = clientRect.bottom - clientRect.top;
	}
	if (!MoveToCenter(m_hWnd,w,h))
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
	pText->m_Uid = m_Uid++;
	pText->SetX(x);
	pText->SetY(y);
	m_uiList.push_back(pText);
	return pText;
}

cLine * MyEngine::cGameEngine::CreateLine(const POINT & start, const POINT & end)
{
	cLine *pLine = new cLine;
	pLine->m_Uid = m_Uid++;
	pLine->SetStartPoint(start);
	pLine->SetEndPoint(end);
	m_uiList.push_back(pLine);
	return pLine;
}

cButton * MyEngine::cGameEngine::CreateButton(const LPWSTR & Name, const int & x, const int & y)
{
	cButton *pButton = new cButton;
	pButton->m_Uid = m_Uid++;
	pButton->SetName(Name);
	pButton->SetX(x);
	pButton->SetY(y);
	m_uiList.push_back(pButton);
	return pButton;
}

cButton * MyEngine::cGameEngine::CreateBitmapButton(const LPWSTR & bmpPath,const int& x, const int& y)
{
	cButton* pButton = new cButton(bmpPath);
	pButton->m_Uid = m_Uid++;
	pButton->SetX(x);
	pButton->SetY(y);
	m_uiList.push_back(pButton);
	return pButton;
}

cButton * MyEngine::cGameEngine::CreateBitmapButton(const HBITMAP & bitmap,const int& x, const int& y)
{
	cButton* pButton = new cButton(bitmap);
	pButton->m_Uid = m_Uid++;
	pButton->SetY(y);
	pButton->SetX(x);
	m_uiList.push_back(pButton);
	return pButton;
}

cCircle * MyEngine::cGameEngine::CreateCircle(const RECT & rect)
{
	cCircle *pCirecle = new cCircle(rect);
	pCirecle->m_Uid = m_Uid++;
	m_uiList.push_back(pCirecle);
	return pCirecle;
}

cPicture * MyEngine::cGameEngine::CreatePicture(const HBITMAP & bitmap, const int & x, const int & y)
{
	cPicture *pPic = new cPicture(bitmap);
	pPic->m_Uid = m_Uid++;
	pPic->SetX(x);
	pPic->SetY(y);
	m_uiList.push_back(pPic);
	return pPic;
}

cPicture * MyEngine::cGameEngine::CreatePicture(const LPWSTR & Name, const int & x, const int & y, const int & w, const int & h)
{
	cPicture *pPic = new cPicture(Name, w, h);
	pPic->m_Uid = m_Uid++;
	pPic->SetX(x);
	pPic->SetY(y);
	m_uiList.push_back(pPic);
	return pPic;
}

cRectangle * MyEngine::cGameEngine::CreateRectangle(const RECT & rect)
{
	cRectangle *pRect = new cRectangle(rect);
	pRect->m_Uid = m_Uid++;
	m_uiList.push_back(pRect);
	return pRect;
}

cTriangle * MyEngine::cGameEngine::CreateTriangle(const POINT & p1, const POINT & p2, const POINT & p3)
{
	cTriangle *pTri = new cTriangle(p1, p2, p3);
	pTri->m_Uid = m_Uid++;
	m_uiList.push_back(pTri);
	return pTri;
}

cPolygon * MyEngine::cGameEngine::CreatePolygon(std::initializer_list<POINT> pointList)
{
	cPolygon * pPoly = new cPolygon(pointList);
	pPoly->m_Uid = m_Uid++;
	m_uiList.push_back(pPoly);
	return pPoly;
}

cAmination * MyEngine::cGameEngine::CreateAmination(const std::initializer_list<LPWSTR>& pathList, const int & x, const int & y, const int& w, const int& h)
{
	cAmination* pAmi = new cAmination(pathList, w, h);
	pAmi->m_Uid = m_Uid++;
	pAmi->SetX(x);
	pAmi->SetY(y);
	m_uiList.push_back(pAmi);
	return pAmi;
}

cAmination * MyEngine::cGameEngine::CreateAmination(const LPWSTR & Name, const int & smallRow, const int & smallRank, const int & w, const int h)
{
	cAmination* pAmi = new cAmination(Name, smallRow, smallRank, w, h);
	pAmi->m_Uid = m_Uid++;
	m_uiList.push_back(pAmi);
	return pAmi;
}

cAmination * MyEngine::cGameEngine::CreateAmination(const HBITMAP & hbitmap, const int & smallrow, const int & smallrank)
{
	cAmination* pAmi = new cAmination(hbitmap, smallrow, smallrank);
	pAmi->m_Uid = m_Uid++;
	m_uiList.push_back(pAmi);
	return pAmi;
}

cSight * MyEngine::cGameEngine::CreateSight()
{
	cSight* pSight = new cSight;
	pSight->m_Uid = m_Uid++;
	m_uiList.push_back(pSight);
	return pSight;
}

void MyEngine::cGameEngine::AddEventToUi(cBaseUI * ui, UINT_PTR eventId, CallEeventBack callBack,void* Param)
{
	UI_Event uiEvent;
	uiEvent.EventId = eventId;
	uiEvent.controller = ui;
	uiEvent.CallProc = callBack;
	uiEvent.Param = Param;
	m_evnetList.push_back(uiEvent);
}

int MyEngine::cGameEngine::DeleteUI(cBaseUI * pDel)
{
	m_lock.Lock();
	for (auto it = m_uiList.begin(); it != m_uiList.end(); ++it)
	{
		if (pDel == *it)
		{
			DeleteEvent(pDel);
			m_uiList.erase(it);
			delete pDel;
			pDel = nullptr;
			m_lock.UnLock();
			return 1;
		}
	}
	m_lock.UnLock();
	return 0;
}

int MyEngine::cGameEngine::DeleteUIs(std::list<cBaseUI*> pDelList)
{
	int iCount = 0;
	for (auto it:pDelList)
	{
		iCount += DeleteUI(it);
	}
	return iCount;
}

int MyEngine::cGameEngine::QuickDeleteUIs(std::list<cBaseUI*> pDelList)
{
	if (pDelList.size() == 0)
	{
		return 0;
	}
	auto pDelCur = pDelList.begin();
	int iCount = 0;
	m_lock.Lock();
	for (auto it = m_uiList.begin(); it != m_uiList.end();)
	{
		if (*it == *pDelCur)
		{
			DeleteEvent(*pDelCur);
			it = m_uiList.erase(it);
			delete *pDelCur;
			*pDelCur = nullptr;
			++pDelCur;
			++iCount;
		}
		else
		{
			++it;
		}
	}
	m_lock.UnLock();
	return iCount;
}

BOOL MyEngine::cGameEngine::DeleteEvent(cBaseUI * ui, UINT_PTR eventId)
{
	for (auto it = m_evnetList.begin(); it != m_evnetList.end(); ++it)
	{
		if (it->controller == ui&&it->EventId == eventId)
		{
			m_evnetList.erase(it);
			return TRUE;
		}
	}
	return FALSE;
}

int MyEngine::cGameEngine::DeleteEvent(cBaseUI * ui)
{
	for (auto it = m_evnetList.begin(); it != m_evnetList.end();)
	{
		if (it->controller == ui)
		{
			it=m_evnetList.erase(it);
		}
		else
		{
			++it;
		}
	}
	return 0;
}

void MyEngine::cGameEngine::DrawUI()
{
	if (!m_hWnd)
	{
		return;
	}
	HDC hDc = GetDC(m_hWnd);
	HDC hMemDc = CreateCompatibleDC(hDc);
	RECT rect;
	GetClientRect(m_hWnd, &rect);
	HBITMAP hBitMap = CreateCompatibleBitmap(hDc, rect.right - rect.left, rect.bottom - rect.top);
	SelectObject(hMemDc, hBitMap);
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(hMemDc, &rect, hBrush);
	m_lock.Lock();
	for (auto it : m_uiList)
	{
		if (it!=nullptr)
		{
			it->Draw(hMemDc);
		}
	}
	m_lock.UnLock();

	BitBlt(hDc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hMemDc, 0, 0, SRCCOPY);
	
	DeleteObject(hBrush);
	DeleteObject(hBitMap);
	DeleteDC(hMemDc);
	ReleaseDC(m_hWnd, hDc);
}

void MyEngine::cGameEngine::DoMouseMsg(WPARAM wParam)
{
	switch (wParam)
	{
	case WM_LBUTTONUP:
		CheckButtonClick(Mouse_Up);
		break;
	case WM_LBUTTONDOWN:
		CheckButtonClick(Mouse_Down);
		break;
	}
	DoUiMouseEvent(wParam);
}

void MyEngine::cGameEngine::DoKeyDownMsg(LPARAM lParam)
{
	KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT*)lParam;
	DoUiKeyEvent(pkbhs->vkCode);
}

void MyEngine::cGameEngine::DoKeyUpMsg(LPARAM lParam)
{
	KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT*)lParam;
	DoUiKeyEvent(pkbhs->vkCode);
}

void MyEngine::cGameEngine::CheckButtonGetOrLostFocus()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(m_hWnd, &pt);
	m_lock.Lock();
	for (auto it =m_uiList.rbegin();it!=m_uiList.rend();++it)
	{
		if ((*it)->GetType() == UI_Button)
		{
			RECT rect=dynamic_cast<cButton*>(*it)->GetRect();
			if (pt.x >rect.left&&pt.x<rect.right&&pt.y>rect.top&&pt.y <rect.bottom)
			{
				dynamic_cast<cButton*>(*it)->ChangeColor(Get_Focus);
				m_lock.UnLock();
				return;
			}
			else
			{
				dynamic_cast<cButton*>(*it)->ChangeColor(Lost_Focus);
			}
		}
	}
	m_lock.UnLock();
}

void MyEngine::cGameEngine::CheckButtonClick(const Btn_Status & clicked)
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(m_hWnd, &pt);
	m_lock.Lock();
	for (auto it=m_uiList.rbegin();it!=m_uiList.rend();++it)
	{
		if ((*it)->GetType() == UI_Button)
		{
			RECT rect = dynamic_cast<cButton*>(*it)->GetRect();
			if (pt.x >rect.left&&pt.x<rect.right&&pt.y>rect.top&&pt.y <rect.bottom)
			{
				dynamic_cast<cButton*>(*it)->ChangeBountColor(clicked);
				m_lock.UnLock();
				return;
			}
		}
	}
	m_lock.UnLock();
}

void MyEngine::cGameEngine::DoUiKeyEvent(const UINT_PTR & eventId)
{
	for (auto it : m_evnetList)
	{
		if (it.EventId == eventId)
		{
			it.CallProc(it.controller);
		}
	}
}

void MyEngine::cGameEngine::DoUiMouseEvent(const UINT_PTR & eventId)
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(m_hWnd, &pt);
	for (auto it=m_uiList.rbegin();it!=m_uiList.rend();++it)
	{
		RECT rect = (*it)->GetRect();
		if (pt.x > rect.left&&pt.x<rect.right&&pt.y>rect.top&&pt.y < rect.bottom)
		{
			DealMouseMsg(*it, eventId);
			return;
		}
	}
}

HWND MyEngine::cGameEngine::GethWnd() const
{
	return m_hWnd;
}

void MyEngine::cGameEngine::SethWnd(HWND hWnd)
{
	m_hWnd = hWnd;
}

LONG MyEngine::cGameEngine::GetWndStyle()
{
	return GetWindowLong(m_hWnd, GWL_STYLE);
}

BOOL MyEngine::cGameEngine::ChangeWndStyle(const LONG & style)
{
	return SetWindowLong(m_hWnd, GWL_STYLE, style);
}

BOOL MyEngine::cGameEngine::DealMouseMsg(const cBaseUI * ui, const UINT_PTR & eventId)
{
	for (auto it : m_evnetList)
	{
		if (it.controller == ui&&it.EventId == eventId)
		{
			it.CallProc(it.Param);
			return TRUE;
		}
	}
	return FALSE;
}
