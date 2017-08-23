#pragma once
#include"cBaseUI.h"

namespace MyEngine
{
	/*
	cLine
	ֱ��
	*/
	class cLine:public cBaseUI
	{
	public:
		cLine();

		/*
		�вι��캯������ʼ��ֱ������㼰����һЩ����
		@Param��
			POINT start������ֱ�ߵĵ�һ����
			POINT end������ֱ�ߵĵڶ�����
		*/
		explicit cLine(const POINT& start, const POINT& end);

		/*
		�вι��캯������ʼ��ֱ������㼰����һЩ����
		@Param��
			int startx����һ�����x����
			int starty����һ�����y����
			int endx���ڶ������x����
			int endy���ڶ������y����
		*/
		explicit cLine(const int& startx, const int& starty, const int& endx, const int& endy);

		virtual ~cLine();

		/*
		SetStartPoint(const POINT&  start)
		���ù���ֱ�ߵĵ�һ�������
		@Param��
			POINT start����һ��������ֵ
		*/
		void SetStartPoint(const POINT& start);

		/*
		SetEndPoint(const POINT& end)
		���ù���ֱ�ߵĵڶ��������
		@param��
			POINT end���ڶ���������ֵ
		*/
		void SetEndPoint(const POINT& end);

		/*
		GetStartPoint()
		��ȡ��һ��������ֵ
		@return POINT��
			��һ��������ֵ
		*/
		const POINT& GetStartPoint() const;

		/*
		GetEndPoint()
		��ڶ���������ֵ
		@return POINT��
			�ڶ���������ֵ
		*/
		const POINT& GetEndPoint() const;

		/*
		SetStartPoint(const POINT&  start)
		���ù���ֱ�ߵĵ�һ�������
		@Param��
			int x����һ��������x����
			int y����һ��������y����
		*/
		void SetStartPoint(const int& x, const int& y);

		/*
		SetEndPoint(const POINT& end)
		���ù���ֱ�ߵĵڶ��������
		@param��
			int x���ڶ���������x����
			int y���ڶ���������y����
		*/
		void SetEndPoint(const int& x, const int& y);

		/*
		SetWidht(const int& w)
		����ֱ�߿��
		@Param ��
			int w��ֱ�߿��
		*/
		void SetWidth(const int& w);

		/*
		GetWidth()
		��ȡֱ�߿��
		@return int��
			ֱ�߿��
		*/
		const int& GetWidth() const;

		/*
		SetColor(const UINT& rgb)
		����ֱ����ɫ
		@Param��
			UINT rgb��ֱ����ɫrgbɫ
		*/
		void SetColor(const UINT& rgb);

		/*
		GetColor()
		��ȡֱ����ɫ
		@return UINT��
			ֱ����ɫ
		*/
		const UINT& GetColor() const;

		/*
		SetStyle(const UINT& style)
		����ֱ�߷��
		@Param��
			UINT style��ֱ�߷��
		*/
		void SetStyle(const UINT& style);

		/*
		GetStyle()
		��ȡֱ�߷��
		@return UINT��
			ֱ�߷��
		*/
		const UINT& GetStyle() const;

	   /*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
			HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;


		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
		ui�ؼ��ľ�������
		*/
		virtual const RECT GetRect() const override;
	private:
		POINT m_startPoint;

		POINT m_endSPoint;

		int m_width;

		UINT m_color;

		UINT m_style;

		HPEN m_hPen;
	};
}