#pragma once

class cIDDialogBase
{
public:
	cIDDialogBase();

	cIDDialogBase(const UINT& IDD, HINSTANCE hInst = NULL, HWND hPWnd=NULL);

	virtual ~cIDDialogBase();

	virtual void Show() = 0;

	/*
	*initDialog(const HWND& hWnd)
	*
	*初始化窗口状态信息
	*
	*@Param：
	*	HWND hWnd：窗口句柄
	*@return bool：
	*	true：初始化成功
	*	false：初始化失败
	*/
	virtual bool initDialog(HWND hWnd);
protected:
	UINT m_IDD;

	HINSTANCE m_hInst;

	HWND m_PhWnd;

	HWND m_hWnd;
};

