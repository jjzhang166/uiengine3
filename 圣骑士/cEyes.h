#pragma once

enum Eyes_Type
{
	Type_Eyes,
	Type_Player,
	Type_Npc,
	Tyep_Monster,
};

enum Dir_Type
{
	Dir_Left,
	Dir_Right,
	Dir_Up,
	Dir_Down,
};


class cEyes
{
public:
	cEyes();
	virtual ~cEyes();

	/*
	*SetPos(const tagPOINT& pos)
	*
	*设置当前位置
	*
	*@Param:
	*	tagPOINT pos：设置的当前位置
	*/
	virtual void SetPos(const tagPOINT& pos);

	/*
	*SetPos(const tagPOINT&& pos)
	*
	*移动语义的SetPos()
	*/
	virtual void SetPos(const tagPOINT&& pos);

	/*
	*GetPos()
	*
	*获取当前位置
	*
	*@return tagPOINT：
	* 当前位置
	*/
	virtual const tagPOINT& GetPos() const;

	/*
	*Move()
	*
	*定义如何移动
	*
	*@return int:
	* 由子类来决定如何返回
	*/
	virtual int move(Dir_Type dir,bool b) = 0;

	/*
	*SetLife(const int& life);
	*
	*设置生命值
	*
	*@Param：
	*	int life：新的生命值
	*/
	virtual void SetLife(const int& life);

	/*
	*SetLife(const int&& life);
	*
	*移动语义的SetLife()
	*
	*@Param：
	* int life:新的生命值
	*/
	virtual void SetLife(const int&& life);

	/*
	*GetLife()
	*
	*获取当前生命值
	*
	*@return int：
	*	当前的生命值
	*/
	virtual const int& GetLife() const;

	/*
	*SetFps(const unsigned& fps);
	*
	*设置帧率
	*
	*@Param：
	*	unsigned fps：帧率
	*/
	virtual void SetFps(const unsigned& fps);

	/*
	*SetFps(const unsigned&& fps);
	*
	*移动语义的SetFps（）
	*/
	virtual void SetFps(const unsigned&& fps);

	/*
	*GetFps() 
	*
	*获取帧率
	*
	*@return unsigned：
	*	帧率
	*/
	virtual const unsigned& GetFps() const;

	/*
	*SetMaxFps(const unsigned& fps);
	*
	*设置最大帧率
	*
	*@Param：
	*	unsigned fps：最大帧率
	*/
	virtual void SetMaxFps(const unsigned& fps);

	/*
	*SetMaxFps(const unsigned&& fps);
	*
	*移动语义的SetMaxFps（）
	*/
	virtual void SetMaxFps(const unsigned&& fps);

	/*
	*GetMaxFps()
	*
	*获取最大帧率
	*
	*@return unsigned：
	*	最大帧率
	*/
	virtual const unsigned& GetMaxFps() const;

	/*
	*GetType()
	*
	*获取自身类型
	*
	*@return Eyes_Type:
	*	自身类型
	*/
	virtual const Eyes_Type& GetType();

	/*
	GetDir()
	获取方向
	@return Dir_Type：
		物体方向
	*/
	virtual const Dir_Type& GetDir() const;
protected:
	//当前位置
	tagPOINT m_pos;

	//生命值
	int m_life;

	//帧率
	unsigned m_fps;

	//最大帧率
	unsigned m_maxFps;

	Eyes_Type m_type;

	Dir_Type m_dir;
};

