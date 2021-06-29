#include "stdafx.h"
#include "ChargeAttack.h"
#include "Player.h"

HRESULT ChargeAttack::init(Player* player)
{
	_img = IMAGEMANAGER->addFrameImage("cAttack", "img/link/chargeAttack.bmp", 2160, 768, 12, 4, true, RGB(255, 0, 255));

	_direct = _player->getDirect();

	_img->setFrameX(0);
	_img->setFrameY(_direct);

	_attackBox = RectMakeCenter(_player->getX(), _player->getY(), 192, 192);
	return S_OK;
}

void ChargeAttack::release()
{
}

void ChargeAttack::update()
{
	controlFrame();
}

void ChargeAttack::render(HDC hdc)
{
	if (PRINTMANAGER->isDebug())
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, brush);
		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN OldPen = (HPEN)SelectObject(hdc, pen);
		Rectangle(hdc, _attackBox);
		SelectObject(hdc, OldPen);
		DeleteObject(pen);
		SelectObject(hdc, OldBrush);
		DeleteObject(brush);
	}
		if (_direct == DOWN)			_img->frameRender(hdc, _player->getBody().left - 57, _player->getBody().top - 92);
		else if (_direct == UP)			_img->frameRender(hdc, _player->getBody().left - 56, _player->getBody().top - 55);
		else if (_direct == RIGHT)		_img->frameRender(hdc, _player->getBody().left - 68, _player->getBody().top - 75);
		else							_img->frameRender(hdc, _player->getBody().left - 47, _player->getBody().top - 73);
}

void ChargeAttack::updateDirect(int direct)
{
}

void ChargeAttack::updateRect()
{
}

void ChargeAttack::controlKey()
{
}

void ChargeAttack::controlFrame()
{
	_count++;

	if (_count >= 3)
	{
		if (_img->getFrameX() >= _img->getMaxFrameX())
			STATEMANAGER->changeState(IDLE);
		else
			_img->setFrameX(_img->getFrameX() + 1);

		_count = 0;
	}
}