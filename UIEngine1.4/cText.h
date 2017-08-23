#pragma once
#include"cBaseUI.h"

namespace MyEngine
{

	/*
	cText
	�ı�
	*/
	class cText:public cBaseUI
	{
	public:
		cText();

		/*
		���ι��캯��
		@Param 
			LPWSTR text���ı�����
		*/
		explicit cText(const LPWSTR& text);

		virtual ~cText();

		/*
		SetText(LPWSTR text)
		�����ı��ؼ�����
		@Param 
			LPWSTR text:�µ��ı�����
		*/
		void SetText(const LPWSTR& text);

		/*
		GetText()
		��ȡ�ı��ؼ�����
		const LPWSTR&��
			��ǰ�ı�����
		*/
		const LPWSTR& GetText() const;

		/*
		Append(LPWSTR text)
		��ǰ�ı�����ĩβ�������
		@return bool:
			true:��ӳɹ�
			false�����ʧ��
		*/
		bool Append(const LPWSTR& text);

		/*
		SetTextColor(const UINT& rgb)
		�����ı�������ɫ
		@Param 
			UINT rgb:�����õ��ı�������ɫ
		*/
		void SetTextColor(const UINT& rgb);

		/*
		GetTextColor()
		��ȡ��ǰ�ı�������ɫ
		@return UINT:
			��ǰ�ı���ɫ
		*/
		const UINT& GetTextColor() const;

		/*
		SetMode(const int& mode)
		�����ı�����ģʽ
		@Param:
			int mode���µ��ı�����ģʽ
		*/
		void SetMode(const int& mode);

		/*
		GetMode()
		��ȡ��ǰ�ı�����ģʽ
		@return int:
			��ǰ�ı�����ģʽ
		*/
		const int& GetMode() const;

		/*
		SetBgColor(UINT rgb)
		���õ�ǰ�ı�������ɫ
		@Param��
			UINT rgb���µ��ı�������ɫ
		*/
		void SetBgColor(UINT rgb);

		/*
		GetBgColor()
		��ȡ��ǰ�ı�������ɫ
		@return UINT:
			��ǰ�ı�������ɫ
		*/
		const UINT& GetBgColor() const;

		/*
		SetFont(const LPWSTR& font);
		��������
		@Param ��
			LPWSTR font���µ�����
		*/
		void SetFont(const LPWSTR& font);

		/*
		GetFont()
		��ȡ��ǰ����
		@return LPWSTR:
			��ǰ����
		*/
		const LPWSTR& GetFont() const;

		/*
		SetFontWidth(const int& width)
		����������
		@Param ��
			int width���µ�������
		*/
		void SetFontWidth(const int& width);

		/*
		GetFontWidth()
		��ȡ������
		@return int��
			��ǰ������
		*/
		const int& GetFontWidth() const;

		/*
		SetFontHeight(const int& height)
		��������߶�
		@Param ��
			int height���µ�����߶�
		*/
		void SetFontHeight(const int& height);

		/*
		GetFontHeight()
		��ȡ����߶�
		@return int��
			��ǰ����߶�
		*/
		const int& GetFonthHeight() const;

		/*
		SetWeight(const UINT& weight)
		������������
		@Param��
			UINT weight����������
		*/
		void SetWeight(const UINT& weight);

		/*
		GetWeight()
		��ȡ��������
		@return UINT��
			��������
		*/
		const UINT& GetWeight() const;

		/*
		SetnEscapement(const UINT& nEscapement);
		ָ����λ�������豸X��֮���һ���Ƕȣ���ʮ��֮һ��Ϊ��λ����λ����ƽ���������еĻ���
		@Param��
			UINT nEscapement���Ƕȴ�С
		*/
		void SetnEscapement(const UINT& nEscapement);

		/*
		GetnEscapement()
		��ȡ��λ�������豸X��֮��ĽǶ�
		@return UINT��
			�Ƕȴ�С
		*/
		const UINT& GetnEscapement() const;

		/*
		SetnOrientation(const UINT& nOrientation);
		ָ��ÿ���ַ��Ļ��ߺ��豸X��֮��ĽǶȡ�
		@Param��
			UINT nOrientation���Ƕȴ�С
		*/
		void  SetnOrientation(const UINT& nOrientation);

		/*
		GetnOrientation()
		��ȡÿ���ַ��Ļ��ߺ��豸X��֮��ĽǶȡ�
		@return UINT��
			�Ƕȴ�С
		*/
		const UINT& GetnOrientation() const;

		/*
		SetfdwItalic(const BOOL& b)
		���������Ƿ�Ϊб��
		@Param��
			BOOL b���Ƿ�Ϊб��
		*/
		void SetfdwItalic(const BOOL& b);

		/*
		GetfdwItalic()
		��ȡ�����Ƿ�Ϊб��
		@return BOOL��
			TRUE ��б��
			FALSE����б��
		*/
	     const BOOL& GetfdwItalic() const;

		 /*
		 SetfdwUnderline(const BOOL& b)
		 ���������Ƿ������»���
		 @Param:
			BOOL b���Ƿ������»���
		 */
		 void  SetfdwUnderline(const BOOL& b);

		 /*
		  GetfdwUnderline()
		  ��ȡ�ı��Ƿ����»���
		  @return BOOL��
			TRUE�����»���
			FALSE��û���»���
		 */
		 const BOOL& GetfdwUnderline() const;

		 /*
		 SetfdwStrikeOut(const BOOL& b)
		 ���������Ƿ�����ɾ����
		 @Param��
			BOOL b���Ƿ�����ɾ����
		 */
		 void SetfdwStrikeOut(const BOOL& b);

		 /*
		 GetfdwStrikeOut()
		 ��ȡ�ı��Ƿ���ɾ����
		 @return BOOL��
			TRUE����ɾ����
			FALSE��û��ɾ����
		 */
		 const BOOL& GetfdwStrikeOut() const;

		/*
		GetRect()
		��ȡui�ؼ�һ����������
		@return RECT��
		ui�ؼ��ľ�������
		*/
		virtual const RECT GetRect() const override;

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;
	private:
		LPWSTR m_Text;

		UINT m_textColor;

		int m_mode;

		int m_bgColor;

		LPWSTR m_font;

		int m_fontWidth;

		int m_fontHeight;

		//��������
		UINT m_weight;

		//ָ����λ�������豸X��֮���һ���Ƕ�
		//����ʮ��֮һ��Ϊ��λ����λ����ƽ���������еĻ��ߡ�
		UINT m_nEscapement;
		
		//ָ��ÿ���ַ��Ļ��ߺ��豸X��֮��ĽǶȡ�
		UINT m_nOrientation;
		
		//���������Ƿ�Ϊб��
		BOOL m_fdwItalic;

		//���������Ƿ������»���
		BOOL m_fdwUnderline;

		//���������Ƿ�����ɾ����
		BOOL m_fdwStrikeOut;

		HFONT m_hFont;
	};
}