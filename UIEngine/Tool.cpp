#include"stdafx.h"
#include "Tool.h"
#include<iostream>
//#include<initializer_list>
//using namespace std;

bool MoveToCenter(const HWND& hWnd, const int& sizeX, const int& sizeY, const int& offsetX , const int& offsetY)
{
	int ScreenX, ScreenY;
	if (!MoveWindow(hWnd, 0, 0, sizeX, sizeY, FALSE))
	{
		return false;
	}
	ScreenX = GetSystemMetrics(SM_CXSCREEN);
	ScreenY = GetSystemMetrics(SM_CYSCREEN);
	if (!MoveWindow(hWnd, (ScreenX - sizeX) / 2 + offsetX, (ScreenY - sizeY) / 2 + offsetY, sizeX, sizeY, TRUE))
	{
		return false;
	}
	return true;
}

int WcharArrayChineseNums(const LPWSTR & str)
{
	int len = lstrlenW(str);
	int iCount = 0;
	for (size_t i = 0; i < len; ++i)
	{
		if (str[i] >= 0x4E00 && str[i] <= 0x9FA5)
		{
			++iCount;
		}
	}
	return iCount;
}

WndBount  GetWindowBount(HWND hWnd)
{
	WndBount xyBount;
	RECT rect1;
	GetWindowRect(hWnd, &rect1);
	RECT rect2;
	GetClientRect(hWnd, &rect2);
	xyBount.xBount = (rect1.right - rect1.left) - (rect2.right - rect2.left);
	xyBount.yBount = (rect1.bottom - rect1.top) - (rect2.bottom - rect2.top);
	return xyBount;
}

//BOOL DeleteHGDIOBJS(initializer_list<HGDIOBJ> hgdiobjList)
//{
//	for (auto it : hgdiobjList)
//	{
//		return DeleteObject(it);
//	}
//}
