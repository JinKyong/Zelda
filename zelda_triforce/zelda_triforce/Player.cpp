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
	_hp = 3;
	_speed = 5.f;
	_money = 0;

	//»óÅÂ


	//ÀÌÆåÆ®
	STATEMANAGER->init(this);
	_effect = new EffectManager;

	return S_OK;
}

void Player::release()
{
	STATEMANAGER->release();
	STATEMANAGER->releaseSingleton();
}

void Player::update()
{
	//Å×½ºÆ®¿ë
	if (KEYMANAGER->isOnceKeyDown('F'))
		changeMoney(50);
	if (KEYMANAGER->isOnceKeyDown('D'))
		changeMoney(-50);

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

void Player::changeMoney(int num)
{
	_money += num;

	if (_money > 999)
		_money = 999;
	else if (_money < 0)
		_money = 0;

	UIMANAGER->setMoney(_money);
}

void Player::changeHP(float damage)
{
	_hp -= damage;

	if (_hp < 0)
		_hp = 0;

	UIMANAGER->setHP(_hp);
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
