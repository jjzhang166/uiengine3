#pragma once
#include"cBaseUI.h"
#include<vector>
#include<initializer_list>

namespace MyEngine {


	/*
	Polygon
	�Ա���
	���ݶ���λ���ѭ�����������γɶ����
	*/
	class cPolygon:public cBaseUI
	{
	public:
		cPolygon();

		/*
		�вι��캯������ʼ������λ���
		@Param��
			std::initializer_list<POINT> pointList:����λ����б����ɶ���ε������
		*/
		explicit cPolygon(const std::initializer_list<POINT> pointList);

		virtual ~cPolygon();

		virtual const RECT GetRect() const override;

		/*
		SetPolygon(const std::initializer_list<POINT>& pointList)
		���ù��ɶ���еĻ���
		@Param��
			std::initializer_list<POINT> pointList:����λ����б����ɶ���ε������
		*/
		void SetPolygon(const std::initializer_list<POINT>& pointList);

		/*
		AlterOnePoint(const POINT& oldPoint,cosnt POINT& newPoint);
		�޸Ķ���е�ĳһ�����
		@Param��
			POINT oldPoint ���ɵ������
			POINT newPoint���µ������
		*/
		void AlterOnePoint(const POINT& oldPoint, const POINT& newPoint);

		/*
		Draw(HDC hDc)
		����ui�ؼ�
		@Param:
		HDC hDc:�豸DC
		*/
		virtual bool Draw(HDC hDc) override;

		/*
		SetWidth(const unsigned& width)
		���ö���α�Ե���
		@Param��
			unsigned width������α�Ե���
		*/
		void SetLineWidth(const unsigned& width);

		/*
		GetWidth()
		��ȡ����α�Ե���
		@return unsigned��
			����α�Ե���
		*/
		const unsigned& GetLineWidth() const;

		/*
		SetLineColor(const UINT& rgb);
		���ö���λ�����ɫ
		@Param��
			UINT rgb������rgbɫ
		*/
		void SetLineColor(const UINT& rgb);

		/*
		GetLineColor()
		��ȡ����rgbɫ
		@return UINT��
			rgbɫ
		*/
		const UINT& GetLineColor() const;

		/*
		*SetLineStyle();
		*�����������
		*@Param:
		*	style:�������
		*/
		void SetLineStyle(const UINT& style);
		const UINT& GetLineStyle();

		/*
		SetFill(cosnt BOOL& b)
		�����Ƿ��������
		@Param��
			BOOL b:TRUE��ʾ��䣬FALSE��ʾ�����
		*/
		void SetFill(const BOOL& b);

		/*
		IsFill()
		�ж��Ƿ�Ϊ�������
		@return BOOL��
			TRUE:Ϊ�������
			FALSE����Ϊ�������
		*/
		const BOOL& IsFill() const;

		/*
		SetFillColor(cosnt UINT& rgb)
		�������ɫ
		@Param��
			UINT rgb�����rgbɫ
		*/
		void SetFillColor(const UINT& rgb);

		/*
		GetFillColor()
		��ȡ���ɫ
		@return UINT��
			���ɫ
		*/
		const UINT& GetFillColor() const;
	private:
		std::vector<POINT> m_pointList;

		unsigned m_sideNums;

		unsigned m_lineWidth;

		UINT m_lineColor;
		
		UINT m_lineStyle;

		BOOL m_isFill;

		UINT m_fillColor;

		HBRUSH m_hBrush;

		HPEN m_hPen;
	};
}