#include "stdafx.h"
#include "cMusicPlayer.h"
#include<mmsystem.h>
#include<Digitalv.h>

#pragma comment(lib,"winmm.lib")

cMusicPlayer::cMusicPlayer():m_BgSoundId(0)
{
	m_listEffectsId.clear();
	m_listEffectsMusic.clear();
}


cMusicPlayer::~cMusicPlayer()
{
}

int cMusicPlayer::PlayBgSound(const LPWSTR & path)
{
	if (m_BgSoundId)
	{
		StopBgSound();
	}
	MCI_OPEN_PARMS mciOpen;
	mciOpen.lpstrDeviceType = L"mpegvideo";
	mciOpen.lpstrElementName = path;
	MCIERROR error = mciSendCommand(0, MCI_OPEN, 
		MCI_OPEN_TYPE |MCI_OPEN_ELEMENT,
		(DWORD)&mciOpen);
	if (error)
	{
		return -1;
	}
	m_BgSoundId = mciOpen.wDeviceID;
	MCI_PLAY_PARMS mciPlay;
	error=mciSendCommand(m_BgSoundId, MCI_PLAY,
		/*MCI_DGV_PLAY_REPEAT*/MCI_NOTIFY, (DWORD)&mciPlay);
	if (error)
	{
		return -1;
	}
	return 0;
}

int cMusicPlayer::StopBgSound()
{
	if (!m_BgSoundId)
	{
		return -1;
	}
	MCI_GENERIC_PARMS gp;
	gp.dwCallback = NULL;
	MCIERROR error=mciSendCommand(m_BgSoundId, 
		MCI_CLOSE, MCI_WAIT, (DWORD)&gp);
	if (error)
	{
		return -1;
	}
	m_BgSoundId = 0;
	return 0;
}

int cMusicPlayer::PauseBgSound()
{
	if (!m_BgSoundId)
	{
		return -1;
	}
	MCI_PLAY_PARMS mciPause;
	MCIERROR error=mciSendCommand(m_BgSoundId,
		MCI_PAUSE, MCI_NOTIFY, (DWORD)&mciPause);
	if (error)
	{
		return -1;
	}
	return 0;
}

int cMusicPlayer::RePlayBgSound()
{
	if (!m_BgSoundId)
	{
		return -1;
	}
	MCI_PLAY_PARMS mciReplay;
	MCIERROR error=mciSendCommand(m_BgSoundId, 
		MCI_PLAY, MCI_DGV_PLAY_REPEAT, 
		(DWORD)&mciReplay);
	if (error)
	{
		return -1;
	}
	return 0;
}

void cMusicPlayer::AddEffectsSound(const LPWSTR& path)
{
	m_listEffectsMusic.push_back(path);
}

void cMusicPlayer::PlayEffectsSound()
{
	if (m_listEffectsMusic.size() == 0)
	{
		return;
	}
	for (const auto& it : m_listEffectsMusic)
	{
		MCI_OPEN_PARMS mciOpen;
		mciOpen.lpstrDeviceType = L"mpegvideo";
		mciOpen.lpstrElementName = it;
		mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciOpen);
		m_listEffectsId.push_back(mciOpen.wDeviceID);
		MCI_PLAY_PARMS mciPlay;
		mciSendCommand(mciOpen.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&mciPlay);
	}
	m_listEffectsMusic.clear();
}

void cMusicPlayer::StopEffectsSound()
{
	if (m_listEffectsId.size() == 0)
	{
		return;
	}
	for (auto it = std::begin(m_listEffectsId); it != std::end(m_listEffectsId);)
	{
		MCI_STATUS_PARMS mciStatus;
		mciStatus.dwItem = MCI_STATUS_LENGTH;
		mciStatus.dwReturn = 0;
		mciSendCommand(*it, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatus);
		DWORD allLen = mciStatus.dwReturn;
		mciStatus.dwItem = MCI_STATUS_POSITION;
		mciStatus.dwReturn = 0;
		mciSendCommand(*it, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatus);
		DWORD currLen = mciStatus.dwReturn;
		if (allLen == currLen)
		{
			MCI_GENERIC_PARMS gp;
			gp.dwCallback = NULL;
		     mciSendCommand(m_BgSoundId,
				MCI_CLOSE, MCI_WAIT, (DWORD)&gp);
			it=m_listEffectsId.erase(it);
		}
		else
		{
			++it;
		}
	}
}

int cMusicPlayer::SetMusicVolume(UINT value)
{
	value = value > 1000 ? 1000 : value;
	if (m_BgSoundId)
	{
		MCI_DGV_SETAUDIO_PARMS mciSetVolume;
		mciSetVolume.dwItem = MCI_DGV_SETAUDIO_VOLUME;
		mciSetVolume.dwValue = value;
		MCIERROR error = mciSendCommand(m_BgSoundId, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD)&mciSetVolume);
		if (error)
		{
			return -1;
		}
	}
	if (m_listEffectsId.size())
	{
		MCI_DGV_SETAUDIO_PARMS mciSetVolume;
		mciSetVolume.dwItem = MCI_DGV_SETAUDIO_VOLUME;
		mciSetVolume.dwValue = value;
		for (const auto& it : m_listEffectsId)
		{
			MCIERROR error = mciSendCommand(it, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD)&mciSetVolume);
			if (error)
			{
				return -1;
			}
		}
	}
	return 0;
}

DWORD cMusicPlayer::GetBgMusicAllTime()
{
	if (!m_BgSoundId)
	{
		return 0;
	}
	MCI_STATUS_PARMS mciStatus;
	mciStatus.dwItem = MCI_STATUS_LENGTH;
	mciStatus.dwReturn = 0;
	mciSendCommand(m_BgSoundId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatus);
	return mciStatus.dwReturn;
}

DWORD cMusicPlayer::GetBgMusicCurTime()
{
	if (!m_BgSoundId)
	{
		return 0;
	}
	MCI_STATUS_PARMS mciStatus;
	mciStatus.dwItem = MCI_STATUS_POSITION;
	mciStatus.dwReturn = 0;
	mciSendCommand(m_BgSoundId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatus);
	return mciStatus.dwReturn;
}

bool cMusicPlayer::JumpBgMusicTo(const UINT & percent)
{
    double allTime = GetBgMusicAllTime();
	MCI_SEEK_PARMS SeekParms;
	SeekParms.dwTo = allTime*(percent / 100.0);
	mciSendCommand(m_BgSoundId, MCI_SEEK, MCI_TO
		| MCI_WAIT, (DWORD)(LPVOID)&SeekParms);
	RePlayBgSound();
	//	* 跳到文件头
	//	mciSendCommand(m_wDeviceID, MCI_SEEK,
	//		MCI_SEEK_TO_START, NULL);
	//*跳到文件尾
	//	mciSendCommand(m_wDeviceID, MCI_SEEK,
	//		MCI_SEEK_TO_END, NULL);
	return false;
}

bool cMusicPlayer::isPlaying()
{
	return m_BgSoundId ? true : false;
}
