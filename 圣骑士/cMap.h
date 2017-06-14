#pragma once
#include<string>

enum Map_type
{
	Type_Null,
	Type_Brick,
	Type_Steel,
	Type_Box,
	Type_Door,
	Type_Born,
	Type_Box1,
	Type_Box2,
	Type_Energy,
};

/*
*cMap
*
*游戏地图类用于保存地图信息
*/
class cMap
{
public:
	cMap();

	/*
	*有参构造函数
	*
	*@Param：
	*	int row：地图行数
	*	int rank：地图列数
	*/
	cMap(const int& row, const int& rank);

	virtual ~cMap();

	/*
	*SetMap(const int& row,const int& rank);
	*
	*设置地图的行列数
	*
	*@Param：
	*	int row：地图行数
	*	int rank：地图列数
	*/
	void SetMap(const int& row, const int& rank);

	/*
	*at(const int& x,const int& y)
	*
	*获取地图在某行列的信息
	*
	*@return int:
	*	在该行列的地图信息
	*/
    Map_type& at(const int& row, const int& rank);

	/*
	*SetMapInfoAt(const int& row,const int& rank,Map_Type type)
	*
	*设置某行列的地图信息
	*
	*@Param:
	*	int row:行
	*	int rank：列
	*	Map_Type type：当前列的地图信息
	*/
	void SetMapInfoAt(const int& row, const int& rank, Map_type type);

	/*
	*LoadMapFromFile(const LPWSTR& fileName);
	*
	*从文件中加载地图信息
	*
	*@Param:
	*	LPWSTR fileName:文件名
	*@return bool:
	*	true：加载成功
	*	false：加载失败
	*/
	bool LoadMapFromFile(const std::string& fileName);

	/*
	*GetRow()
	*
	*获取地图行数
	*
	*@return int:
	*地图行数
	*/
	const int& GetRow() const;

	/*
	*GetRank()
	*
	*获取地图列数
	*
	*@return int：
	*	地图列数
	*/
	const int& GetRank() const;
private:
	/*
	*AllocMemory(const int& row, const int& rank)
	*
	*为地图数组分配内存
	*
	*@Param：
	*	int row：地图的行
	*	int rank：地图的列
	*/
	void AllocMemory(const int& row, const int& rank) noexcept;

	/*
	*FreeMemory(const int& row,const int& rank);
	*
	*释放地图资源
	*
	*@Param：
	*	int row：地图行数
	*	int rank：地图列数
	*/
	void FreeMemory(const int& row, const int& rank) noexcept;

	Map_type **m_MapInfo;

	int m_row;
	
	int m_rank;
};

