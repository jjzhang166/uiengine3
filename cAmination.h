#pragma once
#include<vector>
#include<initializer_list>
#include<string>
#include"cBaseUI.h"

namespace MyEngine
{

	class cAmination:public cBaseUI
	{
	public:
		cAmination();

		/*
		
		*/
		explicit cAmination(const std::initializer_list<LPWSTR>& initlist,int x=0,int y=0);
		
		~cAmination();

		/*
		
		*/
		void SetAmination(const std::initializer_list<PWSTR>& initlist,int x=0,int y=0);

		/*
		
		*/
		const std::vector<HBITMAP>& GetAmination() const;

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
		virtual bool Draw(HDC hDc)  override;
	private:
		void SetAmiConfig();
		std::vector<HBITMAP> m_Amination;
		BOOL m_isLucency;
		UINT m_lucencyRgb;
		BITMAP m_amiConfig;
	};
}

