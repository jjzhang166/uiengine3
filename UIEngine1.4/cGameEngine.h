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
#include"cSight.h"
#include"cResourcePool.h"
#include"Lock.h"
#include<thread>

namespace MyEngine
{
	 typedef struct SIZE
	{
		int width;
		int height;
	};

	/*
	cGameEngine
	UI�����࣬�������н����ϵ�ͼ����ʾ��ͼ����ָ�봴������
	����������ɾ����UI�������ڳ������ʱ���Զ�ɾ�����û�Ҳ
	������Ҫʱ����ɾ����
	������õ�ʵ�����ģʽ����Ҫ��ͼ�½�����Ķ���
	��Ҫͨ��GetEngine()��ȡ�������
	*/
	class cGameEngine :public cMyTimer
	{
	public:
		/*
		*GetEngine();
		*��ȡ��ʵ���������
		*/
		static cGameEngine* GetEngine();

		/*
		*init(HINSTANCE hInst, LPWSTR Title = L"LSYENGINE);
		*��ʼ������
		*@Param hInst:ʵ�����
		*@Param title:���ڱ���
		*/
		void init(HINSTANCE hInst);

		/*
		*LuanchEngine();
		*�������棬����ǰ�����Ѿ�������init();
		*/
		int LuanchEngine();

		/*
		OnTimer(int id,int iParam,string str)
		����ʱ����Ϣ�ص�����
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
		���ͻ����ھ���,������init()֮��ʹ�ò���Ч
		@Param:
			int w�����ڿ��
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
		*CreateButtonByKey(std::string key);
		*ͨ��keyֵ�½�һ��Button��Ҫ�����Դ�Ѿ����ؽ���Դ��
		*@Param��
		*	key��keyֵ
		*/
		cButton* CreateButtonByKey(std::string key);
		
		/*
		CreateCircle(const RECT& rect)
		����һ��Բ
		@Param��
			center:Բ��
			radius���뾶
		@return cCircle*��
			������Բ����ָ��
		*/
		cCircle* CreateCircle(const POINT& center,const UINT& radius);

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
		int w��ָ��ͼƬ���
		int h��ָ��ͼƬ�߶�
		@return cPicture*��
		������ͼƬ����ָ��
		*/
		cPicture* CreatePicture(const LPWSTR& Name, const int& x, const int& y, const int& w = 0, const int& h = 0);

		/*
		*CreatePictureByKey(std::string key);
		*ͨ��keyֵ�½�һ��ͼƬ��Ҫ�����Դ�Ѿ����ؽ���Դ��
		*@Param��
		*	key��keyֵ
		*/
		cPicture* CreatePictureByKey(std::string key);

		/*
		CreateRectangle(const RECT& rect)
		����һ������
		@Param center:�������ĵ�
		@Param width�����ο��
		@Param height�����θ߶�
		@return cRectangle*��
			�����ľ��ζ���ָ��
		*/
		cRectangle* CreateRectangle(const POINT& center, const int& width, const int& height);

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
		CreateAmination(const LPWSTR& Name,const int& smallRow,const int& smallRank,const int& w = 0,const int h = 0);
		һ���Ŵ�ͼ����һ������
		@Param��
			LPWSTR Name��ͼƬ·��
			int smallrow��Сͼ����
			int smallRank��Сͼ����
		*/
		cAmination* CreateAmination(const LPWSTR& Name,const int& smallRow,const int& smallRank,const int& w = 0,const int h = 0);

		/*
		CreateAmination(const LPWSTR& Name,const int& smallRow,const int& smallRank,const int& w = 0,const int h = 0);
		һ���Ŵ�ͼ����һ������
		@Param��
			HBITMAP hbitmap��λͼ��Դ���
			int smallrow��Сͼ����
			int smallRank��Сͼ����
		*/
		cAmination* CreateAmination(const HBITMAP& hbitmap, const int& smallrow, const int& smallrank);

		/*
		*CreateAminationByKey(std::string key);
		*ͨ��keyֵ�½�һ����ͼƬ������Ҫ�����Դ�Ѿ����ؽ���Դ��
		*@Param��
		*	key��keyֵ
		*/
		cAmination* CreateAminationByKey(std::string key);

		/*
		*CreateAminationByKey(std::string key, const int& smallRow, const int& smallRank);
		*ͨ��keyֵ�½�һ�Ŵ�ͼ������Ҫ�����Դ�Ѿ����ؽ���Դ��
		*@Param��
		*	key��keyֵ
		*/
		cAmination* CreateAminationByKey(std::string key, const int& smallRow, const int& smallRank);

		/*
		*CreateSight
		*����һ����Ұ
		*@return cSight* ����Ұ����ָ��
		*/
		cSight* CreateSight();

		/*
		AddEventToUI(const cBaseUI* ui,UINT_PTR eventIdCallEventBack callBack)
		ΪUI�ؼ�����¼�������
		@Param��
			trigger:�¼��Ĵ�����
			eventId:�¼�id��������Ϊ�����¼�
			callBack:�¼�����ص�����
			handler:�¼��Ĵ�����
			Param:Ԥ����������Ϊ��ʱ�����¼�id
		*/
		void AddEventToUi(cBaseUI* trigger, UINT_PTR eventId, SEL_CallFunc callBack, cBaseUI* handler, void* Param = NULL);

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
		DeleteEvent(cBaseUI* ui);
		ɾ��ָ��ui�ؼ��������¼�
		@Param ui:ָ����ui�ؼ�
		@return int��ʧ�ܷ���0���ɹ�����ɾ�����¼�����
		*/
		int DeleteEvent(cBaseUI* ui);

		/*
		DeleteEvent(cBaseUI* ui)
		ɾ��ĳһUI�ؼ�������������¼�
		@Param��
			uid��ָ����ui�ؼ���id��
		@return int��
			ɾ�����¼�����
		*/
		int DeleteEvent(UINT_PTR uid);

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
		DoKeyMsg(LPARAM lParam)
		������̰���������Ϣ
		@Param��
			LPARAM lParam����Ϣ����ϸ��Ϣ
		*/
		void DoKeyMsg(UINT message,WPARAM wParam);

		/*
		DoUiKeyEvent(const UINT_PTR& eventId)
		����ui�ؼ������¼�
		@Param��
			UINT_PTR eventId���¼�id
		*/
		void DoUiKeyEvent(WPARAM wParam,UINT_PTR eventId);

		/*
		DoUiMouseEvent(const UINT_PTR& eventId)
		����ui�ؼ�����¼�
		@Param:
			UINT_PTR eventId���¼�id
		*/
		void DoUiMouseEvent(UINT_PTR eventId);

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

		/*
		*AddEngineUi
		*�����������UI�ؼ�
		*@Param ui*����ӽ������ui�ؼ�
		*@return bool����ӳɹ�����true������ÿؼ��Ѿ������������򷵻�false
		*/
		bool AddEngineUi(cBaseUI* ui);

		void ReleaseSelf();

		/*
		*GetClientSize();
		*��ȡ�ͻ������ڳߴ�
		*@return SIZE�����ؿͻ����ߴ�
		*/
		SIZE GetClientSize();

		/*
	    *GetMouseStatus();
		*��ȡ���״̬
		*@return Mouse_Status:������굱ǰ״̬���Ƿ���
		*���·���Mouse_Down�����򷵻�Mouse_Up
		*/
		Mouse_Status GetMouseStatus();

		/*
		*RegisterWinClass();
		*ע�ᴰ����
		*/
		ATOM RegisterWinClass();

		/*
		*InitInstance();
		*�������ھ������ʵ����
		*@return bool���ɹ�����true��ʧ�ܷ���false
		*/
		bool InitInstance();

		/*
		*GethInstance();
		*��ȡ����ʵ�����
		*/
		HINSTANCE GethInstance();

		/*
		*SetCursor();
		*��������꣬�����ڵ���init()֮ǰ���òŻ���Ч
		*@Param hCursor�������Դ���
		*/
		void SetCursor(HCURSOR hCursor);
		HCURSOR GetCursor();

		/*
		*SetTitle(LPWSTR name);
		*���������ڱ��⣬�����ڵ���init()֮ǰ���òŻ���Ч
		*LPWSTR name�����ڱ���
		*/
		void SetTitle(LPWSTR name);
		LPWSTR GetTitle();

		/*
		*SetIcon(LPWSTR name)
		*���ó���icon�������ڵ���init()֮ǰ���òŻ���Ч
		*@Param hIcon��icon��Դ���
		*/
		void SetIcon(HICON hIcon);
		HICON GetIcon();

		/*
		*���ó���Сͼ�꣬�����ڵ���init()֮ǰ���òŻ���Ч
		*@Param hIcon��icon��Դ���
		*/
		void SetIconSm(HICON hIcon);
		HICON GetIconSm();

		/*
		*SetMenuName(LPCWSTR name);
		*���ô��ڲ˵�������ڵ���init()֮ǰ���òŻ���Ч
		*@Param name���˵�������
		*/
		void SetMenuName(LPCWSTR name);

		/*
		*SetAccelTable(HACCEL hAccel);
		*���ÿ�ݼ���
		*/
		void SetAccelTable(HACCEL hAccel);
	private:
		cGameEngine();
		virtual ~cGameEngine();

		/*
		*������������Ϣѭ��
		*/
		void DoMainMsg();

		void SafeAddUi(cBaseUI* ui);

		HWND m_hWnd;

		//������Ϣ
		LPWSTR m_wError;

		//����UI�ؼ��б�
		std::list<cBaseUI*> m_uiList;

		std::list<UI_Event> m_evnetList;

		//������
		CLock m_lock;

		Mouse_Status m_mouseStatus;

		HINSTANCE m_hInst;

		LPWSTR m_title;

		HICON m_hIcon;

		HICON m_hIconSm;

		HCURSOR m_hCursor;

		LPCWSTR m_menuName;

		HACCEL m_hAccel;
	};
}