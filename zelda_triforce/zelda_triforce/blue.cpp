#include "stdafx.h"
#include "blue.h"

HRESULT blue::init(POINT position)
{
	blue[0] = IMAGEMANAGER->addFrameImage("blueMX", "img/enemy/blue move mix.bmp", 762, 729, 4, 4, true, RGB(255, 0, 255));
	blue[1] = IMAGEMANAGER->addFrameImage("blueSMX", "img/enemy/blue search mix.bmp", 762, 729, 4, 4, true, RGB(255, 0, 255));


	_x = position.x;
	_y = position.y;

	blueI = blue[0];
	blueI->setX(_x);
	blueI->setY(_y);
	_state = BLUE_MOVE;
	_action = new action;
	_action->init();


	_next = RND->getFromIntTo(5, 8);
	_findway = RND->getInt(4);
	_direction = RND->getInt(4);

	_indexX = 0;
	_indexY = _direction;
	_indexH = _findway;
	_maxHP = _currentHP = 30;
	_z = 1;

	_radius = 300;
	_rc = RectMakeCenter(_x, _y, 80, 112);

	return S_OK;
}

void blue::release()
{
}

void blue::update()
{
	if (_findway == 0 && _next <= 0)_state = BLUE_SEARCH;
	if (_findway == 1 && _next <= 0)_state = BLUE_SEARCH;
	if (_findway == 2 && _next <= 0)_state = BLUE_SEARCH;
	if (_findway == 3 && _next <= 0)_state = BLUE_SEARCH;
	if (_direction == 0 && _next > 0)_state = BLUE_MOVE;
	if (_direction == 1 && _next > 0)_state = BLUE_MOVE;
	if (_direction == 2 && _next > 0)_state = BLUE_MOVE;
	if (_direction == 3 && _next > 0)_state = BLUE_MOVE;
	_indexY = _direction;

	_count++;
	_movecount++;
	if (_count >= 20)
	{
		if (_state == BLUE_MOVE)
		{
			blue[0]->setFrameY(_indexY);
			blue[0]->setFrameX(_indexX);
			_count = 0;
			_indexX++;
			if (_indexX > blue[0]->getMaxFrameX())_indexX = 0;
		}
		if (_state == BLUE_SEARCH)
		{

			blue[1]->setFrameY(_indexY);
			if (_direction == 0 && _indexH == 0)_indexH++;
			if (_direction == 1 && _indexH == 0)_indexH++;
			if (_direction == 2 && _indexH == 3)_indexH++;
			if (_direction == 3 && _indexH == 2)_indexH++;
			blue[1]->setFrameX(_indexH);
			_indexH++;
			if (_indexH > blue[1]->getMaxFrameX())_indexH = 0;
			_next--;
			_count = 0;
		}

	}

	if (_movecount >= 20 && _next > 0)
	{
		_movecount = 0;
		if (_direction == 0)
		{	
			//EFFECTMANAGER->setKnife(_rc.left + 10, _rc.bottom);
			_action->moveTo(blueI, blueI->getX(), blueI->getY() + 30, 0.3f);
		}
		if (_direction == 1)
		{
			//EFFECTMANAGER->setKnife(_rc.right - 50, _rc.top - 40);
			_action->moveTo(blueI, blueI->getX(), blueI->getY() - 30, 0.3f);
		}
		if (_direction == 2)
		{
			//EFFECTMANAGER->setKnife(_rc.left - 40, _rc.top - 10);
			_action->moveTo(blueI, blueI->getX() - 30, blueI->getY(), 0.3f);
		}
		if (_direction == 3)
		{
			//EFFECTMANAGER->setKnife(_rc.right, _rc.bottom - 10);
			_action->moveTo(blueI, blueI->getX() + 30, blueI->getY(), 0.3f);
		}
		_next--;
	}

	if (_direction == 0 && _findway == 1)_findway = RND->getInt(4);
	if (_direction == 1 && _findway == 0)_findway = RND->getInt(4);
	if (_direction == 2 && _findway == 3)_findway = RND->getInt(4);
	if (_direction == 3 && _findway == 2)_findway = RND->getInt(4);

	if (_next < -5)
	{
		_next = RND->getFromIntTo(5, 8);
		if (_direction == 0)_direction = 1;
		else if (_direction == 1)_direction = 0;
		else if (_direction == 2)_direction = 3;
		else if (_direction == 3)_direction = 2;
		_findway = RND->getInt(4);
	}
	_action->update();
	if (_direction == 0)
	{
		_sword=RectMake(_rc.left , _rc.bottom,30,40);
	}
	if (_direction == 1)
	{
		_sword=RectMake(_rc.right - 30, _rc.top - 40,30,40);
	}
	if (_direction == 2)
	{
		_sword=RectMake(_rc.left - 40, _rc.bottom - 40,40,30);
	}
	if (_direction == 3)
	{
		_sword=RectMake(_rc.right, _rc.bottom - 40,40,30);
	}
	_rc = RectMake(blueI->getX() + (blueI->getFrameWidth() / 4), blueI->getY() + (blueI->getFrameHeight() / 4), blueI->getFrameWidth() / 2, blueI->getFrameHeight() / 2);
}

void blue::render()
{
	if (PRINTMANAGER->isDebug())
	{
		EllipseMakeCenter(getMemDC(), blueI->getX() + blueI->getFrameWidth() / 2, blueI->getY() + blueI->getFrameHeight() / 2, _radius * 2, _radius * 2);
		Rectangle(getMemDC(), _rc);
		Rectangle(getMemDC(), _sword);
	}
	draw();
}

void blue::draw()
{
	if (_state == BLUE_MOVE)
	{
		blue[0]->frameRender(getMemDC(), blueI->getX(), blueI->getY(), _indexX, _indexY);
	}
	if (_state == BLUE_SEARCH)
	{
		blue[1]->frameRender(getMemDC(), blueI->getX(), blueI->getY(), _indexH, _indexY);
	}
}

void blue::hitDamage(float damage)
{
	_currentHP -= damage;
}