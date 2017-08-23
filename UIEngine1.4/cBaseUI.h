#pragma once

#define _CALLFUNC(SEL_CALLFUNC) static_cast<MyEngine::SEL_CallFunc>(&SEL_CALLFUNC)

namespace MyEngine
{
	class cBaseUI;
	typedef void(*CallEeventBack)(void *param);
	typedef void(cBaseUI::*SEL_CallFunc)(void* Param);

	typedef struct _UI_Event
	{
		cBaseUI* Trigger;
		UINT_PTR EventId;
		cBaseUI* Handler;
		SEL_CallFunc CallProc;
		void* Param;
	}UI_Event;

	enum UI_Type
	{
		UI_Base,
		UI_Amination,
		UI_Button,
		UI_Circle,
		UI_Line,
		UI_Picture,
		UI_Polygon,
		UI_Rectangle,
		UI_Text,
		UI_Triangle,
	};

	/*
	cBaseUI
	����UI��Ļ���
	*/
	class cBaseUI
	{
	public:
		cBaseUI();
		/*
		�вι��캯��
		@Param :
			int x��ui�ؼ�x����
			int y : ui�ؼ�y����
		*/
		explicit cBaseUI(const int& x, const int& y);

		friend class cGameEngine;

		virtual ~cBaseUI();

		/*
		SetX(const int& x);
		����ui�ؼ�x����
		@Param ��
			int x���µ�x����
		*/
		virtual void SetX(const int& x);

		/*
		GetX()
		��ȡui�ؼ�x����
		@return const int&:
			ui�ؼ���ǰx����
		*/
		virtual const int& GetX() const;

		/*
		SetY(const int& y)
		����ui�ؼ�y����
		@Param ��
			int y:�µ�y����
		*/
		virtual void SetY(const int& y);

		/*
		GetY()
		��ȡui�ؼ���ǰy����
		@return int��
			��ǰy����
		*/
		virtual const int& GetY() const;

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
			ui�ؼ��ľ�������
		*/
		virtual const RECT GetRect() const=0;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
			HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) = 0;

		/*
		GetType()
		��ȡ�ؼ�����
		@return UI_Type��
			�ؼ�����
		*/
		virtual const UI_Type& GetType() const;

		/*
		GetID()
		��ȡ�ؼ�ID
		@return UINT_PTR:
			�ؼ�ID����δ����ID�ⷵ��-1��ֻ��ͨ��cGameEngine�����Ŀؼ������cGameEngine�Ŀؼ��Ż����ID
		*/
		virtual const UINT_PTR& GetID() const;
		virtual void SetUid(UINT_PTR Uid);

		void SetParent(cBaseUI* parent);
		cBaseUI* GetParent();
	protected:
		int m_x;
		int m_y;
		UI_Type m_type;
		UINT_PTR m_Uid = -1;

		//����Ƿ�ʹ������Դ���е���Դ
		BOOL m_isUsePool;

		cBaseUI* m_parent;
	};
}