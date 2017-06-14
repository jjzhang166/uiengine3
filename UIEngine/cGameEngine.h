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
	UI�����࣬�������н����ϵ�ͼ����ʾ��ͼ����ָ�봴������
	����������ɾ����UI�������ڳ������ʱ���Զ�ɾ�����û�Ҳ
	������Ҫʱ����ɾ����
	*/
	class cGameEngine :public cMyTimer
	{
	public:
		cGameEngine();

		explicit cGameEngine(HWND hWnd);
		~cGameEngine();

		/*
		OnTimer(int id,int iParam,string str)
		������ʱ����Ϣ�ص�����
		@Param
			int id:�ص���ʱ��id
			int iParam:��ʱ�����Ӳ���
			string str����ʱ������
		@return int��
			0����ʾ�ö�ʱ������ɾ��
		*/
		virtual int OnTimer(int id, int iParam, string str);

		/*
		CenterWindow(int w = 0, int h = 0)
		���ͻ����ھ���
		@Param:
			int w�����ڿ���
			int h�����ڸ߶�
		@return int��
			0���ɹ�����
			-1������ʧ��
		*/
		int CenterWindow(int w = 0, int h = 0);

		/*
		GetLastError()
		��ȡ��һ�δ�����Ϣ
		@return const LPWSTR&:
			������Ϣ��
		*/
		const LPWSTR& GetLastError() const;

		/*
		CreateText(const LPWSTR& text,const int& x,const int& y)
		����һ��Text�ı�
		@Param
			LPWSTR text:�ı�����
			int x:�ı�x����
			int y:�ı�y����
		@return cText��
			�ɹ��򷵻ش������ı�ָ�룬ʧ���򷵻�nullptr
		*/
		cText* CreateText(const LPWSTR& text, const int& x , const int& y );

		/*
		CreateLine(const POINT& start,const POINT& end)
		����һ��ֱ��
		@Param��
			POINT start��ֱ�����
			POINT end��ֱ���յ�
		@return cLine*:
			������ֱ�߶���ָ��
		*/
		cLine* CreateLine(const POINT& start, const POINT& end);

		/*
		CreateButton(const LPWSTR& Name,cosnt int& x,const int& y)
		����һ����ť
		@Param��
			LPWSTR Name:��ť��
			int x:��ťx����
			int y����ťy����
		@return cButton*��
			�����İ�ť����ָ��
		*/
		cButton* CreateButton(const LPWSTR& Name, const int& x, const int& y);

		/*
		CreateBitmapButton(const LPWSTR& bmpPath,const int& x,const int& y)
		����ͼƬ��ť
		@Param:
			LPWSTR bmpPath��λͼ��Դ·��
			int x:��ťx����
			int y:��ťy����
		@return��
			�����İ�ť����ָ��
		*/
		cButton* CreateBitmapButton(const LPWSTR& bmpPath,const int& x,const int& y);

		/*
		CreateBitmapButton(const HBITMAP& hbitmap,const int& x,const int& y)
		����ͼƬ��ť
		@Param:
			HBITMAP hbitmap��λͼ��Դ���
			int x:��ťx����
			int y:��ťy����
		@return��
			�����İ�ť����ָ��
		*/
		cButton* CreateBitmapButton(const HBITMAP& bitmap,const int& x,const int& y);

		/*
		CreateCircle(const RECT& rect)
		����һ��Բ
		@Param��
			RECT rect����Բ����Ӿ���
		@return cCircle*��
			������Բ����ָ��
		*/
		cCircle* CreateCircle(const RECT& rect);

		/*
		CreatePicture(const HBITMAP& bitmap,const int& x,const int& y)
		����һ��ͼƬ
		@Param:
			HBITMAP bitmap��λͼ���
			int x��ͼƬx����
			int y��ͼƬy����
		@return cPicture*��
			������ͼƬ����ָ��
		*/
		cPicture* CreatePicture(const HBITMAP& bitmap,const int& x,const int& y);

		/*
		CreatePicture(const LPWSTR& name,const int& x,const int& y,const int& w = 0, const int& h = 0)
		����ͼƬ·������һ��ͼƬ
		@Param:
		LPWSTR Name��ͼƬ·����
		int x��ͼƬx����
		int y��ͼƬy����
		int w��ָ��ͼƬ����
		int h��ָ��ͼƬ�߶�
		@return cPicture*��
		������ͼƬ����ָ��
		*/
		cPicture* CreatePicture(const LPWSTR& Name, const int& x, const int& y, const int& w = 0, const int& h = 0);

		/*
		CreateRectangle(const RECT& rect)
		����һ������
		@Param��
			RECT rect�������ľ�������
		@return cRectangle*��
			�����ľ��ζ���ָ��
		*/
		cRectangle* CreateRectangle(const RECT& rect);

		/*
		CreateTriangle(const POINT& p1,const POINT& p2,const POINT p3)
		����һ��������
		@Param��
			POINT p1:���������еĵ�һ����
			POINT p2�����������εĵڶ�����
			POINT p3�����������εĵ�������
		@return cTriangle*��
			�����������ζ���ָ��
		*/
		cTriangle* CreateTriangle(const POINT& p1, const POINT& p2, const POINT& p3);

		/*
		CreatePolygon(std::initializer_list<POINT> pointList)
		����һ�������
		@Param��
			initializer_list<POINT> pointList:���ɶ���εĻ������б�
		@return cPolygon*��
			�����Ķ���ζ���ָ��
		*/
		cPolygon* CreatePolygon(std::initializer_list<POINT> pointList);

		/*
		CreateAmination(const std::initializer_list<LPWSTR>& pathList,const int& x,const int& y)
		����������Դ
		@Param��
			std::initializer_list pathList��������Դ·�����б�
			int x������x����
			int y������y����
		@return cAmination*:
			��������ָ��
		*/
		cAmination *CreateAmination(const std::initializer_list<LPWSTR>& pathList, const int &x, const int& y, const int& w= 0, const int& h = 0);

		/*
		AddEventToUI(const cBaseUI* ui,UINT_PTR eventIdCallEventBack callBack)
		ΪUI�ؼ������¼���������
		@Param��
			cBaseUI* ui����Ҫ�����¼�������ui�ؼ�
			CallEventBack callBack:�¼������ص�����
		*/
		void AddEventToUi(cBaseUI* ui, UINT_PTR eventId, CallEeventBack callBack, void* Param);

		/*
		int DeleteUI(cBaseUI *pDel);
		ɾ��ָ��ui�ؼ�
		@Param :
			pDel��ָ��Ҫɾ����ui�ؼ���ָ��
		@return int��
			0��δ�ҵ�ɾ����
			1��ɾ���ɹ�
		*/
		int DeleteUI(cBaseUI* pDel);

		/*
		DeleteUIs(std::list<cBseUI*> pDelList)
		ɾ�����UIԪ��
		@Param pDelList��
			std::list<cBaseUI*> pDelList����Ҫɾ����UI�б�
		@return int��
			ɾ���ĸ���
		*/
		int DeleteUIs(std::list<cBaseUI*> pDelList);

		/*
		QuickDeleteUIs(std::initializer_list<cBaseUI*> pDelList)
		����ɾ�����UI�ؼ�������ɾ���б��еĿؼ�˳���봴��˳��һ��
		@Param:
			std::initializer_list<cBaseUI*> pDelList:��Ҫɾ����UI�б�
		@return int��
			ʵ��ɾ����UI�ؼ�����
		*/
		int QuickDeleteUIs(std::list<cBaseUI*> pDelList);

		/*
		DeleteEvent(cBaseUI* ui,UINT_PTR eventId)
		ɾ��UI�ؼ���ָ���¼�
		@Param��
			cBaseUI* ui��ָ��Ҫɾ���Ŀؼ�����ָ��
			UINT_PTR eventId���¼�id
		@return BOOL:
			TRUE��ɾ���ɹ�
			FALSE��ɾ��ʧ��
		*/
		BOOL DeleteEvent(cBaseUI* ui, UINT_PTR eventId);

		/*
		DeleteEvent(cBaseUI* ui)
		ɾ��ĳһUI�ؼ�������������¼�
		@Param��
			cBaseUI* ui��ָ����ui�ؼ�����ָ��
		@return int��
			ɾ�����¼�����
		*/
		int DeleteEvent(cBaseUI* ui);

		/*
		DrawUI();
		 ����UI����
		*/
		void DrawUI();

		/*
		DoMouseMsg()
		���������Ϣ
		@Param��
			WPARAM wParam�������Ϣ��ϸ��Ϣ
		*/
		void DoMouseMsg(WPARAM wParam);

		/*
		DoKeyDownMsg(LPARAM lParam)
		�������̰���������Ϣ
		@Param��
			LPARAM lParam����Ϣ����ϸ��Ϣ
		*/
		void DoKeyDownMsg(LPARAM lParam);

		/*
		DoKeyDownMsg(LPARAM lParam)
		�������̰���������Ϣ
		@Param��
			LPARAM lParam����Ϣ����ϸ��Ϣ
		*/
		void DoKeyUpMsg(LPARAM lParam);

		/*
		CheckButtonGetOrLostFocus()
		��ⰴťʧȥ��õ�����
		*/
		void CheckButtonGetOrLostFocus();

		/*
		CheckButtonClick(const Btn_Status clicked)
		��ⰴť�Ƿ񱻵��
		@Param��
			Btn_Status clicked����ť�Ƿ񱻵��
		*/
		void CheckButtonClick(const Btn_Status& clicked);

		/*
		DoUiKeyEvent(const UINT_PTR& eventId)
		����ui�ؼ������¼�
		@Param��
			UINT_PTR eventId���¼�id
		*/
		void DoUiKeyEvent(const UINT_PTR& eventId);

		/*
		DoUiMouseEvent(const UINT_PTR& eventId)
		����ui�ؼ�����¼�
		@Param:
			UINT_PTR eventId���¼�id
		*/
		void DoUiMouseEvent(const UINT_PTR& eventId);

		/*
		GethWnd()
		��ȡ�󶨵Ĵ��ھ��
		@return HWND��
			���ھ��
		*/
		HWND GethWnd() const;

		/*
		SethWnd(HWND hWnd);
		���ô��ھ��
		@Param:
			HWND hWnd���󶨵Ĵ��ھ��
		*/
		void SethWnd(HWND hWnd);

		/*
		GetWndStyle()
		��ȡ���ڷ��
		@return LONG:
			���ڵ�ǰ���
		*/
		LONG GetWndStyle();

		/*
		ChangeWndStyle(const LONG& style)
		�ı䴰�ڷ��
		@Param��
			LONG style:�µĴ��ڷ��
		@return BOOL��
			TRUE���ı�ɹ�
			FALSE���ı�ʧ��
		*/
		BOOL ChangeWndStyle(const LONG& style);
	private:
		/*
		DealMouseMsg(cBaseUI* ui,UINT_PTR eventId)
		����UI�ؼ�������¼�
		@Param:
			cBaseUI* ui������Ҫ��Ӧ�¼���UI�ؼ�ָ��
			UINT_PTR eventId:�¼�id
		@return BOOL:
			TRUE:��Ӧ���¼�
			FALSE��δ��Ӧ�¼�
		*/
		BOOL DealMouseMsg(const  cBaseUI* ui,const UINT_PTR& eventId);

		HWND m_hWnd;

		//������Ϣ
		LPWSTR m_wError;

		//����UI�ؼ��б�
		std::list<cBaseUI*> m_uiList;

		std::list<UI_Event> m_evnetList;

		//����Ϊ������UI�ؼ�����ID
		static UINT_PTR m_Uid;
	};
}