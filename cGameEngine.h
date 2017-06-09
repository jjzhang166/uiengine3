#pragma once
#include<list>
#include"cMyTimer.h"
#include"cText.h"
#include"cButton.h"
#include"cPicture.h"
#include"cAmination.h"
#include"cTriangle.h"
#include"cLine.h"
#include"cRectangle.h"
#include"cCircle.h"
#include"cPolygon.h"

namespace MyEngine
{
	typedef void(*CallEeventBack)(void *param);

	typedef struct _UI_Event
	{
		cBaseUI* controller;
		CallEeventBack CallProc;
	}UI_Event;

	class cGameEngine :public cMyTimer
	{
	public:
		explicit cGameEngine(HWND hWnd);
		~cGameEngine();

		/*
		OnTimer(int id,int iParam,string str)
		处理定时器消息回调函数
		@Param
			int id:回调定时器id
			int iParam:定时器附加参数
			string str：定时器描述
		@return int：
			0：表示该定时器将被删除
		*/
		virtual int OnTimer(int id, int iParam, string str);

		/*
		CenterWindow()
		将客户窗口居中
		@return int：
			0：成功居中
			-1：居中失败
		*/
		int CenterWindow();

		/*
		GetLastError()
		获取上一次错误信息
		@return const LPWSTR&:
			错误信息串
		*/
		const LPWSTR& GetLastError() const;

		/*
		CreateText(const LPWSTR& text,const int& x,const int& y)
		创建一个Text文本
		@Param
			LPWSTR text:文本内容
			int x:文本x坐标
			int y:文本y坐标
		@return cText：
			成功则返回创建的文本指针，失败则返回nullptr
		*/
		cText* CreateText(const LPWSTR& text, const int& x , const int& y );

		/*
		CreateLine(const POINT& start,const POINT& end)
		创建一条直线
		@Param：
			POINT start：直线起点
			POINT end：直线终点
		@return cLine*:
			创建的直线对象指针
		*/
		cLine* CreateLine(const POINT& start, const POINT& end);

		/*
		CreateButton(const LPWSTR& Name,cosnt int& x,const int& y)
		创建一个按钮
		@Param：
			LPWSTR Name:按钮名
			int x:按钮x坐标
			int y：按钮y坐标
		@return cButton*：
			创建的按钮对象指针
		*/
		cButton* CreateButton(const LPWSTR& Name, const int& x, const int& y);

		/*
		CreateCircle(const RECT& rect)
		创建一个圆
		@Param：
			RECT rect：该圆的外接矩形
		@return cCircle*：
			创建的圆对象指针
		*/
		cCircle* CreateCircle(const RECT& rect);

		/*
		CreatePicture(const LPWSTR& name,const int& x,const int& y)
		创建一个图片
		@Param:
		LPWSTR Name：图片路径名
		int x：图片x坐标
		int y：图片y坐标
		@return cPicture*：
		创建的图片对象指针
		*/
		cPicture* CreatePicture(const LPWSTR& name, const int& x, const int& y);

		/*
		CreatePicture(const HBITMAP& bitmap,const int& x,const int& y)
		创建一个图片
		@Param:
			HBITMAP bitmap：位图句柄
			int x：图片x坐标
			int y：图片y坐标
		@return cPicture*：
			创建的图片对象指针
		*/
		cPicture* CreatePicture(const HBITMAP& bitmap,const int& x,const int& y);

		/*
		CreateRectangle(const RECT& rect)
		创建一个矩形
		@Param：
			RECT rect：创建的矩形区域
		@return cRectangle*：
			创建的矩形对象指针
		*/
		cRectangle* CreateRectangle(const RECT& rect);

		/*
		CreateTriangle(const POINT& p1,const POINT& p2,const POINT p3)
		创建一个三角形
		@Param：
			POINT p1:构成三角行的第一个点
			POINT p2：构成三角形的第二个点
			POINT p3：构成三角形的第三个点
		@return cTriangle*：
			创建的三角形对象指针
		*/
		cTriangle* CreateTriangle(const POINT& p1, const POINT& p2, const POINT& p3);

		/*
		CreatePolygon(std::initializer_list<POINT> pointList)
		创建一个多边形
		@Param：
			initializer_list<POINT> pointList:构成多边形的基础点列表
		@return cPolygon*：
			创建的多边形对象指针
		*/
		cPolygon* CreatePolygon(std::initializer_list<POINT> pointList);

		/*
		int DeleteUI(cBaseUI *pDel);
		删除指定ui控件
		@Param :
			pDel：指定要删除的ui控件的指针
		@return int：
			0：未找到删除项
			1：删除成功
		*/
		int DeleteUI(cBaseUI* pDel);

		/*
		DrawUI();
		 绘制UI界面
		*/
		void DrawUI();

		/*
		
		*/
		void DoMouseMsg();

		/*
		
		*/
		void DoKeyMsg();

		/*
		GethWnd()
		获取绑定的窗口句柄
		@return HWND:
			绑定的窗口句柄
		*/
		const HWND& GethWnd() const;
	private:
		//游戏引擎绑定的窗口句柄
		HWND m_hWnd;

		//错误信息
		LPWSTR m_wError;

		//保存UI控件列表
		std::list<cBaseUI*> m_uiList;
	};
}

