#pragma once
#include<list>
#include"cBaseUI.h"

namespace MyEngine
{
	/*
	*class cSight
	*视野，管理一个视野（即当前所能看到的所有事物）的内容
	*/
	class cSight:public cBaseUI
	{
	public:
		cSight();
		virtual ~cSight();
		virtual const RECT GetRect() const override;

		/*
		*Draw(HDC hDc)
		*绘制ui控件
		*@Param:
		*HDC hDc:设备DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		*addChild(cBaseUI* ui);
		*添加子节点
		*@Param ui*：子节点对象指针
		*/
		void addChild(cBaseUI* ui);
	private:
		std::list<cBaseUI*> m_uiList;
	};
}