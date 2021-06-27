#include "stdafx.h"
#include "Slash.h"
#include "Player.h"

HRESULT Slash::init(Player * player)
{
	State::init(player);

	_img = IMAGEMANAGER->addFrameImage("slash_front", "img/link/attack.bmp", 1160, 584, 8, 4, true, RGB(255, 0, 255));

	_direct = _player->getDirect();

	_img->setFrameX(0);

	if (_direct == DOWN)
	{
		_slashBox = RectMakeCenter(_player->getX(), _player->getY() + 64, 64, 64);
		_img->setFrameY(0);
	}
	else if (_direct == UP)
	{
		_slashBox = RectMakeCenter(_player->getX(), _player->getY() - 64, 64, 64);
		_img->setFrameY(1);
	}
	else if (_direct == RIGHT)
	{
		_slashBox = RectMakeCenter(_player->getX() + 64, _player->getY(), 64, 64);
		_img->setFrameY(2);
	}
	else
	{
		_slashBox = RectMakeCenter(_player->getX() - 64, _player->getY(), 64, 64);
		_img->setFrameY(3);
	}

	return S_OK;
}

void Slash::release()
{
}

void Slash::update()
{
	controlKey();
	controlFrame();

	updateRect();
}

void Slash::render(HDC hdc)
{
	if (PRINTMANAGER->isDebug()) {
		HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, brush);
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HPEN OldPen = (HPEN)SelectObject(hdc, pen);
		Rectangle(hdc, _slashBox);
		SelectObject(hdc, OldPen);
		DeleteObject(pen);
		SelectObject(hdc, OldBrush);
		DeleteObject(brush);
	}

	if (_direct == DOWN)		_img->frameRender(hdc, _player->getBody().left - 28, _player->getBody().top - 24);
	else if (_direct == UP)	_img->frameRender(hdc, _player->getBody().left - 52, _player->getBody().top - 67);
	else if (_direct == RIGHT)	_img->frameRender(hdc, _player->getBody().left, _player->getBody().top - 39);
	else						_img->frameRender(hdc, _player->getBody().left - 75, _player->getBody().top - 39);
}

void Slash::updateDirect(int direct)
{
}

void Slash::updateRect()
{
	float x = _player->getX();
	float y = _player->getY();

	//_player->setRect(x, y, WIDTH, HEIGHT);
}

void Slash::controlKey()
{
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_img->setFrameX(0);
	}
}

void Slash::controlFrame()
{
	_count++;
	if (_count % 2 == 0) {
		if (_img->getFrameX() >= _img->getMaxFrameX()) {

			if (KEYMANAGER->isStayKeyDown('A'))
			{
				STATEMANAGER->changeState(CHARGING);
			}
			else STATEMANAGER->setState(STATEMANAGER->getPrevState());
			_count = 0;
		}
		else _img->setFrameX(_img->getFrameX() + 1);
	}
}
