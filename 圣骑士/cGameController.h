#pragma once
#include"cMusicPlayer.h"
#include"../UIEngine/cGameEngine.h"
#include"cMap.h"
#include<map>

using namespace MyEngine;

enum EntryStatus
{
	Null_Entry,
	Menu_Entry,
	ReadFile_Entry,
	Game_Entry
};

enum MapScene
{
	Map_Censorship1,
	Map_Censorship2,
	Map_Censorship3,
	Map_Censorship4,
};

typedef struct RowRankInfo
{
	int row;
	int rank;

	bool operator <(const RowRankInfo& info) const
	{
		return row *rank < info.row*info.rank;
	}
}tagRowRankInfo;

class cGameController :public cMyTimer
{
	const int CLIENTX = 900;
	const int CLIENTY = 600;
	const int PANESIZE = 50;

public:
	enum  Time_Type
	{
		Time_Draw,
	};

public:
	cGameController();

	virtual ~cGameController();

	/*
	*OnTimer(int id,int iParam,string str);
	*
	*自cMyTimer继承而来的定时器处理处理回调函数
	*
	*@Param :
	*	int id:定时器id
	*	int iParam：定时器预留参数
	*	string str：定时器描述
	*
	*@return int：
	*	返回值为0时表示删除该定时器
	*/
	virtual int OnTimer(int id, int iParam, string str) override;

	/*
	*StartGame(HWND hWnd);
	*
	*开始游戏
	*
	*@Param：
	*	HWND hWnd：游戏窗口句柄
	*/
	void StartGame(const HWND& hWnd);

	/*
	*LButtonDown()
	*
	*鼠标坐标按下
	*/
	void LButtonDown();

	/*
	*LButtonUp()
	*
	*鼠标左键弹起
	*/
	void LButtonUp();

	/*
	*RButtonDown()
	*
	*鼠标右键按下
	*/
	void RButtonDown();

	/*
	*RButtonUp()
	*
	*鼠标右键弹起
	*/
	void RButtonUp();

	/*
	*KeyDown(LPARAM lParam)
	*
	*键盘按下消息
	*@Param:
	*	LPARAM lParam:事件详细信息
	*/
	void KeyDown(LPARAM lParam);

	/*
	*KeyUp(LPARAM wParam)
	*
	*键盘弹起消息
	*
	*@Param：
	*	LPARAM lParam：事件详细信息
	*/
	void KeyUp(LPARAM lParam);

	/*
	GetUIEngine()
	获取UI引擎对象指针
	@return cGameEngine*：
		UI引擎对象指针
	*/
	cGameEngine* GetUIEngine();

	/*
	EntryGame(EntryStatus entry)
	正式进入游戏
	@Param:
		EntryStatus entry：进入该页面的上一个页面
	*/
	void EntryGame(EntryStatus entry);

	/*
	EntrySelectView()
	进入选择视图
	@Param:
		EntryStatus entry：进入该页面的上一个页面
	*/
	void EntrySelectView(EntryStatus entry);

	/*
	EntryReadFileView
	进入读取存档界面
	@Param:
		EntryStatus entry：进入该页面的上一个页面
	*/
	void EntryReadFileView(const EntryStatus& entry);

	/*
	LoadMap(MapScene scene)
	加载地图
	@Param:
		MapScene scene：要加载的地图场景
	*/
	bool LoadMap(MapScene scene);
private:
	/*
	ReleaseLastViewResource(const EntryStatus& status);
	释放上一个界面的资源
	@Param：
		EntryStatus status：标识上一个界面
	@return BOOL：
		TRUE：释放成功
		FALSE：释放失败
	*/
    bool ReleaseLastViewResource(const EntryStatus& status);

	/*
	CreateMapResource();
	创建地图资源
	*/
	void CreateMapResource();

	/*
	ReleaseMapResource()
	释放地图资源
	@return BOOL：
		TRUE：释放成功
		FALSE：释放失败
	*/
	bool ReleaseMapResource();

	cMusicPlayer m_GameMusic;

	bool m_IsOpenMusic;

	unsigned m_gameVolume;

    cGameEngine* m_pUI;

	cMap m_mapInfo;

	cPicture* m_mapBg;

	std::list<cBaseUI*> m_MenuList;

	std::list<cBaseUI*> m_ReadFileList;

	//保存地图资源列表
	std::map<RowRankInfo, cBaseUI*> m_MapResource;
};

