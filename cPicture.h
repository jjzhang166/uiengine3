#pragma once
#include<string>
#include"cBaseUI.h"

namespace MyEngine
{

	class cPicture:public cBaseUI
	{
	public:
		cPicture();

		/*
		*有参构造函数
		@Param:
			HBITMAP hBitmap:位图句柄
		*/
		explicit cPicture(const HBITMAP& hBitmap);

		/*
		有参构造函数
		@Param：
			LPWSTR name：图片路径名
			int w：指定图片宽度,w=0为原图宽度
			int h：制定图片高度，h=0原图高度
		*/
		explicit cPicture(const LPWSTR& name,int w=0,int h=0);
		
		~cPicture();

		/*
		GetRect()
		获取ui控件一个矩形区域
		@return RECT：
		ui控件的矩形区域
		*/
		virtual const RECT&& GetRect() const  override;

		/*
		Draw(HDC hDc)
		绘制ui控件
		@Param:
		HDC hDc:设备DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		SetBitmap(const HBITMAP& hBitmap)
		指定一个位图句柄
		@Param：
			HBITMAP hBitmap：为图句柄
		*/
		void SetBitmap(const HBITMAP& hBitmap);

		/*
		SetBitmap(const LPWSTR& name,int w,int y)
		通过一个路径加载一个位图
		@Param：
			LPWSTR name:图片路径名
			int w：指定图片宽度，w=0原图宽度
			int h：制定图片高度，h=0原图高度
		*/
		void SetBitmap(const LPWSTR& name, int  w = 0, int  h = 0);

		/*
		GetBitmap()
		获取图片句柄
		@return
			图片句柄
		*/
		const HBITMAP& GetBitmap() const;
	private:
		/*
		SetPicConfig()
		设置图片信息
		*/
		void SetPicConfig();

		HBITMAP m_hBitmap;

		BOOL m_isLucency;

		UINT m_licencyRgb;

		BITMAP m_bmpConfig;
	};
}

