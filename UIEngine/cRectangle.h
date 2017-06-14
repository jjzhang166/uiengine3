#pragma once
#include"cBaseUI.h"

namespace MyEngine
{
	/*
	cRectangle
	矩形
	*/
	class cRectangle:public cBaseUI
	{
	public:
		cRectangle();

		/*
		有参构造函数，初始化矩形区域
		@Param：
			RECT rect：矩形区域
		*/
		explicit cRectangle(const RECT& rect);

		/*
		有参构造函数，初始化矩形区域
		@Param:
			int left：矩形区域最左边
			int right：矩形区域最右边
			int top：矩形区域最上边
			int bottom：矩形区域最下边
		*/
		cRectangle(const int& left, const int& right, const int& top, const int& bottom);

		~cRectangle();

		/*
		SetRect(const RECT& rect)
		设置矩形区域
		@Param：
			RECT rect：矩形区域
		*/
		void SetRect(const RECT& rect);

	
		/*
		SetRect(const int& left, const int& right, const int& top, const int& bottom);
		设置矩形区域
		@Param:
			int left：矩形区域最左边
			int right：矩形区域最右边
			int top：矩形区域最上边
			int bottom：矩形区域最下边
		*/
		void SetRect(const int& left, const int& right, const int& top, const int& bottom);

		/*
		GetRect()
		获取ui控件一个矩形区域
		@return RECT：
			ui控件的矩形区域
		*/
		virtual const RECT GetRect() const override;

		/*
		GetWidth()
		获取矩形宽度
		@return int：
			矩形宽度
		*/
		int GetWidth() const;

		/*
		GetHeight()
		获取矩形高度
		@return int：
			高度
		*/
		int GetHeight() const;

		/*
		SetLineColor(const UINT& rgb)
		设置线段颜色
		@Param:
			UINT rgb：线段颜色
		*/
		void SetLineColor(const UINT& rgb);

		/*
		GetLineColor()
		获取线段颜色
		@return UINT:
			线段颜色
		*/
		const UINT& GetLineColor() const;

		/*
		SetIsFill(const bool& ok)
		设置是否填充矩形区域
		@Param:
			bool ok:是否填充
		*/
		void SetIsFill(const bool& ok);

		/*
		IsFill()
		是否填充
		@return bool：
			true：填充
			false：非填充
		*/
		const bool& isFIll() const;

		/*
		SetFillColor(const UINT& rgb)
		设置填充色
		@Param：
			UINT rgb：填充色
		*/
		void SetFillColor(const UINT& rgb);

		/*
		GetFillColor()
		获取填充色
		@return UINT：
			填充色
		*/
		const UINT& GetFillColor() const;

		/*
		SetLineStyle(const UINT&v style)
		设置线段风格
		@Param：
			UINT style:线段风格
		*/
		void SetLineStyle(const UINT& style);

		/*
		GetLineStyle()
		获取线段风格
		@return UINT：
			线段风格
		*/
		const UINT& GetLineStyle() const;

		/*
		Draw(HDC hDc)
		绘制ui控件
		@Param:
		HDC hDc:设备DC
		*/
		virtual bool Draw(HDC hDc) override;
	private:
		RECT m_rect;

		int m_Linewidth;

		UINT m_lineColor;

		bool m_isFill;

		UINT m_fillColor;

		UINT m_lineStyle;

		HPEN m_hPen;

		HBRUSH m_hBrush;
	};
}