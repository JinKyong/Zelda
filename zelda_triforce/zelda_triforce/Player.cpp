#include "stdafx.h"
#include "Player.h"
#include "State.h"

HRESULT Player::init()
{
	//¸öÃ¼


	//½ºÅÈ


	//»óÅÂ


	//ÀÌÆåÆ®
	STATEMANAGER->init(this);

	return S_OK;
}

void Player::release()
{
	STATEMANAGER->release();
	STATEMANAGER->releaseSingleton();
}

void Player::update()
{
	STATEMANAGER->update();
	STATEMANAGER->getCurrentState()->updateRect();
}

void Player::render()
{
	if (PRINTMANAGER->isDebug()) {

	}

	STATEMANAGER->render(getMemDC());
}