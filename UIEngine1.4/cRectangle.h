#pragma once
#include"cBaseUI.h"

namespace MyEngine
{
	/*
	cRectangle
	����
	*/
	class cRectangle:public cBaseUI
	{
	public:
		cRectangle();

		/*
		*ͨ���������ĵ�Ϳ��߳�ʼ������
		*@Param center���������ĵ�
		*/
		explicit cRectangle(const POINT& center, const int& width = 2, const int& height = 2);

		virtual ~cRectangle();

		/*
		*SetRect(const POINT& center)
		*���þ������ĵ�
		*@Param center�����ĵ�
		*/
		void SetCenter(const POINT& center);

		/*
		*SetWidth(const int& width);
		*���þ��п��
		*@Param width�����
		*/
		void SetWidth(const int& width);
		const int& GetWidth();

		/*
		*SetHeight(const int& height);
		*���þ��и߶�
		*@Param height�����θ߶�
		*/
		void SetHeight(const int& height);
		const int& GetHeight();

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
			ui�ؼ��ľ�������
		*/
		virtual const RECT GetRect() const override;

		/*
		SetLineColor(const UINT& rgb)
		�����߶���ɫ
		@Param:
			UINT rgb���߶���ɫ
		*/
		void SetLineColor(const UINT& rgb);

		/*
		GetLineColor()
		��ȡ�߶���ɫ
		@return UINT:
			�߶���ɫ
		*/
		const UINT& GetLineColor() const;

		/*
		*SetLineWidth(const int& linewidth);
		*���ñ߿��ߵĿ��
		*/
		void SetLineWidth(const int& linewidth);
		const int& GetLineWidth();

		/*
		SetIsFill(const bool& ok)
		�����Ƿ�����������
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
		const bool& isFIll() const;

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
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;
	private:
		int m_width;

		int m_height;

		int m_Linewidth;

		UINT m_lineColor;

		bool m_isFill;

		UINT m_fillColor;

		UINT m_lineStyle;

		HPEN m_hPen;

		HBRUSH m_hBrush;
	};
}