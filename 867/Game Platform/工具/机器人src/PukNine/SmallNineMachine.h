#pragma once

#include "IRobot.h"
#include <deque>

class SmallNineMachine : public IRobot
{
public:
	SmallNineMachine(DWORD dwUserID);
	virtual ~SmallNineMachine(void);

	//游戏状态
	virtual bool			OnGameSceneMessage(BYTE cbGameStation, 
		void * pBuffer, WORD wDataSize);

	//周期性更新
	virtual void			OnUpdate(float fElapsed);

	//游戏消息
	virtual bool			OnGameMessage(WORD wSubCmdID, const void * pBuffer=NULL,
		WORD wDataSize=0);

public:
	virtual bool			SendApplyBanker(bool bUp);
	virtual	void			ResetGame();
	virtual INT64			GetRandScore();
	virtual void			SetOnlineTime(double fOnlineTime);
	virtual BYTE			GetRandArea();
protected:
	WORD					m_wCurBanker;
	double					m_fOnlineTime;
	double					m_fCurOnlineTime;
	double					m_fElapsedTime;
	double					m_fAddJettonTime;
	INT64					m_nMeMaxScore;
	BOOL					m_bAddJetton;

	INT64					m_nBankerScore;
	INT64					m_nBankerWinScore;	//庄家成绩
	WORD					m_wUpBankerCount;
	INT64					m_nApplyBankerCondition;
	BOOL					m_bStart;
	BOOL					m_bApplyBankerSend;

	INT64					m_nMePlaceScore;
	INT64					m_nMeWinScore;
};

