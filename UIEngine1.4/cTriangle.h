#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	/*
	cTriangle
	������
	*/
	class cTriangle:public cBaseUI
	{
	public:
		cTriangle();

		/*
		�вι��캯������ʼ�����������ε�������
		@Param��
			POINT p1:��һ����
			POINT p2���ڶ�����
			POINT p3����������
		*/
		explicit cTriangle(const POINT& p1, const POINT& p2, const POINT& p3);

		virtual ~cTriangle();

		/*
	    SetFirstPoint(const POINT& p1);
		���ù��������εĵ�һ����
		@Param ��
			POINT p1�������
		*/
		void SetFirstPoint(const POINT& p1);

		/*
		SetSecondPoint(const POINT& p2);
		���ù��������εĵڶ�����
		@Param ��
		POINT p1�������
		*/
		void SetSecondPoint(const POINT& p2);

		/*
		SetThirdPoint(const POINT& p3);
		���ù��������εĵ�������
		@Param ��
		POINT p1�������
		*/
		void SetThirdPoint(const POINT& p3);

		/*
		GetFirstPoint()
		��ȡ�����εĵ�һ����
		@return POINT��
			�����
		*/
		const POINT& GetFirstPoint() const;

		/*
		GetSecondPoint()
		��ȡ�����εĵڶ�����
		@return POINT��
			�����
		*/
		const POINT& GetSecondPoint() const;

		/*
		GetThirdPoint() 
		��ȡ�����εĵ�������
		@return POINT��
			�����
		*/
		const POINT& GetThirdPoint() const;

		/*
		SetLineColor(const UINT& rgb);
		�����߶���ɫ
		@Param��
			UINT rgb���߶�rgbɫ
		*/
		void SetLineColor(const UINT& rgb);

		/*
		GetLineColor() 
		��ȡ�߶���ɫ
		@return UINT��
			�߶���ɫ
		*/
		const UINT& GetLineColor() const;

		/*
		SetLineWidth(const int& width)
		�����߶ο��
		@return width��
			�߶ο��
		*/
		void SetLineWidth(const int& width);

		/*
		GetLineWidth()
		��ȡ�߶ο��
		@return int��
			�߶ο��
		*/
		const int& GetLineWidth() const;

		/*
		SetIsFill(const bool& ok)
		�����Ƿ��������������
		@Param:
			bool ok:�Ƿ����
		*/
		void SetIsFill(const bool& ok);

		/*
		IsFill()
		�Ƿ����
		@return bool��
			true�����
			false�������
		*/
		const bool& isFill() const;

		/*
		SetFillColor(const UINT& rgb)
		�������ɫ
		@Param��
			UINT rgb�����ɫ
		*/
		void SetFillColor(const UINT& rgb);

		/*
		GetFillColor()
		��ȡ���ɫ
		@return UINT��
			���ɫ
		*/
		const UINT& GetFillColor() const;

		/*
		SetLineStyle(const UINT&v style)
		�����߶η��
		@Param��
			UINT style:�߶η��
		*/
		void SetLineStyle(const UINT& style);

		/*
		GetLineStyle()
		��ȡ�߶η��
		@return UINT��
			�߶η��
		*/
		const UINT& GetLineStyle() const;

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
		virtual bool Draw(HDC hDc) override;
	private:
		POINT m_firstPoint;

		POINT m_secondPoint;

		POINT m_thirdPoint;

		UINT m_LineColor;

		int m_Linewidth;

		bool m_isFill;

		UINT m_FillColor;

		UINT m_lineStyle;

		HPEN m_hPen;

		HBRUSH m_hBrush;
	};
}