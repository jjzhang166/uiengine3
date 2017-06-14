#pragma once
#include<vector>
#include<initializer_list>
#include<string>
#include"cBaseUI.h"

namespace MyEngine
{

	/*
	cAmination
	动画
	*/
	class cAmination:public cBaseUI
	{
	public:
		cAmination();

		/*
		构造函数，初始化的动画资源，并自定其宽度和高度也可以使用图片本身默认宽高
		@Param：
			std::initializer_list<LPWSTR> initList:动画资源路径列表
			int w：动画宽度
			int h：动画高度
		*/
		explicit cAmination(const std::initializer_list<LPWSTR>& initlist,const int& w=0,const int& h=0);
		
		~cAmination();

		/*
		SetAmination(const std::initializer_list<LPWSTR>& initlist,const int& x,const int& y)
		初始化的动画资源，并自定义其宽度和高度也可以使用图片本身默认宽高
		@Param：
			std::initializer_list<LPWSTR> initlist:动画资源路径列表
			int w：动画宽度
			int h：动画高度
		*/
		void SetAmination(const std::initializer_list<LPWSTR>& initlist,const int& w=0,const int& h=0);

		/*
		GetAmination()
		获取动画资源位图句柄列表
		@return std::vector<HBITMAP>：
			动画资源位图句柄列表
		*/
		const std::vector<HBITMAP>& GetAmination() const;

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
		virtual bool Draw(HDC hDc)  override;

		/*
		SetIsLucency(const BOOL& b)
		设置动画是否具有透明色
		@Param：
			BOOL b：TRUE表示具有透明色FALSE表示不具有透明色
		*/
		void SetIsLucnecy(const BOOL& b);

		/*
		GetIsLucency()
		获取动画是否具有·透明
		@return BOOL：
			TRUE：动画具有透明色
			FALSE：动画不具有透明色
		*/
		const BOOL& GetIsLucency() const;

		/*
		SetLucencyColor()
		设置透明色
		@Param：
			UINT rgb：透明rgb色
		*/
		void SetLucnecyColor(const UINT& rgb);

		/*
		GetLucencyColor()
		获取透明色
		@return UINT：
			透明rgb色
		*/
		const UINT& GetLucnecyColor() const;

		/*
		GetConfig()
		获取动画信息
		@return BITMAP：
			动画图片信息
		*/
		const BITMAP& GetConfig() const;

		/*
		IncCurFrame()
		自增当前帧
		*/
		void IncFrame();

		/*
		SetAutoRun(const BOOL& b)
		设置是否自动播放
		@Param：
			BOOL b：是否自动播放
		*/
		void SetAutoRun(const BOOL& b);

		/*
		IsAutoRun()
		是否自动播放
		*/
		const BOOL& IsAutoRun() const;
	private:
		/*
		SetAmiConfig()
		设置动画配置
		*/
		void InitAmiConfig();

		/*
		DeleteAmination()
		删除动画位图资源
		*/
		void DeleteAmination();
	
		//动画位图资源句柄列表
		std::vector<HBITMAP> m_Amination;

		//动画是否有透明色
		BOOL m_isLucency;

		//动画透明rgb色
		UINT m_lucencyRgb;

		//保存位图句柄信息
		BITMAP m_amiConfig;

		unsigned m_maxFrame;

		unsigned m_curFrame;

		BOOL m_isAutoRun;
	};
}