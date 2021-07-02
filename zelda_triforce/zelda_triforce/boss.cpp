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

	

	_x = position.x;
	_y = position.y;
	_cx = _x;
	_cy = _y;

	bossI = boss[0];
	bossI->setX(_x - 44);
	bossI->setY(_y - 35);
	_state = ATTACK;
	

	_aPossible = true;
	_mPossible = false;

	_direction = 0;
	_indexY = _direction;
	_maxHP = _currentHP = 30;
	_z = 1;
	_midW = (_censor.left + _censor.right) / 2;
	_midH = (_censor.top + _censor.bottom) / 2;

	_lCount = _aCount = _mCount = 0;

	_rc = RectMakeCenter(_x, _y, 80, 65);
	_censor = RectMakeCenter(_cx, _cy+100, 700, 700);
	_indexX = 0;
	_pattern = RND->getInt(2);
	return S_OK;
}

void boss::release()
{
}

void boss::update()
{
	_midW = (_censor.left + _censor.right) / 2;
	_midH = (_censor.top + _censor.bottom) / 2;
	_count++;
	_movecount++;
	if (!_lightning)
	{
		if (_ptMouse.x+CAMERAMANAGER->getScreen().left >= _rc.left&&
			_ptMouse.x + CAMERAMANAGER->getScreen().left <= _rc.right&&
			_ptMouse.y + CAMERAMANAGER->getScreen().top >= _rc.bottom)_direction = 0;
		if (_ptMouse.y + CAMERAMANAGER->getScreen().top <= _rc.top)_direction = 1;
		if (_ptMouse.x + CAMERAMANAGER->getScreen().left <= _rc.left&&
			_ptMouse.y + CAMERAMANAGER->getScreen().top >= _rc.top - 100 &&
			_ptMouse.y + CAMERAMANAGER->getScreen().top <= _rc.bottom)_direction = 2;
		if (_ptMouse.x + CAMERAMANAGER->getScreen().left >= _rc.right&&
			_ptMouse.y + CAMERAMANAGER->getScreen().top >= _rc.top - 100 &&
			_ptMouse.y + CAMERAMANAGER->getScreen().top <= _rc.bottom)_direction = 3;
		if (_ptMouse.x + CAMERAMANAGER->getScreen().left <= _rc.left&&
			_ptMouse.y + CAMERAMANAGER->getScreen().top >= _rc.bottom)_direction = 4;
		if (_ptMouse.x + CAMERAMANAGER->getScreen().left >= _rc.right&&
			_ptMouse.y + CAMERAMANAGER->getScreen().top >= _rc.bottom)_direction = 5;

		_indexY = _direction;
	}
	else
		_indexY = 0;

	//if (_mPossible && !_lightning)
	//{
	//	if (_ptMouse.x + CAMERAMANAGER->getScreen().left < _midW&&
	//		_ptMouse.y + CAMERAMANAGER->getScreen().top < _midH)_action->moveTo(bossI, _censor.right - bossI->getFrameWidth() - RND->getFromIntTo(5, 20), _ptMouse.y + RND->getInt(30), 2.1f);
	//	if (_ptMouse.x + CAMERAMANAGER->getScreen().left > _midW&&
	//		_ptMouse.y + CAMERAMANAGER->getScreen().top > _midH)_action->moveTo(bossI, _censor.left + RND->getFromIntTo(5, 20), _ptMouse.y + RND->getFromIntTo(-30, 0), 2.1f);
	//	if (_ptMouse.x + CAMERAMANAGER->getScreen().left > _midW&&
	//		_ptMouse.y + CAMERAMANAGER->getScreen().top < _midH)_action->moveTo(bossI, _ptMouse.x + RND->getFromIntTo(-30, 0), _censor.bottom - bossI->getFrameHeight() - RND->getInt(30), 2.1f);
	//	if (_ptMouse.x + CAMERAMANAGER->getScreen().left<_midW&&
	//		_ptMouse.y + CAMERAMANAGER->getScreen().top > _midH)_action->moveTo(bossI, _ptMouse.x + RND->getInt(30), _censor.top + RND->getInt(30), 2.1f);
	//
	//	_state = BOSS_MOVE;
	//}
	//if (_mPossible&&_lightning)
	//{
	//	_action->moveTo(bossI, _midW - (bossI->getFrameWidth() / 2), _censor.top + 20, 2.1f);
	//	_state = BOSS_MOVE;
	//	_lCount = 0;
	//}
	if (_aPossible)
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
			_aCount++;
			boss[0]->setFrameY(_indexY);
			boss[0]->setFrameX(_indexX);
			_count = 0;
			if (_aCount < 17)_indexX++;
			if (_aCount >= 30)
			{
				if (_lightning)_lightning = false;
				_aCount = 0;
				_lCount++;
				if (_lCount >= 3)_lightning = true;
				_aPossible = false;
				_mPossible = true;
			}
			if (_indexX > boss[0]->getMaxFrameX())_indexX = 0;
			_rc = RectMake(bossI->getX() + 10, bossI->getY() + 5, bossI->getFrameWidth() - 20, bossI->getFrameHeight() - 5);
		}

		if (_state == BOSS_MOVE)
		{
			_mCount++;
			boss[1]->setFrameY(0);
			boss[1]->setFrameX(_indexX);
			_count = 0;
			if (_mCount <= 12)_indexX++;
			if (_mCount > 12)
			{
				_pattern = RND->getInt(2);
				_mCount = 0;
				_mPossible = false;
				_aPossible = true;
			}
			if (_indexX > boss[1]->getMaxFrameX())_indexX = 0;
			_rc = RectMake(bossI->getX() + 10, bossI->getY() + 5, boss[1]->getFrameWidth(), boss[1]->getFrameHeight());
		}
	}
	
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
		boss[1]->frameRender(getMemDC(), bossI->getX() + 10, bossI->getY() + 5, _indexX, 0);
	}
	if (_state == ATTACK)
	{
		boss[0]->frameRender(getMemDC(), bossI->getX(), bossI->getY(), _indexX, _indexY);
	}
}

void boss::hitDamage(float damage)
{
	_currentHP -= damage;
}
