#pragma once
#include<string>
#include"cBaseUI.h"

namespace MyEngine
{

	/*
	cPicture
	ͼƬ
	*/
	class cPicture:public cBaseUI
	{
	public:
		cPicture();

		/*
		*�вι��캯��
		@Param:
			HBITMAP hBitmap:λͼ���
		*/
		explicit cPicture(const HBITMAP& hBitmap);

		/*
		�вι��캯��
		@Param��
			LPWSTR name��ͼƬ·����
			int w��ָ��ͼƬ���,w=0Ϊԭͼ���
			int h���ƶ�ͼƬ�߶ȣ�h=0ԭͼ�߶�
		*/
		explicit cPicture(const LPWSTR& name,int w=0,int h=0);

		/*
		ͨ��keyֵ��ʼ��ͼƬ
		*@Param:
		*	key:keyֵ
		*/
		explicit cPicture(const std::string key);
		
		virtual ~cPicture();

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
		ui�ؼ��ľ�������
		*/
		virtual const RECT GetRect() const  override;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		SetBitmap(const HBITMAP& hBitmap)
		ָ��һ��λͼ���
		@Param��
			HBITMAP hBitmap��Ϊͼ���
		*/
		void SetBitmap(const HBITMAP& hBitmap);

		/*
		SetBitmap(const LPWSTR& name,int w,int y)
		ͨ��һ��·������һ��λͼ
		@Param��
			LPWSTR name:ͼƬ·����
			int w��ָ��ͼƬ��ȣ�w=0ԭͼ���
			int h���ƶ�ͼƬ�߶ȣ�h=0ԭͼ�߶�
		*/
		void SetBitmap(const LPWSTR& name, int  w = 0, int  h = 0);

		/*
		*SetBitmapByKey(std::string key);
		*ͨ��keyֵ����ͼƬ
		*@Param 
		*	key��keyֵ
		*/
		void SetBitmapByKey(std::string key);

		/*
		GetBitmap()
		��ȡͼƬ���
		@return
			ͼƬ���
		*/
		const HBITMAP& GetBitmap() const;

		/*
		SetIsLucency(const BOOL& b)
		����ͼƬ�Ƿ����͸��ɫ
		@Param��
			BOOL b���Ƿ����͸��ɫ
		*/
		void SetIsLecency(const BOOL& b);

		/*
		IsLucnecy()
		ͼƬ�Ƿ����͸��ɫ
		@return BOOL��
			TRUE������͸��ɫ
			FALSE��������͸��ɫ
		*/
		const BOOL& IsLucency() const;

		/*
		SetLucencyColor(const UINT& rgb)
		����ͼƬ͸��rgbɫ
		@Param:
			UINT rgb:͸��ɫ
		*/
		void SetLucency(const UINT& rgb);

		/*
		GetLucencyColor()
		��ȡ͸��ɫ
		@return UINT��
			͸��ɫ
		*/
		const UINT& GetLucencyColor() const;

		/*
		GetConfig()
		��ȡͼƬ��Ϣ
		@return BITMAP��
			ͼƬ��ϸ��Ϣ
		*/
		const BITMAP& GetConfig() const;
	private:
		/*
		SetPicConfig()
		����ͼƬ��Ϣ
		*/
		void SetPicConfig();

		HBITMAP m_hBitmap;

		BOOL m_isLucency;

		UINT m_lucencyRgb;

		BITMAP m_bmpConfig;
	};
}