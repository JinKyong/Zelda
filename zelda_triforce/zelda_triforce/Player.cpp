#include "stdafx.h"
#include "Player.h"
#include "State.h"

HRESULT Player::init()
{
	//¸öÃ¼
	_x = 2500;
	_y = 2500;
	_z = 1;
	_direct = 0;
	_body = RectMakeCenter(_x, _y, 64, 64);

	//½ºÅÈ
	_speed = 5.f;

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
		Rectangle(getMemDC(), _body);
	}

	STATEMANAGER->render(getMemDC());
}

void Player::move(int direct)
{
	switch (direct)
	{
	case RIGHT:
		_x += _speed;
		break;
	case LEFT:
		_x -= _speed;
		break;
	case UP:
		_y -= _speed;
		break;
	case DOWN:
		_y += _speed;
		break;
	default:
		break;
	}
}
