#pragma once
#include<vector>
#include<initializer_list>
#include<string>
#include"cBaseUI.h"

namespace MyEngine
{

	/*
	cAmination
	����
	*/
	class cAmination:public cBaseUI
	{
	public:
		cAmination();

		/*
		�вι��캯��
		��һ��ͼƬ��ʼ������
		@Param��
			LPWSTR name:ͼƬ·����
			int smallRow��Сͼ����
			int smallRank��Сͼ����
			int w���������
			int h�������߶�
		*/
		cAmination(const LPWSTR& Name,const int& smallRow,const int& smallRank,const int& w = 0, const int& h = 0);

		/*
		*ͨ����Դkeyֵ��ʼ����ͼƬ����
		*@Param:
		*	key:keyֵ
		*	int smallRow��Сͼ����
		*	int smallRank��Сͼ����
		*/
		cAmination(const std::string& key, const int& smallRow, const int& smallRank);

		/*
	    *ͨ����Դkeyֵ��ʼ����ͼƬ����
		*@Param:
		*	key��keyֵ
		*/
		cAmination(const std::string& key);

		/* 
		�вι��캯��
		��һ��ͼƬ��ʼ������
		@Param��
			HBITMAP hbitmap:λͼ���
			int smallRow��Сͼ����
			int smallRank��Сͼ����
	    */
		cAmination(HBITMAP hbitmap, const int& smallRow, const int& smallRank);

		/*
		���캯������ʼ���Ķ�����Դ�����Զ����Ⱥ͸߶�Ҳ����ʹ��ͼƬ����Ĭ�Ͽ��
		@Param��
			std::initializer_list<LPWSTR> initList:������Դ·���б�
			int w���������
			int h�������߶�
		*/
		explicit cAmination(const std::initializer_list<LPWSTR>& initlist,const int& w=0,const int& h=0);
		
		virtual ~cAmination();

		/*
		SetAmination(const std::initializer_list<LPWSTR>& initlist,const int& x,const int& y)
		��ʼ���Ķ�����Դ�����Զ������Ⱥ͸߶�Ҳ����ʹ��ͼƬ����Ĭ�Ͽ��
		@Param��
			std::initializer_list<LPWSTR> initlist:������Դ·���б�
			int w���������
			int h�������߶�
		*/
		void SetAmination(const std::initializer_list<LPWSTR>& initlist,const int& w=0,const int& h=0);

		/*
		*SetAmination(const std::string key);
		*ͨ��keyֵ���ö�ͼƬ����
		*@Param key��keyֵ
		*/
		void SetAmination(const std::string key);

		/*
		*SetAmination(const std::string key, const int& smallRow, const int& smallRank);
		*ͨ��keyֵ���õ�ͼƬ����
		*@Param��
		*	key��keyֵ
		*	int smallRow��Сͼ����
		*	int smallRank��Сͼ����
		*/
		void SetAmination(const std::string key, const int& smallRow, const int& smallRank);

		/*
		*SetAmination(const LPWSTR& name, const int& smallRow, const int& smallRank);
		*ͨ��һ��ͼƬ���ö���
		*@Param��
		*	name��ͼƬ·����
		*	int smallRow��Сͼ����
		*	int smallRank��Сͼ����
		*/
		void SetAmination(const LPWSTR& name, const int& smallRow, const int& smallRank);

		/*
		GetAmination()
		��ȡ������Դλͼ����б�
		@return std::vector<HBITMAP>��
			������Դλͼ����б�
		*/
		const std::vector<HBITMAP>& GetAmination() const;

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
		ui�ؼ��ľ�������
		*/
		virtual const RECT GetRect() const override;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc)  override;

		/*
		SetIsLucency(const BOOL& b)
		���ö����Ƿ����͸��ɫ
		@Param��
			BOOL b��TRUE��ʾ����͸��ɫFALSE��ʾ������͸��ɫ
		*/
		void SetIsLucnecy(const BOOL& b);

		/*
		GetIsLucency()
		��ȡ�����Ƿ���С�͸��
		@return BOOL��
			TRUE����������͸��ɫ
			FALSE������������͸��ɫ
		*/
		const BOOL& GetIsLucency() const;

		/*
		SetLucencyColor()
		����͸��ɫ
		@Param��
			UINT rgb��͸��rgbɫ
		*/
		void SetLucnecyColor(const UINT& rgb);

		/*
		GetLucencyColor()
		��ȡ͸��ɫ
		@return UINT��
			͸��rgbɫ
		*/
		const UINT& GetLucnecyColor() const;

		/*
		GetConfig()
		��ȡ������Ϣ
		@return BITMAP��
			����ͼƬ��Ϣ
		*/
		const BITMAP& GetConfig() const;

		/*
		IncCurFrame()
		������ǰ֡
		@Param:
			int curFrame:���õ�ǰ֡
		*/
		void IncFrame(const int& curFrame = 0);

		/*
		SetAutoRun(const BOOL& b)
		�����Ƿ��Զ�����
		@Param��
			BOOL b���Ƿ��Զ�����
		*/
		void SetAutoRun(const BOOL& b);

		/*
		IsAutoRun()
		�Ƿ��Զ�����
		*/
		const BOOL& IsAutoRun() const;

		/*
		SetSmallRowAndRank(const int& row,const int& rank)
		���õ���������һ��ͼƬ��ʱָ��Сͼ��������
		@Param:
			int row��Сͼ����
			int rank��Сͼ����
		*/
		void SetSmallRowAndRank(const int& row, const int& rank);

		/*
		SetCurFrame(const int& curFrame);
		���õ�ǰ֡,һ�㲻��Ҫ�õ���������������
		@Param: 
			int curFrame;
		*/
		void  SetCurFrame(const int& curFrame);

		/*
		GetCurFrame()
		��ȡ��ǰ֡
		@return int:
			��ǰ֡
		*/
		const int& GetCurFrame() const;
	private:
		/*
		SetAmiConfig()
		���ö�������
		*/
		void InitAmiConfig();

		/*
		DeleteAmination()
		ɾ������λͼ��Դ
		*/
		void DeleteAmination();
	
		//����λͼ��Դ����б�
		std::vector<HBITMAP> m_Amination;

		//�����Ƿ���͸��ɫ
		BOOL m_isLucency;

		//����͸��rgbɫ
		UINT m_lucencyRgb;

		//����λͼ�����Ϣ
		BITMAP m_amiConfig;

		unsigned m_maxFrame;

		unsigned m_curFrame;

		BOOL m_isAutoRun;

		//ָ���Ƿ�ֻ��һ��ͼ
		BOOL m_isOne;

		//��ֻ��һ��ͼƬʱСͼ����
		int m_smallRow;

		//��ֻ��һ��ͼƬʱСͼ����
		int m_smallRank;
	};
}