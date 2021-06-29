#include "stdafx.h"
#include "Idle.h"
#include "Player.h"

HRESULT Idle::init(Player * player)
{
	State::init(player);

	_img = IMAGEMANAGER->addFrameImage("idle", "img/link/idle.bmp", 64, 368, 1, 4, true, RGB(255, 0, 255));

	_count = 0;
	_direct = _player->getDirect();

	_img->setFrameY(_direct);

	_img->setFrameX(0);
	return S_OK;
}

void Idle::release()
{
}

void Idle::update()
{
	controlKey();
}

void Idle::render(HDC hdc)
{
	_img->frameRender(hdc, _player->getX() - _img->getFrameWidth() / 2, _player->getY() - _img->getFrameHeight() / 2);
}

void Idle::updateDirect(int direct)
{
}

void Idle::updateRect()
{
}

void Idle::controlKey()
{
	/**** 이동 ***/
	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT))
	{
		_player->setDirect(RIGHT);
		STATEMANAGER->changeState(RUN);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_LEFT))
	{
		_player->setDirect(LEFT);
		STATEMANAGER->changeState(RUN);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_UP))
	{
		_player->setDirect(UP);
		STATEMANAGER->changeState(RUN);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_DOWN))
	{
		_player->setDirect(DOWN);
		STATEMANAGER->changeState(RUN);
	}

	//공격
	if (KEYMANAGER->isOnceKeyDown(KEY_SLASH))
	{
		STATEMANAGER->changeState(SLASH);
	}
}

void Idle::controlFrame()
{
}
