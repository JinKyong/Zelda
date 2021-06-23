#include "stdafx.h"
#include "Player.h"
#include "State.h"

HRESULT Player::init()
{
	//¸öÃ¼
	_x = 200;
	_y = 300;
	_z = 1;
	_body = RectMakeCenter(_x, _y, 64, 64);

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
	//STATEMANAGER->getCurrentState()->updateRect();

	_body = RectMakeCenter(_x, _y, 64, 64);
}

void Player::render()
{
	if (PRINTMANAGER->isDebug()) {

	}

	STATEMANAGER->render(getMemDC());
}