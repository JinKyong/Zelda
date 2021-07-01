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
	_mp = 128;
	_speed = 5.f;
	_moneyCount = _bombCount = _arrowCount = 0;

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
	//Å×½ºÆ®¿ë ÄÚµå============================
	if (KEYMANAGER->isOnceKeyDown('1'))	changeMoney(-50);
	if (KEYMANAGER->isOnceKeyDown('2'))	changeMoney(50);

	if (KEYMANAGER->isOnceKeyDown('3'))	changeBomb(-5);
	if (KEYMANAGER->isOnceKeyDown('4'))	changeBomb(5);

	if (KEYMANAGER->isOnceKeyDown('5'))	changeArrow(-5);
	if (KEYMANAGER->isOnceKeyDown('6'))	changeArrow(5);
	
	//////////////////////////////////////////

	if (KEYMANAGER->isOnceKeyDown('7'))	changeHP(0.5f);
	if (KEYMANAGER->isOnceKeyDown('8'))	changeHP(-0.5f);
	if (KEYMANAGER->isOnceKeyDown('9'))	changeMP(5);
	if (KEYMANAGER->isOnceKeyDown('0'))	changeMP(-5);
	//========================================

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

void Player::changeHP(float damage)
{
	_hp -= damage;

	if (_hp < 0) _hp = 0;
	if (_hp > 3) _hp = 3;

	UIMANAGER->setHP(_hp);
}

void Player::changeMP(float useSkill)
{
	_mp -= useSkill;

	if (_mp < 0) _mp = 0;
	if (_mp > 128) _mp = 128;

	UIMANAGER->setMP(_mp);
}

void Player::changeMoney(int num)
{
	_moneyCount += num;

	if (_moneyCount > 999) _moneyCount = 999;
	else if (_moneyCount < 0) _moneyCount = 0;

	UIMANAGER->setMoney(_moneyCount);
}
void Player::changeBomb(int num)
{
	_bombCount += num;

	if (_bombCount > 99) _bombCount = 99;
	else if (_bombCount < 0) _bombCount = 0;

	UIMANAGER->setBomb(_bombCount);
}

void Player::changeArrow(int num)
{
	_arrowCount += num;

	if (_arrowCount > 99) _arrowCount = 99;
	else if (_arrowCount < 0) _arrowCount = 0;

	UIMANAGER->setArrow(_arrowCount);
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
