#include "stdafx.h"
#include "green.h"

HRESULT green::init(POINT position)
{
	green[0] = IMAGEMANAGER->addFrameImage("greenMX", "img/enemy/green move mix.bmp", 762, 729, 4, 4, true, RGB(255, 0, 255));
	green[1] = IMAGEMANAGER->addFrameImage("greenSMX", "img/enemy/green search mix.bmp", 762, 729, 4, 4, true, RGB(255, 0, 255));


	_x = position.x;
	_y = position.y;

	greenI = green[0];
	greenI->setX(_x);
	greenI->setY(_y);
	_state = GREEN_MOVE;
	_action = new action;
	_action->init();


	_next = RND->getFromIntTo(5, 8);
	_findway = RND->getInt(4);
	_direction = RND->getInt(4);
	_indexY = _direction;
	_indexH = _findway;
	_maxHP = _currentHP = 30;
	_z = 1;

	_radius = 300;
	_rc = RectMakeCenter(_x, _y, 80, 112);

	_indexX = 0;
	return S_OK;
}

void green::release()
{
}

void green::update()
{
	if (_findway == 0 && _next <= 0)_state = GREEN_SEARCH;
	if (_findway == 1 && _next <= 0)_state = GREEN_SEARCH;
	if (_findway == 2 && _next <= 0)_state = GREEN_SEARCH;
	if (_findway == 3 && _next <= 0)_state = GREEN_SEARCH;
	if (_direction == 0 && _next > 0)_state = GREEN_MOVE;
	if (_direction == 1 && _next > 0)_state = GREEN_MOVE;
	if (_direction == 2 && _next > 0)_state = GREEN_MOVE;
	if (_direction == 3 && _next > 0)_state = GREEN_MOVE;
	_indexY = _direction;

	_count++;
	_movecount++;
	if (_count >= 20)
	{
		if (_state == GREEN_MOVE)
		{
			green[0]->setFrameY(_indexY);
			green[0]->setFrameX(_indexX);
			_count = 0;
			_indexX++;
			if (_indexX > green[0]->getMaxFrameX())_indexX = 0;
		}
		if (_state == GREEN_SEARCH)
		{

			green[1]->setFrameY(_indexY);
			if (_direction == 0 && _indexH == 0)_indexH++;
			if (_direction == 1 && _indexH == 0)_indexH++;
			if (_direction == 2 && _indexH == 3)_indexH++;
			if (_direction == 3 && _indexH == 2)_indexH++;
			green[1]->setFrameX(_indexH);
			_indexH++;
			if (_indexH > green[1]->getMaxFrameX())_indexH = 0;
			_next--;
			_count = 0;
		}

	}

	if (_movecount >= 20 && _next > 0)
	{
		_movecount = 0;
		if (_direction == 0)_action->moveTo(greenI, greenI->getX(), greenI->getY() + 30, 0.3f);
		if (_direction == 1)_action->moveTo(greenI, greenI->getX(), greenI->getY() - 30, 0.3f);
		if (_direction == 2)_action->moveTo(greenI, greenI->getX() - 30, greenI->getY(), 0.3f);
		if (_direction == 3)_action->moveTo(greenI, greenI->getX() + 30, greenI->getY(), 0.3f);
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
	_rc = RectMake(greenI->getX() + (greenI->getFrameWidth() / 4), greenI->getY() + (greenI->getFrameHeight() / 4), greenI->getFrameWidth() / 2, greenI->getFrameHeight() / 2);
}

void green::render()
{
	if (PRINTMANAGER->isDebug())
	{
		EllipseMakeCenter(getMemDC(), greenI->getX() + greenI->getFrameWidth() / 2, greenI->getY() + greenI->getFrameHeight() / 2, _radius * 2, _radius * 2);
		Rectangle(getMemDC(), _rc);

	}
	draw();
}

void green::draw()
{
	if (_state == GREEN_MOVE)
	{
		green[0]->frameRender(getMemDC(), greenI->getX(), greenI->getY(), _indexX, _indexY);
	}
	if (_state == GREEN_SEARCH)
	{
		green[1]->frameRender(getMemDC(), greenI->getX(), greenI->getY(), _indexH, _indexY);
	}
}

void green::hitDamage(float damage)
{
	_currentHP -= damage;
}
