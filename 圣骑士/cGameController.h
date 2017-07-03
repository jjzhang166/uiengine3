#pragma once
#include"cMusicPlayer.h"
#include<cGameEngine.h>
#include"cMap.h"
#include<map>
#include"cPlayer.h"

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
	*KeyDown(LPARAM lParam)
	*
	*键盘按下消息
	*@Param:
	*	WPARAM wParam:事件详细信息
	*/
	void KeyDown(WPARAM wParam);

	/*
	*KeyUp(LPARAM wParam)
	*
	*键盘弹起消息
	*
	*@Param：
	*	WPARAM wParam：事件详细信息
	*/
	void KeyUp(WPARAM wParam);

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

	/*
	CreatePlayer(Mapscene scene)
	创造一个玩家
	@Param :
		MapScene scene:地图场景
	@return cPlayer*:
		玩家对象指针
	*/
	cPlayer* CreatePlayer(MapScene scene);

	/*
	CanGo(tagPOINT pt,Dir_Type dir)
	判断玩家当前是否可以移动
	@Param：
		tagPOINT pt：玩家当前位置
		Dir_Type dir:移动方向
	@return bool：
		true：可以移动
		false：不可以移动
	*/
	bool CanGo(const tagPOINT& pt, Dir_Type dir);
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

	//出生点
	tagPOINT m_BornSite;

	cPlayer *m_Player;

	tagPOINT m_DoorSite;

	int m_delayWalk;

	int m_pressTimes;
};

