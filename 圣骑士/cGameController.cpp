#include "stdafx.h"
#include "cGameController.h"
#include<Tool.h>

#ifdef _DEBUG
#pragma comment(lib,"../Debug/UiEngine.lib")
#else
#pragma comment(lib,"../Release/UiEngine.lib")
#endif // _DEBUG

void quitBtnProc(void* Param)
{
	PostQuitMessage(0);
}

void startBtnProc(void* Param)
{
	cGameController* pCon = reinterpret_cast<cGameController*>(Param);
	pCon->EntryGame(Menu_Entry);
}

void goOnBtnProc(void* Param)
{
	cGameController* pCon = reinterpret_cast<cGameController*>(Param);
	pCon->EntryReadFileView(Menu_Entry);
}

void okBtnProc(void* Param)
{
	cGameController* pCon = reinterpret_cast<cGameController*>(Param);
	pCon->EntryGame(ReadFile_Entry);
}

void goBackBtnProc(void* Param)
{
	cGameController* pCon = (cGameController*)Param;
	pCon->EntrySelectView(ReadFile_Entry);
}

cGameController::cGameController()
{
	m_IsOpenMusic = true;
	m_gameVolume = 500;
	m_pUI = NULL;
}

cGameController::~cGameController()
{
	delete m_pUI;
	m_pUI = nullptr;
}

int cGameController::OnTimer(int id, int iParam, string str)
{
	return 1;
}

void cGameController::StartGame(const HWND & hWnd)
{
	m_pUI = new MyEngine::cGameEngine(hWnd);
	auto xyBount = GetWindowBount(m_pUI->GethWnd());
	m_pUI->CenterWindow(CLIENTX + xyBount.xBount, CLIENTY + xyBount.yBount);
	m_pUI->ChangeWndStyle(m_pUI->GetWndStyle()&~WS_THICKFRAME&~WS_MAXIMIZEBOX);
	EntrySelectView(Null_Entry);
}

void cGameController::LButtonDown()
{

}

void cGameController::LButtonUp()
{

}

void cGameController::RButtonDown()
{

}

void cGameController::RButtonUp()
{
	
}

void cGameController::KeyDown(LPARAM lParam)
{
	KBDLLHOOKSTRUCT* pkhst = (KBDLLHOOKSTRUCT*)lParam;
	switch (pkhst->vkCode)
	{

	}
}

void cGameController::KeyUp(LPARAM lParam)
{
}

cGameEngine * cGameController::GetUIEngine()
{
	return m_pUI;
}

void cGameController::EntryGame(EntryStatus entry)
{
	ReleaseLastViewResource(entry);
	if (false==LoadMap(Map_Censorship1))
	{
		MessageBox(NULL, L"加载地图失败", L"", MB_OK);
	}
}

void cGameController::EntrySelectView(EntryStatus entry)
{
	ReleaseLastViewResource(entry);
    cPicture* startBg = m_pUI->CreatePicture(L"images/MenuBg.bmp", 0, 0, CLIENTX, CLIENTY);
	cText* Title = m_pUI->CreateText(L"圣骑士冒险吧!", 280, 30);
	Title->SetTextColor(RGB(255, 217, 39));
	cLine* SplitLine = m_pUI->CreateLine(POINT{ 0,90 }, POINT{ 900,90 });
	SplitLine->SetColor(RGB(181, 230, 29));
	cButton* startBtn = m_pUI->CreateButton(L"开始游戏", 320, 200);
	cButton* goOnBtn = m_pUI->CreateButton(L"读取存档", 320, 300);
	cButton* quitBtn = m_pUI->CreateButton(L"结束游戏", 320, 400);
	m_MenuList.assign({ startBg,Title,SplitLine,startBtn,goOnBtn,quitBtn });
	startBtn->SetWidth(200);
	startBtn->SetHeight(50);
	startBtn->SetnBount(5);
	goOnBtn->SetWidth(200);
	goOnBtn->SetHeight(50);
	goOnBtn->SetnBount(5);
	quitBtn->SetWidth(200);
	quitBtn->SetHeight(50);
	quitBtn->SetnBount(5);
	m_pUI->AddEventToUi(goOnBtn, WM_LBUTTONUP, goOnBtnProc, this);
	m_pUI->AddEventToUi(startBtn, WM_LBUTTONUP, startBtnProc, this);
	m_pUI->AddEventToUi(quitBtn, WM_LBUTTONUP, quitBtnProc, nullptr);
}

void cGameController::EntryReadFileView(const EntryStatus& entry)
{
	ReleaseLastViewResource(entry);
 	cPicture* ReadFileBg = m_pUI->CreatePicture(L"images/FileBg.bmp", 0, 0, CLIENTX, CLIENTY);
	cText* ReadFileTitle = m_pUI->CreateText(L"历史存档", 340, 50);
	ReadFileTitle->SetTextColor(RGB(255, 127, 39));
	cRectangle* DisPlayArea = m_pUI->CreateRectangle(RECT{ 100,150,800,350 });
	DisPlayArea->SetLineColor(RGB(239, 228, 176));
	cButton* OkBtn = m_pUI->CreateButton(L"确认", 200, 500);
	cButton* goBackBtn = m_pUI->CreateButton(L"返回", 500, 500);
	m_ReadFileList.assign({ ReadFileBg,ReadFileTitle,DisPlayArea,OkBtn,goBackBtn });
	OkBtn->SetWidth(200);
	OkBtn->SetHeight(50);
	goBackBtn->SetWidth(200);
	goBackBtn->SetHeight(50);
	m_pUI->AddEventToUi(OkBtn, WM_LBUTTONUP, okBtnProc, this);
	m_pUI->AddEventToUi(goBackBtn, WM_LBUTTONUP, goBackBtnProc, this);
}

bool cGameController::LoadMap(MapScene scene)
{
	bool bRet = true;
	switch (scene)
	{
	case Map_Censorship1:
		bRet=m_mapInfo.LoadMapFromFile("Map1.txt");
		break;
	case Map_Censorship2:
		bRet=m_mapInfo.LoadMapFromFile("");
		break;
	case Map_Censorship3:
		bRet=m_mapInfo.LoadMapFromFile("");
		break;
	case Map_Censorship4:
		bRet=m_mapInfo.LoadMapFromFile("");
		break;
	default:
		return false;
	}
	if (false == bRet)
	{
		return bRet;
	}
	bRet = ReleaseMapResource();
	if (false == bRet)
	{
		return bRet;
	}
	CreateMapResource();
	return bRet;
}

bool cGameController::ReleaseLastViewResource(const EntryStatus & status)
{
	switch (status)
	{
	case Null_Entry:
		return false;
	case Menu_Entry:
		return m_pUI->QuickDeleteUIs(m_MenuList);
	case ReadFile_Entry:
		return m_pUI->QuickDeleteUIs(m_ReadFileList);
	case Game_Entry:
		return ReleaseMapResource();
	}
	return false;
}

void cGameController::CreateMapResource()
{
	m_mapBg = m_pUI->CreatePicture(L"images/mapBg.bmp", 0, 0, CLIENTX, CLIENTY);
	int row=m_mapInfo.GetRow();
	int rank = m_mapInfo.GetRank();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < rank; ++j)
		{
			switch (m_mapInfo.at(i, j))
			{
			case Type_Box:
			{
				RowRankInfo info;
				info.row = i;
				info.rank = j;
				cPicture* Box = m_pUI->CreatePicture(L"images/Box0.bmp", j * PANESIZE, i * PANESIZE, PANESIZE, PANESIZE);
				Box->SetIsLecency(TRUE);
				Box->SetLucency(RGB(128, 128, 128));
				auto it = std::make_pair(info, Box);
				m_MapResource.insert(it);
			}
			break;
			case Type_Brick:
			{
				RowRankInfo info;
				info.row = i;
				info.rank = j;
				cPicture* Brick = m_pUI->CreatePicture(L"images/Brick.bmp", j * PANESIZE, i * PANESIZE, PANESIZE, PANESIZE);
				auto it = std::make_pair(info, Brick);
				m_MapResource.insert(it);
			}
			break;
			case Type_Door:
			{
				RowRankInfo info;
				info.row = i;
				info.rank = j;
				cAmination* Door = m_pUI->CreateAmination({ L"images/Door1.bmp",
					L"images/Door2.bmp",L"images/Door3.bmp",
					L"images/Door4.bmp" ,L"images/Door5.bmp" ,
					L"images/Door6.bmp" ,L"images/Door7.bmp" ,
					L"images/Door8.bmp" }, j * PANESIZE, i * PANESIZE, PANESIZE, PANESIZE);
				auto it = std::make_pair(info, Door);
				m_MapResource.insert(it);
			}
			break;
			case Type_Steel:
			{
				RowRankInfo info;
				info.row = i;
				info.rank = j;
				cPicture* Steel = m_pUI->CreatePicture(L"images/Steel.bmp", j * PANESIZE, i * PANESIZE, PANESIZE, PANESIZE);
				auto it = std::make_pair(info, Steel);
				m_MapResource.insert(it);
			}
				break;
			case Type_Born:
			{
				RowRankInfo info;
				info.row = i;
				info.rank = j;
				cAmination* Born= m_pUI->CreateAmination({ L"images/Door1.bmp",
					L"images/Door2.bmp",L"images/Door3.bmp",
					L"images/Door4.bmp" ,L"images/Door5.bmp" ,
					L"images/Door6.bmp" ,L"images/Door7.bmp" ,
					L"images/Door8.bmp" }, j * PANESIZE, i * PANESIZE, PANESIZE, PANESIZE);
				auto it = std::make_pair(info, Born);
				m_MapResource.insert(it);
			}
			    break;
			default:
				break;
			}
		}
	}
}

bool cGameController::ReleaseMapResource()
{
	if (m_MapResource.size() == 0)
	{
		return true;
	}
	if (!m_pUI->DeleteUI(m_mapBg))
	{
		return false;
	}
	for (auto it : m_MapResource)
	{
		if (!m_pUI->DeleteUI(it.second))
		{
			return false;
		}
	}
	m_MapResource.clear();
	return true;
}
