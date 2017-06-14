#pragma once
#include<list>

class cMusicPlayer
{
	enum Time_Type
	{
		Time_Check,
	};

public:
	cMusicPlayer();
	virtual ~cMusicPlayer();

	/*
	*PlayBgSound(const LPWSTR& path)
	*
	*播放音乐背景音乐
	*
	*@param：
	*	LPWSTR path：音频路径
	*@return int：
	*	0：播放成功
	*	-1：播放失败
	*/
    int PlayBgSound(const LPWSTR& path);

	/*
	*StopBgSound()
	*
	*停止播放背景音乐
	*
	*@return int：
	*	0：停止成功
	*	-1：停止失败
	*/
	int StopBgSound();

	/*
	*PauseBgSound()
	*
	*暂停播放背景音乐
	*
	*@return int：
	*	0：暂停成功
	*	-1：暂停失败
	*/
	int PauseBgSound();

	/*
	*RePlayBgSound()
	*
	*重新播放背景音乐
	*
	*@return int：
	*	0：重新播放成功
	*	-1：重新播放失败
	*/
	int RePlayBgSound();

	/*
	*AddEffectsSound()
	*
	*添加特效音乐
	*
	*@Param:
	*	LPWSTR path:音乐路径
	*/
	void AddEffectsSound(const LPWSTR& path);

	/*
	*PlayEffectsSound()
	*
	*播放特效音乐
	*/
	void PlayEffectsSound();

	/*
	*StopEffectsSound()
	*
	*关闭特效音乐
	*/
	void StopEffectsSound();

	/*
	*SetMusicVolume(const UINT& value)
	*
	*设置音乐音量
	*
	*@Param：
	*	UINT value：音量大小，此值应在0~1000之间
	*@return int:
	*	0:设置成功
	*	-1：设置失败
	*/
	int SetMusicVolume(UINT value);

	/*
	*GetBgMusicAllTime()
	*
	*获取背景音乐总的播放时长
	*
	*@return DWORD
	*	背景音乐总时长毫秒数
	*/
	DWORD GetBgMusicAllTime();

	/*
	*GetBgMusicCurTime();
	*
	*获取背景音乐当前播放时长
	*
	*@return DWORD：
	*	当前播放时长
	*/
	DWORD GetBgMusicCurTime();

	/*
	*bool JumpBgMusicTo(const UINT& percent)
	*
	*将背景音乐跳到指定百分比数播放
	*
	*@Param：
	*	UINT percent：指定的百分比,此值应为0~100
	*/
	bool JumpBgMusicTo(const UINT& percent);

	/*
	*isPlaying()
	*
	*判断是否有音乐在播放
	*
	*@return bool：
	*	true：有音乐正在播放
	*	false：没有音乐正在播放
	*/
	bool isPlaying();
private:
	DWORD m_BgSoundId;

	std::list<LPWSTR> m_listEffectsMusic;

	std::list<DWORD> m_listEffectsId;
};

