#include "stdafx.h"
#include "boss.h"

HRESULT boss::init()
{
	
	return S_OK;
}

HRESULT boss::init(POINT position)
{
	boss[0] = IMAGEMANAGER->addFrameImage("agahnimMX", "img/enemy/agahnim mix.bmp", 2112, 630, 16, 6, true, RGB(255, 0, 255));
	boss[1] = IMAGEMANAGER->addFrameImage("agahnimSD", "img/enemy/agahnim shadow.bmp", 1152, 96, 12, 1, true, RGB(255, 0, 255));

	

	x = position.x;
	y = position.y;
	cx = x;
	cy = y;

	bossI = boss[0];
	bossI->setX(x - 44);
	bossI->setY(y - 35);
	_state = ATTACK;
	_action = new action;
	_action->init();

	aPossible = true;
	mPossible = false;

	direction = 0;
	indexY = direction;
	maxHP = currentHP = 30;
	z = 1;
	midW = (_censor.left + _censor.right) / 2;
	midH = (_censor.top + _censor.bottom) / 2;

	lCount = aCount = mCount = 0;

	_rc = RectMakeCenter(x, y, 80, 65);
	_censor = RectMakeCenter(cx, cy+100, 700, 700);
	indexX = 0;
	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	midW = (_censor.left + _censor.right) / 2;
	midH = (_censor.top + _censor.bottom) / 2;
	_count++;
	movecount++;
	if (!lightning)
	{
		if (_ptMouse.x >= _rc.left&&_ptMouse.x <= _rc.right&&_ptMouse.y >= _rc.bottom)direction = 0;
		if (_ptMouse.y <= _rc.top)direction = 1;
		if (_ptMouse.x <= _rc.left&&_ptMouse.y >= _rc.top - 100 && _ptMouse.y <= _rc.bottom)direction = 2;
		if (_ptMouse.x >= _rc.right&&_ptMouse.y >= _rc.top - 100 && _ptMouse.y <= _rc.bottom)direction = 3;
		if (_ptMouse.x <= _rc.left&&_ptMouse.y >= _rc.bottom)direction = 4;
		if (_ptMouse.x >= _rc.right&&_ptMouse.y >= _rc.bottom)direction = 5;

		indexY = direction;
	}
	else
		indexY = 0;

	if (mPossible && !lightning)
	{
		if (_ptMouse.x < midW&&_ptMouse.y < midH)_action->moveTo(bossI, _censor.right - bossI->getFrameWidth() - RND->getFromIntTo(5, 20), _ptMouse.y + RND->getInt(30), 2.1f);
		if (_ptMouse.x > midW&&_ptMouse.y > midH)_action->moveTo(bossI, _censor.left + RND->getFromIntTo(5, 20), _ptMouse.y + RND->getFromIntTo(-30, 0), 2.1f);
		if (_ptMouse.x > midW&&_ptMouse.y < midH)_action->moveTo(bossI, _ptMouse.x + RND->getFromIntTo(-30, 0), _censor.bottom - bossI->getFrameHeight() - RND->getInt(30), 2.1f);
		if (_ptMouse.x<midW&&_ptMouse.y > midH)_action->moveTo(bossI, _ptMouse.x + RND->getInt(30), _censor.top + RND->getInt(30), 2.1f);

		_state = BOSS_MOVE;
	}
	if (mPossible&&lightning)
	{
		_action->moveTo(bossI, midW - (bossI->getFrameWidth() / 2), _censor.top + 20, 2.1f);
		_state = BOSS_MOVE;
		lCount = 0;
	}
	if (aPossible)
	{
		_state = ATTACK;
	}

	if (bossI->getX() <= _censor.left)bossI->setX(_censor.left + 5);
	if ((bossI->getX() + bossI->getFrameWidth()) >= _censor.right)bossI->setX(_censor.right - 5 - bossI->getFrameWidth());
	if (bossI->getY() <= _censor.top)bossI->setY(_censor.top + 5);
	if ((bossI->getY() + bossI->getFrameHeight()) >= _censor.bottom)bossI->setY(_censor.bottom - 5 - bossI->getFrameHeight());

	if (_count >= 9)
	{
		if (_state == ATTACK)
		{
			aCount++;
			boss[0]->setFrameY(indexY);
			boss[0]->setFrameX(indexX);
			_count = 0;
			if (aCount < 17)indexX++;
			if (aCount >= 30)
			{
				if (lightning)lightning = false;
				aCount = 0;
				lCount++;
				if (lCount >= 3)lightning = true;
				aPossible = false;
				mPossible = true;
			}
			if (indexX > boss[0]->getMaxFrameX())indexX = 0;
			_rc = RectMake(bossI->getX() + 10, bossI->getY() + 5, bossI->getFrameWidth() - 20, bossI->getFrameHeight() - 5);
		}

		if (_state == BOSS_MOVE)
		{
			mCount++;
			boss[1]->setFrameY(0);
			boss[1]->setFrameX(indexX);
			_count = 0;
			if (mCount <= 12)indexX++;
			if (mCount > 12)
			{
				mCount = 0;
				mPossible = false;
				aPossible = true;
			}
			if (indexX > boss[1]->getMaxFrameX())indexX = 0;
			_rc = RectMake(bossI->getX() + 10, bossI->getY() + 5, boss[1]->getFrameWidth(), boss[1]->getFrameHeight());
		}
	}
	_action->update();
}

void boss::render()
{
	if (PRINTMANAGER->isDebug())
	{
		Rectangle(getMemDC(), _censor);
		Rectangle(getMemDC(), _rc);
	}
	draw();
}

void boss::draw()
{
	if (_state == BOSS_MOVE)
	{
		boss[1]->frameRender(getMemDC(), bossI->getX() + 10, bossI->getY() + 5, indexX, 0);
	}
	if (_state == ATTACK)
	{
		boss[0]->frameRender(getMemDC(), bossI->getX(), bossI->getY(), indexX, indexY);
	}
}

void boss::hitDamage(float damage)
{
	currentHP -= damage;
}
