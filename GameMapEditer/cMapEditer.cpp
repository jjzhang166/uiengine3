#include "stdafx.h"
#include "cMapEditer.h"
#include"Tool.h"
#include<iostream>
#include<fstream>
using namespace MyEngine;

#pragma comment(lib,"msimg32.lib")
#ifdef _DEBUG
#pragma comment(lib,"../Debug/UiEngine.lib")
#else
#pragma comment(lib,"../Release/UiEngine.lib")
#endif 

UINT MapStatusColor[20] = {
RGB(0, 0, 0),RGB(127, 127, 127),
RGB(136, 0, 21),RGB(237, 28, 36),
RGB(255, 127, 39),RGB(255, 242, 0),
RGB(34, 177, 76),RGB(0, 162, 232),
RGB(63, 72, 204),RGB(163, 73, 164),
RGB(255, 255, 255),RGB(195, 195, 195),
RGB(182, 122, 87),RGB(255, 174, 201),
RGB(255, 201, 14),RGB(239, 228, 176),
RGB(181, 230, 29),RGB(153, 217, 234),
RGB(112, 146, 190),RGB(200, 191, 231)
};

cMapEditer::cMapEditer()
{
	m_MapPath = L"";
	m_rank = 0; 
	m_row = 0;
	m_terrianSpecies = 0;
	m_mapInfo = nullptr;
	m_wndWidth = 800;
	m_wndHeight = 600;
}

cMapEditer::cMapEditer(HWND hWnd)
{
	m_Ui = cGameEngine::GetEngine();
	m_Ui->init(hWnd);
	m_MapPath = L"";
	m_rank = 0;
	m_row = 0;
	m_terrianSpecies = 0;
	m_mapInfo = nullptr;
	m_wndWidth = 800;
	m_wndHeight = 600;
	MoveToCenter(hWnd, m_wndWidth, m_wndHeight);
	LONG style = m_Ui->GetWndStyle();
	style &= ~WS_THICKFRAME;
	style &= ~WS_MAXIMIZEBOX;
	m_Ui->ChangeWndStyle(style);
}


cMapEditer::~cMapEditer()
{
	deleteMapInfo();
	m_Ui->ReleaseSelf();
}

BOOL cMapEditer::SetRowAndRabk(const int & row, const int & rank,const int& terrianSpecies)
{
	if (!row || !rank||!terrianSpecies)
	{
		MessageBox(NULL, L"未指定行列数或地形种类", L"", MB_OK);
		return FALSE;
	}
	if (!lstrcmpW(m_MapPath,L""))
	{
		MessageBox(NULL, L"请指定一张地图", L"", MB_OK);
		return FALSE;
	}
	deleteMapInfo();
	m_Ui->DeleteUIs(m_splitLine);
	m_Ui->DeleteUIs(m_terrianRect);
	m_splitLine.clear();
	m_terrianRect.clear();
	m_row = row;
	m_rank = rank;
	m_terrianSpecies = terrianSpecies;
	m_mapInfo = new int*[row];
	for (size_t i = 0; i < row; ++i)
	{
		m_mapInfo[i] = new int[rank];
	}
	initMapInfo();
	CreateSplitLine();
	return TRUE;
}

BOOL cMapEditer::LoadMapResource(const LPWSTR & mapPath)
{
	if (!lstrcmpW(mapPath, L""))
	{
		return FALSE;
	}
	m_Ui->DeleteUI(m_MapImage);
	m_MapPath = mapPath;
	HBITMAP hbtimap = (HBITMAP)LoadImage(nullptr, mapPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BITMAP bitmap;
	GetObject(hbtimap, sizeof(BITMAP), &bitmap);
	DeleteObject(hbtimap);
	AutoChangeWndSize(bitmap.bmWidth, bitmap.bmHeight);
	return TRUE;
}

BOOL cMapEditer::FromFileLoadMapConfig(const LPWSTR & fileName)
{
	ifstream in(fileName, ios::in);
	if (in.fail())
	{
		return FALSE;
	}
	int row = 0;
	int rank = 0;
	int terrianSpecies;
	in >> row;
	in >> rank;
	in >> terrianSpecies;
	if (!SetRowAndRabk(row, rank, terrianSpecies))
	{
		return FALSE;
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < rank; ++j)
		{
			in >> m_mapInfo[i][j];
			if (m_mapInfo[i][j])
				CreateTerrianRect(POINT{ j*m_baseXSize +
					(m_baseXSize * 2) / 5,m_baseYSize*i +
					(m_baseYSize * 2) / 5 }, m_baseXSize / 5,
					m_baseYSize / 5, MapStatusColor[m_mapInfo[i][j]]);
		}
	}
	return TRUE;
}

void cMapEditer::CreateSplitLine()
{
	int baseSizeX = m_wndWidth / m_rank;
	int baseSizeY = m_wndHeight / m_row;
	m_baseXSize = baseSizeX;
	m_baseYSize = baseSizeY;
	for (int i = 0; i < m_row; ++i)
	{
		m_splitLine.push_back(m_Ui->CreateLine(POINT{ 0,i*baseSizeY }, POINT{ m_wndWidth,i*baseSizeY }));
	}
	for (int i = 0; i < m_rank; ++i)
	{
		m_splitLine.push_back(m_Ui->CreateLine(POINT{ i*baseSizeX,0 }, POINT{ i*baseSizeX,m_wndHeight }));
	}
}

BOOL cMapEditer::SaveMapFile(const LPWSTR & fileName)
{
	char strFileName[MAX_PATH] = { 0 };
	WideCharToMultiByte(CP_ACP, NULL, fileName, lstrlenW(fileName), strFileName, 1024, NULL, FALSE);
	ofstream out(strFileName, ios::out);
	if (out.fail())
	{
		return FALSE;
	}
	out << m_row << " " << m_rank << " " << m_terrianSpecies << endl;
	for (int i = 0; i < m_row; ++i)
	{
		for (int j = 0; j < m_rank; ++j)
		{
			out << m_mapInfo[i][j] << " ";
		}
		out << endl;
	}
	out.close();
	return TRUE;
}

void cMapEditer::MouseDown()
{
	if (!m_row || !m_rank)
	{
		return;
	}
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(m_Ui->GethWnd(), &pt);
	int rank = pt.x / m_baseXSize;
	int row = pt.y / m_baseYSize;
	if (m_terrianSpecies)
	{
		m_mapInfo[row][rank] = (m_mapInfo[row][rank] + 1) % m_terrianSpecies;
		CreateTerrianRect(POINT{ rank*m_baseXSize + (m_baseXSize * 2) / 5,m_baseYSize*row + (m_baseYSize * 2) / 5 }, m_baseXSize / 5, m_baseYSize / 5, MapStatusColor[m_mapInfo[row][rank]]);
	}
}

void cMapEditer::StartEdit(HWND hWnd)
{
	m_MapPath = L"";
	m_rank = 0;
	m_row = 0;
	m_terrianSpecies = 0;
	m_mapInfo = nullptr;
	m_wndWidth = 800;
	m_wndHeight = 600;
	MoveToCenter(hWnd, m_wndWidth, m_wndHeight);
	m_Ui->SethWnd(hWnd);
	LONG style = m_Ui->GetWndStyle();
	style &= ~WS_THICKFRAME;
	style &= ~WS_MAXIMIZEBOX;
	m_Ui->ChangeWndStyle(style);
}

bool cMapEditer::deleteMapInfo()
{
	if (m_mapInfo == nullptr)
	{
		return false;
	}
	for (size_t i = 0; i < m_row; ++i)
	{
		delete[] m_mapInfo[i];
		m_mapInfo[i] = nullptr;
	}
	return true;
}

BOOL cMapEditer::AutoChangeWndSize(const int & mapWidth, const int & mapHeight)
{
	int maxWidth = GetSystemMetrics(SM_CXSCREEN)-100;
	int maxHeight = GetSystemMetrics(SM_CYSCREEN)-95;
	auto xyBount = GetWindowBount(m_Ui->GethWnd());
	if (mapWidth < maxWidth&&mapHeight<maxHeight)
	{
		MoveToCenter(m_Ui->GethWnd(), mapWidth + xyBount.xBount, mapHeight + xyBount.yBount);
		m_wndWidth = mapWidth;
		m_wndHeight = mapHeight;
	    m_MapImage=m_Ui->CreatePicture(m_MapPath, 0, 0);
	}
	else
	{
		m_wndWidth = (mapWidth*maxHeight) / mapHeight;
		m_wndHeight = (mapHeight*maxWidth) / mapWidth;
		m_wndWidth <= maxWidth ? m_wndHeight = maxHeight : m_wndWidth = maxWidth;
		MoveToCenter(m_Ui->GethWnd(), m_wndWidth + xyBount.xBount, m_wndHeight + xyBount.yBount);
		m_MapImage = m_Ui->CreatePicture(m_MapPath, 0, 0,m_wndWidth,m_wndHeight);
	}
	return  true;
}

void cMapEditer::initMapInfo()
{
	for (int i = 0; i < m_row; ++i)
	{
		for (int j = 0; j < m_rank; ++j)
		{
			m_mapInfo[i][j] = 0;
		}
	}
}

void cMapEditer::CreateTerrianRect(const POINT & pt, const int& w, const int& h, const UINT& fillColor)
{
	for (auto it=m_terrianRect.begin();it!=m_terrianRect.end();++it)
	{
		if (pt.x == (*it)->GetRect().left&&pt.y == (*it)->GetRect().top)
		{
			if (fillColor == MapStatusColor[0])
			{
				m_Ui->DeleteUI(*it);
				m_terrianRect.erase(it);
			}
			else
			{
				dynamic_cast<MyEngine::cRectangle*>(*it)->SetFillColor(fillColor);
				dynamic_cast<MyEngine::cRectangle*>(*it)->SetLineColor(fillColor);
			}
			return;
		}
	}
	MyEngine::cRectangle* rect = m_Ui->CreateRectangle(RECT{ pt.x,pt.y,pt.x + w,pt.y + h });
	rect->SetIsFill(true);
	rect->SetLineColor(fillColor);
	rect->SetFillColor(fillColor);
	m_terrianRect.push_back(rect);
}