#pragma once
#include<list>
#include"cBaseUI.h"
#include"cMyTimer.h"

namespace MyEngine
{
	/*
	*class cSight
	*��Ұ������һ����Ұ������ǰ���ܿ������������������
	*/
	class cSight:public cMyTimer,public cBaseUI
	{
	public:
		cSight();
		virtual ~cSight();
		virtual const RECT GetRect() const override;

		/*
		*Draw(HDC hDc)
		*����ui�ؼ�
		*@Param:
		*HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		*addChild(cBaseUI* ui);
		*����ӽڵ�
		*@Param ui*���ӽڵ����ָ��
		*/
		void addChild(cBaseUI* ui);

		virtual void SetUid(UINT_PTR uid) override;
		virtual int OnTimer(int id, int iParam, string str) override;

		/*
		*RemoveChild(cBaseUI* ui);
		*�Ƴ��ӽڵ�
		*@Param child���ӽڵ�ָ�����
		*@return bool���ɹ�����true�����򷵻�false
		*/
		bool RemoveChild(cBaseUI* child);

		/*
	    *RemoveAllChild();
		*�Ƴ������ӽڵ�
		*/
		void RemoveAllChild();
	private:
		/*
		*�ͷ���Դ
		*/
		void Release();

		std::list<cBaseUI*> m_uiList;

	protected:
		CLock m_lock;
	};
}