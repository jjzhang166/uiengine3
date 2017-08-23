#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	/**
	cCircle
	Բ
	*/
	class cCircle:public cBaseUI
	{
	public:
		cCircle();

		/*
		�вι��캯������ʼԲ����Ӿ�������
		@Param��
			center:Բ��
			radius���뾶
		*/
		explicit cCircle(const POINT& center, const UINT& radius);

		virtual ~cCircle();

		/*
		m_radius�뾶��getter��setter����
		*/
		void SetRaduis(const UINT& radius);
		const UINT& GetRadius();

		/*
		m_centerԲ�ĵ�getter��setter
		*/
		void SetCenter(const POINT& center);
		const POINT GetCenter();

		/*
		SetCircleArea()
		����Բ����Ӿ�������
		@param:
			center:Բ��
			radius���뾶
		*/
		void SetCircle(const POINT& center,const UINT& radius);

		/*
		SetLineColor(const UINT& rgb)
		�����߶���ɫ
		@param��
			UINT rgb���߶�rgbɫ
		*/
		void SetLineColor(const UINT& rgb);

		/*
		GetLineColor()
		��ȡ�߶���ɫ
		@return UINT��
			�߶�rgbɫ
		*/
		const UINT& GetLineColor() const;

		/*
		SetIsFill(const bool& ok)
		�����Ƿ����Բ������
		@Param��
			bool ok���Ƿ����
		*/
		void SetIsFill(const bool& ok);

		/*
		GetIsFill()
		��ȡ�Ƿ����
		@return bool��
			true�����
			false�������
		*/
		const bool& GetIsFill() const;

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
		@return UINT:
			���ɫ
		*/
		const UINT& GetFillColor() const;

		/*
		SetLineStyle(const UINT& style)
		�����߶η��
		@param:
			UINT style���߶η��
		*/
		void SetLineStyle(const UINT& style);

		/*
		GetLineStyle()
		��ȡ�߶η��
		@return UINT��
			�߶η��
		*/
		const UINT& GetLineStyle(const UINT& style);

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
		int m_lineWidth;

		UINT m_LineColor;

		bool m_isFill;

		UINT m_fillColor;

		UINT m_lineStyle;

		HBRUSH m_hBrush;

		HPEN m_hPen;

		//�뾶
		UINT m_radius;
	};
}