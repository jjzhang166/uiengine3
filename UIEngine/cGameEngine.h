#pragma once
#include<list>
#include<vector>
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
	 	UINT_PTR EventId;
		void *Param;
		CallEeventBack CallProc;
	}UI_Event;

	/*
	cGameEngine
	UI引擎类，管理所有界面上的图形显示，图形类指针创建后用
	户无需主动删除，UI引擎类在程序结束时会自动删除，用户也
	可在需要时主动删除。
	*/
	class cGameEngine :public cMyTimer
	{
	public:
		cGameEngine();

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
		CenterWindow(int w = 0, int h = 0)
		将客户窗口居中
		@Param:
			int w：窗口宽度
			int h：窗口高度
		@return int：
			0：成功居中
			-1：居中失败
		*/
		int CenterWindow(int w = 0, int h = 0);

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
		CreateBitmapButton(const LPWSTR& bmpPath,const int& x,const int& y)
		创建图片按钮
		@Param:
			LPWSTR bmpPath：位图资源路径
			int x:按钮x坐标
			int y:按钮y坐标
		@return：
			创建的按钮对象指针
		*/
		cButton* CreateBitmapButton(const LPWSTR& bmpPath,const int& x,const int& y);

		/*
		CreateBitmapButton(const HBITMAP& hbitmap,const int& x,const int& y)
		创建图片按钮
		@Param:
			HBITMAP hbitmap：位图资源句柄
			int x:按钮x坐标
			int y:按钮y坐标
		@return：
			创建的按钮对象指针
		*/
		cButton* CreateBitmapButton(const HBITMAP& bitmap,const int& x,const int& y);

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
		CreatePicture(const LPWSTR& name,const int& x,const int& y,const int& w = 0, const int& h = 0)
		根据图片路径创建一个图片
		@Param:
		LPWSTR Name：图片路径名
		int x：图片x坐标
		int y：图片y坐标
		int w：指定图片宽度
		int h：指定图片高度
		@return cPicture*：
		创建的图片对象指针
		*/
		cPicture* CreatePicture(const LPWSTR& Name, const int& x, const int& y, const int& w = 0, const int& h = 0);

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
		CreateAmination(const std::initializer_list<LPWSTR>& pathList,const int& x,const int& y)
		创建动画资源
		@Param：
			std::initializer_list pathList：动画资源路径名列表
			int x：动画x坐标
			int y：动画y坐标
		@return cAmination*:
			动画对象指针
		*/
		cAmination *CreateAmination(const std::initializer_list<LPWSTR>& pathList, const int &x, const int& y, const int& w= 0, const int& h = 0);

		/*
		AddEventToUI(const cBaseUI* ui,UINT_PTR eventIdCallEventBack callBack)
		为UI控件添加事件处理函数
		@Param：
			cBaseUI* ui：需要添加事件处理的ui控件
			CallEventBack callBack:事件处理回调函数
		*/
		void AddEventToUi(cBaseUI* ui, UINT_PTR eventId, CallEeventBack callBack, void* Param);

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
		DeleteUIs(std::list<cBseUI*> pDelList)
		删除多个UI元素
		@Param pDelList：
			std::list<cBaseUI*> pDelList：需要删除的UI列表
		@return int：
			删除的个数
		*/
		int DeleteUIs(std::list<cBaseUI*> pDelList);

		/*
		QuickDeleteUIs(std::initializer_list<cBaseUI*> pDelList)
		快速删除多个UI控件，仅限删除列表中的控件顺序与创建顺序一致
		@Param:
			std::initializer_list<cBaseUI*> pDelList:需要删除的UI列表
		@return int：
			实际删除的UI控件个数
		*/
		int QuickDeleteUIs(std::list<cBaseUI*> pDelList);

		/*
		DeleteEvent(cBaseUI* ui,UINT_PTR eventId)
		删除UI控件的指定事件
		@Param：
			cBaseUI* ui：指定要删除的控件对象指针
			UINT_PTR eventId：事件id
		@return BOOL:
			TRUE：删除成功
			FALSE：删除失败
		*/
		BOOL DeleteEvent(cBaseUI* ui, UINT_PTR eventId);

		/*
		DeleteEvent(cBaseUI* ui)
		删除某一UI控件相关联的所有事件
		@Param：
			cBaseUI* ui：指定的ui控件对象指针
		@return int：
			删除的事件个数
		*/
		int DeleteEvent(cBaseUI* ui);

		/*
		DrawUI();
		 绘制UI界面
		*/
		void DrawUI();

		/*
		DoMouseMsg()
		处理鼠标消息
		@Param：
			WPARAM wParam：鼠标消息详细信息
		*/
		void DoMouseMsg(WPARAM wParam);

		/*
		DoKeyDownMsg(LPARAM lParam)
		处理键盘按键按下消息
		@Param：
			LPARAM lParam：消息的详细信息
		*/
		void DoKeyDownMsg(LPARAM lParam);

		/*
		DoKeyDownMsg(LPARAM lParam)
		处理键盘按键弹起消息
		@Param：
			LPARAM lParam：消息的详细信息
		*/
		void DoKeyUpMsg(LPARAM lParam);

		/*
		CheckButtonGetOrLostFocus()
		检测按钮失去或得到焦点
		*/
		void CheckButtonGetOrLostFocus();

		/*
		CheckButtonClick(const Btn_Status clicked)
		检测按钮是否被点击
		@Param：
			Btn_Status clicked：按钮是否被点击
		*/
		void CheckButtonClick(const Btn_Status& clicked);

		/*
		DoUiKeyEvent(const UINT_PTR& eventId)
		处理ui控件键盘事件
		@Param：
			UINT_PTR eventId：事件id
		*/
		void DoUiKeyEvent(const UINT_PTR& eventId);

		/*
		DoUiMouseEvent(const UINT_PTR& eventId)
		处理ui控件鼠标事件
		@Param:
			UINT_PTR eventId：事件id
		*/
		void DoUiMouseEvent(const UINT_PTR& eventId);

		/*
		GethWnd()
		获取绑定的窗口句柄
		@return HWND：
			窗口句柄
		*/
		HWND GethWnd() const;

		/*
		SethWnd(HWND hWnd);
		设置窗口句柄
		@Param:
			HWND hWnd：绑定的窗口句柄
		*/
		void SethWnd(HWND hWnd);

		/*
		GetWndStyle()
		获取窗口风格
		@return LONG:
			窗口当前风格
		*/
		LONG GetWndStyle();

		/*
		ChangeWndStyle(const LONG& style)
		改变窗口风格
		@Param：
			LONG style:新的窗口风格
		@return BOOL：
			TRUE：改变成功
			FALSE：改变失败
		*/
		BOOL ChangeWndStyle(const LONG& style);
	private:
		/*
		DealMouseMsg(cBaseUI* ui,UINT_PTR eventId)
		处理UI控件鼠标点击事件
		@Param:
			cBaseUI* ui：可能要响应事件的UI控件指针
			UINT_PTR eventId:事件id
		@return BOOL:
			TRUE:响应了事件
			FALSE：未响应事件
		*/
		BOOL DealMouseMsg(const  cBaseUI* ui,const UINT_PTR& eventId);

		HWND m_hWnd;

		//错误信息
		LPWSTR m_wError;

		//保存UI控件列表
		std::list<cBaseUI*> m_uiList;

		std::list<UI_Event> m_evnetList;

		//用于为创建的UI控件分配ID
		static UINT_PTR m_Uid;
	};
}