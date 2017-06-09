#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	class cLine:public cBaseUI
	{
	public:
		cLine();

		/*

		*/
		explicit cLine(const POINT& start, const POINT& end);

		/*

		*/
		cLine(const int& startx, const int& starty, const int& endx, const int& endy);
		~cLine();

		/*

		*/
		void SetStartPoint(const POINT& start);

		/*

		*/
		void SetEndPoint(const POINT& end);

		/*

		*/
		const POINT& GetStartPoint() const;

		/*

		*/
		const POINT& GetEndPoint() const;

		/*

		*/
		void SetStartPoint(const int& x, const int& y);

		/*

		*/
		void SetEndPoint(const int& x, const int& y);

		/*

		*/
		void SetWidth(const int& w);

		/*

		*/
		const int& GetWidth() const;

		/*

		*/
		void SetColor(const UINT& rgb);

		/*

		*/
		const UINT& GetColor() const;

		/*
		
		*/
		void SetStyle(const UINT& style);

		/*
		
		*/
		const UINT& GetStyle() const;

	   /*
		Draw(HDC hDc)
		绘制ui控件
		@Param:
			HDC hDc:设备DC
		*/
		virtual bool Draw(HDC hDc) override;


		/*
		GetRect()
		获取ui控件一个矩形区域
		@return RECT：
		ui控件的矩形区域
		*/
		virtual const RECT&& GetRect() const override;
	private:
		POINT m_startPoint;

		POINT m_endSPoint;

		int m_width;

		UINT m_color;

		UINT m_style;
	};
}