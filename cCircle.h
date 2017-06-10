#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	/**
	cCircle
	圆
	*/
	class cCircle:public cBaseUI
	{
	public:
		cCircle();

		/*
		有参构造函数，初始圆的外接矩形区域
		@Param：
			int startx：左上角x坐标
			int starty：左上角y坐标
			int endx：右下角x坐标
			int endy：右下角y坐标
		*/
		explicit cCircle(const int& startx,const int& starty,const int& endx,const int& endy);

		/*
		有参构造函数，初始圆的外接矩形区域
		@Param：
			RECT rect：矩形区域
		*/
		explicit cCircle(const RECT& rect);

		~cCircle();

		/*
		SetCircleArea()
		设置圆的外接矩形区域
		@param:
			RECT rect：外界矩形
		*/
		void SetCircleArea(const RECT& rect);

		/*
		SetCircleArea()
		设置圆的外接矩形区域
		@Param：
			int startx：左上角x坐标
			int starty：左上角y坐标
			int endx：右下角x坐标
			int endy：右下角y坐标
		*/
		void SetCircleArea(const int& startx, const int& starty, const int& endx, const int& endy);

		/*
		GetHeight()
		获取圆的高度
		@return int：
			高度
		*/
		const int& GetHeight() const;

		/*
		GetWidth()
		获取圆的宽度
		@return int：
			宽度
		*/
		const int& GetWidth() const;

		/*
		SetLineColor(const UINT& rgb)
		设置线段颜色
		@param：
			UINT rgb：线段rgb色
		*/
		void SetLineColor(const UINT& rgb);

		/*
		GetLineColor()
		获取线段颜色
		@return UINT：
			线段rgb色
		*/
		const UINT& GetLineColor() const;

		/*
		SetIsFill(const bool& ok)
		设置是否填充圆形区域
		@Param：
			bool ok：是否填充
		*/
		void SetIsFill(const bool& ok);

		/*
		GetIsFill()
		获取是否填充
		@return bool：
			true：填充
			false：非填充
		*/
		const bool& GetIsFill() const;

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
		@return UINT:
			填充色
		*/
		const UINT& GetFillColor() const;

		/*
		SetLineStyle(const UINT& style)
		设置线段风格
		@param:
			UINT style：线段风格
		*/
		void SetLineStyle(const UINT& style);

		/*
		GetLineStyle()
		获取线段风格
		@return UINT：
			线段风格
		*/
		const UINT& GetLineStyle(const UINT& style);

		/*
		GetRect()
		获取ui控件一个矩形区域
		@return RECT：
		ui控件的矩形区域
		*/
		virtual const RECT GetRect() const override;

		/*
		Draw(HDC hDc)
		绘制ui控件
		@Param:
		HDC hDc:设备DC
		*/
		virtual bool Draw(HDC hDc) override;
	private:
		int m_height;

		int m_width;

		int m_lineWidth;

		UINT m_LineColor;

		bool m_isFill;

		UINT m_fillColor;

		UINT m_lineStyle;
	};
}