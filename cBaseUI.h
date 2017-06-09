#pragma once

namespace MyEngine
{

	class cBaseUI
	{
	public:
		cBaseUI();
		/*
		有参构造函数
		@Param :
			int x：ui控件x坐标
			int y : ui控件y坐标
		*/
		explicit cBaseUI(const int& x, const int& y);
		virtual ~cBaseUI();

		/*
		SetX(const int& x);
		设置ui控件x坐标
		@Param ：
			int x：新的x坐标
		*/
		void SetX(const int& x);

		/*
		GetX()
		获取ui控件x坐标
		@return const int&:
			ui控件当前x坐标
		*/
		const int& GetX() const;

		/*
		SetY(const int& y)
		设置ui控件y坐标
		@Param ：
			int y:新的y坐标
		*/
		void SetY(const int& y);

		/*
		GetY()
		获取ui控件当前y坐标
		@return int：
			当前y坐标
		*/
		const int& GetY() const;

		/*
		GetRect()
		获取ui控件一个矩形区域
		@return RECT：
			ui控件的矩形区域
		*/
		virtual const RECT&& GetRect() const=0;

		/*
		Draw(HDC hDc)
		绘制ui控件
		@Param:
			HDC hDc:设备DC
		*/
		virtual bool Draw(HDC hDc) = 0;
	private:
		int m_x;
		int m_y;
	};
}