#pragma once
#include"../UIEngine/cGameEngine.h"

class cMapEditer
{

public:
	cMapEditer();

	/*
	有参构造函数，初始化地图编辑窗口
	@Param：
		HWND hWnd：地图编辑窗口句柄
	*/
	cMapEditer(HWND hWnd);

	~cMapEditer();

	/*
	SetRowAndRank(const int& row,const int& rank)
	设置所需编辑地图的行列数
	@Param:
		int row：地图行数
		int rank：地图列数
	*/
	BOOL SetRowAndRabk(const int& row, const int& rank, const int& terrianSpecies);

	/*
	LoadMapResource(const LPWSTR& mapPath)
	加载地图位图资源
	@param：
		LPWSTR mapPath：位图资源路径
	*/
	BOOL LoadMapResource(const LPWSTR& mapPath);

	/*
	FromFileLoadMapConfig(const LPWSTR& fileName)
	从地图文件中加载地图配置
	@Param：
		LPWSTR fileName:文件路径名
	*/
	BOOL FromFileLoadMapConfig(const LPWSTR& fileName);

	/*
	CreateSplitLine()
	生成分隔线
	*/
	void CreateSplitLine();

	/*
	 SaveMapFile(const LPWSTR& fileName);
	 保存地图文件
	 @Param：
		LPWSTR fileName：文件名
	@return BOOL：
		TRUE：保存成功
		FALSE：保存失败
	*/
	BOOL SaveMapFile(const LPWSTR& fileName);

	/*
	MouseDown()
	鼠标按下
	*/
	void MouseDown();

	/*
	StartEdit(HWND hWnd)
	与有参构造函数，做同样的初始化操作
	@Param:
		HWND hWnd：编辑窗口句柄
	*/
	void StartEdit(HWND hWnd);
private:
	/*
	deleteMapInfo()
	释放地图信息数组内存
	*/
	bool deleteMapInfo(); 

	/*
	AutoChangeWndSize()
	根据地图资源自动调整窗口大小
	@Param:
		int mapWidth：地图宽度
		int mapHeight：地图高度
	*/
	BOOL AutoChangeWndSize(const int& mapWidth, const int& mapHeight);

	/*
	initMapInfo()
	初始化地图信息
	*/
	void initMapInfo();

	/*
	CreateTerrianRect(const POINT& pt)
	创建一个地形标志矩形
	@Param：
		POINT pt：创建点
		int w:矩形宽度
		int h:举行高度
		UINT fillColor：填充色
	*/
	void CreateTerrianRect(const POINT& pt,const int& w,const int& h,const UINT& fillColor);

	int m_row;

	int m_rank;

	LPWSTR m_MapPath;

	int m_terrianSpecies;

	int **m_mapInfo;

	int m_wndWidth;

	int m_wndHeight;

	int m_baseXSize;

	int m_baseYSize;

	MyEngine::cGameEngine m_Ui;

	std::list<MyEngine::cBaseUI*> m_terrianRect;

	std::list<MyEngine::cBaseUI*> m_splitLine;

	MyEngine::cPicture *m_MapImage;
};

