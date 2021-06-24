#include "stdafx.h"
#include "Run.h"
#include "Player.h"

HRESULT Run::init(Player * player)
{
	State::init(player);

	_img = IMAGEMANAGER->addFrameImage("run", "img/link/run.bmp", 576, 384, 8, 4, true, RGB(255, 0, 255));

	_count = 0;
	_direct = _player->getDirect();

	_img->setFrameY(_direct);

	_img->setFrameX(0);
	return S_OK;
}

void Run::release()
{
}

void Run::update()
{
	controlKey();
	controlFrame();

	updateRect();
}

void Run::render(HDC hdc)
{
	_img->frameRender(hdc, _player->getX() - _img->getFrameWidth() / 2, _player->getY() - _img->getFrameHeight() / 2);
}

void Run::updateDirect(int direct)
{
}

void Run::updateRect()
{
	float x = _player->getX();
	float y = _player->getY();

	_player->setRect(x, y, 64, 64);
}

void Run::controlKey()
{
	if (KEYMANAGER->isStayKeyDown(KEY_RIGHT))
	{
		updateDirect(RIGHT);
		_player->move(RIGHT);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_LEFT))
	{
		updateDirect(LEFT);
		_player->move(LEFT);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_UP))
	{
		updateDirect(UP);
		_player->move(UP);
	}
	if (KEYMANAGER->isStayKeyDown(KEY_DOWN))
	{
		updateDirect(DOWN);
		_player->move(DOWN);
	}

	if (KEYMANAGER->isOnceKeyUp(KEY_RIGHT)) 	STATEMANAGER->changeState(IDLE);
	if (KEYMANAGER->isOnceKeyUp(KEY_LEFT))		STATEMANAGER->changeState(IDLE);
	if (KEYMANAGER->isOnceKeyUp(KEY_UP))		STATEMANAGER->changeState(IDLE);
	if (KEYMANAGER->isOnceKeyUp(KEY_DOWN))		STATEMANAGER->changeState(IDLE);
}

void Run::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();

	if (_count >= RENDERCOUNT2)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			_img->setFrameX(0);
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}
