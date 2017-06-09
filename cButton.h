#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	class cButton :public cBaseUI
	{
	public:
		cButton();

		/*
		有参构造函数
		@Param:
			int width:按钮宽度
			int height：按钮高度
		*/
		explicit cButton(const LPWSTR& Name,const int& width,const int& height);

		virtual ~cButton();

		/*
		SetName()
		设置按钮名称
		@Param：
			LPWSTR name:按钮名
		*/
		void SetName(const LPWSTR& Name);

		/*
		GetName()
		获取按钮名
		@return LPWSTR：
			按钮名
		*/
		const LPWSTR& GetName() const;

		/*
		SetWidth(const int& width)
		设置按钮宽度
		@Param：
			int width：按钮宽度
		*/
		void SetWidth(const int& width);

		/*
		GetWidth()
		获取按钮宽度
		@return int：
			按钮宽度
		*/
		const int& GetWidth() const;

		/*
		SetHeight(const int& height)
		设置按钮高度
		@Param：
			int height：按钮高度
		*/
		void SetHeight(const int& Height);

		/*
		GetHeight()
		获取按钮高度
		@return int：
			按钮高度
		*/
		const int& GetHeight() const;

		/*
		SetBount(const int& n)
		设置按钮边框宽度
		@Param：
			int n：按钮边框宽度
		*/
		void SetnBount(const int& n);

		/*
		GetBount()
		获取按钮边框宽度
		@return int：
			按钮边框宽度
		*/
		const int& GetBount() const;

		/*
		SetBountColor(const UINT& rgb)
		设置边框颜色
		@Param：
			UINT rgb：边框颜色
		*/
		void SetBountColor(const UINT& rgb);

		/*
		GetBountColor()
		获取按钮边框颜色
		@return UINT：
			按钮边框颜色
		*/
		const UINT& GetBountColor() const;

		/*
		SetFirstColor(const UINT& rgb)
		设置按钮第一颜色
		@Param:
			UINT rgb:RGB色
		*/
		void SetfirstColor(const UINT& rgb);

		/*
		GetFirstColor()
		获取按钮第一颜色
		@return UINT:
			按钮第一颜色
		*/
		const UINT& GetfirstColor() const;

		/*
		SetSecondColor(const UINT& rgb)
		设置第二颜色
		@Param：
			UINT rgb：RGB色
		*/
		void SetsecondColor(const UINT& rgb);

		/*
		GetsecondColor()
		获取按钮第二颜色
		@return UINT：
			按钮第二颜色
		*/
		const UINT& GetsecondColor() const;

		/*
		GetRect()
		获取ui控件一个矩形区域
		@return RECT：
			ui控件的矩形区域
		*/
		virtual const RECT&& GetRect() const override;

		/*
		Draw(HDC hDc)
		绘制ui控件
		@Param:
			HDC hDc:设备DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		SetFont(const LPWSTR& font);
		设置字体
		@Param：
			LPWSTR font：字体
		*/
		void SetFont(const LPWSTR& font);

		/*
		GetFont()
		获取按钮文本字体
		@return LPWSTR：
			按钮文本字体
		*/
		const LPWSTR& GetFont() const;

		/*
		SetFontColor()
		设置字体颜色
		@Param：
			UINT rgb：rgb色
		*/
		void SetFontColor(const UINT& rgb);

		/*
		GetFontColor()
		获取字体颜色
		@return UINT：
			字体颜色
		*/
		const UINT& GetFontColor() const;
	private:
		LPWSTR m_Name;

		int m_width;

		int m_height;

		//边框宽度
		int m_nBount;

		UINT m_BountColor;

		//第一前景色
		UINT m_firstColor;

		//第二前景色
		UINT m_secondColor;

		LPWSTR m_font;

		UINT m_fontColor;
	};
}

