#include "stdafx.h"
#include "enemy.h"


HRESULT scout::init()
{
	
	return S_OK;
}

HRESULT scout::init(POINT position)
{
	scout[0] = IMAGEMANAGER->addFrameImage("scoutMX", "img/enemy/scout move mix.bmp", 135, 378, 2, 4, true, RGB(255, 0, 255));
	scout[1] = IMAGEMANAGER->addFrameImage("scoutSMX", "img/enemy/scout shift mix.bmp", 270, 378, 4, 4, true, RGB(255, 0, 255));
	 

	x = position.x;
	y = position.y;

	scoutI = scout[0];
	scoutI->setX(x);
	scoutI->setY(y);
	_state = SCOUT_MOVE;
	_action = new action;
	_action->init();


	next = RND->getFromIntTo(5, 8);
	findway = RND->getInt(4);
	direction = RND->getInt(4);
	indexY = direction;
	indexH = findway;
	maxHP = currentHP = 30;
	z = 1;

	radius = 300;
	_rc = RectMakeCenter(x, y, 80, 112);

	indexX = 0;
	return S_OK;
}

void scout::release()
{
}

void scout::update()
{
	if (findway == 0 && next <= 0)_state = SCOUT_SHIFT;
	if (findway == 1 && next <= 0)_state = SCOUT_SHIFT;
	if (findway == 2 && next <= 0)_state = SCOUT_SHIFT;
	if (findway == 3 && next <= 0)_state = SCOUT_SHIFT;
	if (direction == 0 && next > 0)_state = SCOUT_MOVE;
	if (direction == 1 && next > 0)_state = SCOUT_MOVE;
	if (direction == 2 && next > 0)_state = SCOUT_MOVE;
	if (direction == 3 && next > 0)_state = SCOUT_MOVE;
	indexY = direction;
	indexH = findway;

	_count++;
	movecount++;
	if (_count >= 10)
	{
		if (_state == SCOUT_MOVE)
		{
			scout[0]->setFrameY(indexY);
			scout[0]->setFrameX(indexX);
			_count = 0;
			indexX++;
			if (indexX > scout[0]->getMaxFrameX())indexX = 0;
		}
		if (_state == SCOUT_SHIFT)
		{
			scout[1]->setFrameY(indexY);
			if (findway == 3)findway = RND->getInt(4);
			scout[1]->setFrameX(indexH);
			next--;
			_count = 0;
		}

	}

	if (movecount >= 20 && next > 0)
	{
		movecount = 0;
		if (direction == 0)_action->moveTo(scoutI, scoutI->getX(), scoutI->getY() + 30, 0.3f);
		if (direction == 1)_action->moveTo(scoutI, scoutI->getX(), scoutI->getY() - 30, 0.3f);
		if (direction == 2)_action->moveTo(scoutI, scoutI->getX() - 30, scoutI->getY(), 0.3f);
		if (direction == 3)_action->moveTo(scoutI, scoutI->getX() + 30, scoutI->getY(), 0.3f);
		next--;
	}

	if (direction == 0 && findway == 1)findway = RND->getInt(4);
	if (direction == 1 && findway == 0)findway = RND->getInt(4);
	if (direction == 2 && findway == 3)findway = RND->getInt(4);
	if (direction == 3 && findway == 2)findway = RND->getInt(4);
	if (next < -5)
	{
		next = RND->getFromIntTo(5, 8);
		direction = findway;
		findway = RND->getInt(4);
	}
	_action->update();
	_rc = RectMake(scoutI->getX(), scoutI->getY(), scoutI->getFrameWidth(), scoutI->getFrameHeight());
}

void scout::render()
{
	if (PRINTMANAGER->isDebug())
	{
		Rectangle(getMemDC(), _rc);

	}
	draw();
}

void scout::draw()
{

	if (_state == SCOUT_MOVE)
	{
		scout[0]->frameRender(getMemDC(), scoutI->getX(), scoutI->getY(), indexX, indexY);
	}
	if (_state == SCOUT_SHIFT)
	{
		scout[1]->frameRender(getMemDC(), scoutI->getX(), scoutI->getY(), indexH, indexY);
	}
}

void scout::hitDamage(float damage)
{
	currentHP -= damage;
}

HRESULT snake::init()
{
	
	return S_OK;
}

HRESULT snake::init(POINT position)
{
	snake[0] = IMAGEMANAGER->addFrameImage("snakeMX", "img/enemy/snake move mix.bmp", 96, 192, 2, 4, true, RGB(255, 0, 255));
	//snake[1] = IMAGEMANAGER->findImage("scoutSMX");

	x = position.x;
	y = position.y;

	snakeI = snake[0];
	snakeI->setX(x);
	snakeI->setY(y);
	_state = SNAKE_MOVE;
	_action = new action;
	_action->init();

	next = RND->getFromIntTo(2, 5);
	findway = RND->getInt(4);
	direction = RND->getInt(4);
	indexY = direction;
	maxHP = currentHP = 30;
	z = 1;

	_rc = RectMake(snakeI->getX(), snakeI->getY(), snakeI->getFrameWidth(), snakeI->getFrameHeight());

	indexX = 0;
	return S_OK;
}

void snake::release()
{
}

void snake::update()
{
	_state = SNAKE_MOVE;
	indexY = direction;

	_count++;
	movecount++;
	if (movecount >= 20 && next > 0)
	{

		direction = findway;
		movecount = 0;
		if (direction == 0)_action->moveTo(snakeI, snakeI->getX(), snakeI->getY() + 30, 0.3f);
		if (direction == 1)_action->moveTo(snakeI, snakeI->getX(), snakeI->getY() - 30, 0.3f);
		if (direction == 2)_action->moveTo(snakeI, snakeI->getX() - 30, snakeI->getY(), 0.3f);
		if (direction == 3)_action->moveTo(snakeI, snakeI->getX() + 30, snakeI->getY(), 0.3f);
		next--;
	}
	if (_count >= 4)
	{
		if (_state == SNAKE_MOVE)
		{
			snake[0]->setFrameY(indexY);
			snake[0]->setFrameX(indexX);
			_count = 0;
			indexX++;
			if (indexX > snake[0]->getMaxFrameX())indexX = 0;
		}

	}


	if (next == 0)
	{
		next = RND->getFromIntTo(3, 7);
		findway = RND->getInt(4);
	}
	_action->update();
	_rc = RectMake(snakeI->getX(), snakeI->getY(), snakeI->getFrameWidth(), snakeI->getFrameHeight());
}

void snake::render()
{
	if (PRINTMANAGER->isDebug())
	{
		Rectangle(getMemDC(), _rc);
	}
	draw();

}

void snake::draw()
{
	if (_state == SNAKE_MOVE)
	{
		snake[0]->frameRender(getMemDC(), snakeI->getX(), snakeI->getY(), indexX, indexY);
	}
	//if (_state == BOTTOM_SHIFT || _state == TOP_SHIFT || _state == LEFT_SHIFT || _state == RIGHT_SHIFT)
	//{
	//	scout[1]->frameRender(getMemDC(), scoutI->getX(), scoutI->getY(), indexH, indexY);
	//}
}

void snake::hitDamage(float damage)
{
	currentHP -= damage;
}

HRESULT mouse::init()
{
	
	return S_OK;
}

HRESULT mouse::init(POINT position)
{
	mouse[0] = IMAGEMANAGER->addFrameImage("mouseMX", "img/enemy/mouse move mix.bmp", 96, 192, 2, 4, true, RGB(255, 0, 255));
	mouse[1] = IMAGEMANAGER->addFrameImage("mouseIMX", "img/enemy/mouse idle mix.bmp", 96, 192, 2, 4, true, RGB(255, 0, 255));
	
	

	x = position.x;
	y = position.y;

	mouseI = mouse[0];
	mouseI->setX(x);
	mouseI->setY(y);
	_state = MOUSE_IDLE;
	_action = new action;
	_action->init();

	next = RND->getFromIntTo(4, 10);
	findway = RND->getInt(4);
	direction = RND->getInt(4);
	indexY = direction;
	indexH = findway;
	maxHP = currentHP = 30;
	z = 1;
	idle = next + 2;

	_rc = RectMake(mouseI->getX(), mouseI->getY(), mouseI->getFrameWidth(), mouseI->getFrameHeight());

	indexX = 0;
	indexH = 0;
	return S_OK;
}

void mouse::release()
{
}

void mouse::update()
{
	if (findway == 0 && (next <= 0 || next < idle))_state = MOUSE_IDLE;
	if (findway == 1 && (next <= 0 || next < idle))_state = MOUSE_IDLE;
	if (findway == 2 && (next <= 0 || next < idle))_state = MOUSE_IDLE;
	if (findway == 3 && (next <= 0 || next < idle))_state = MOUSE_IDLE;
	if (direction == 0 && next > 0 && next >= idle)_state = MOUSE_MOVE;
	if (direction == 1 && next > 0 && next >= idle)_state = MOUSE_MOVE;
	if (direction == 2 && next > 0 && next >= idle)_state = MOUSE_MOVE;
	if (direction == 3 && next > 0 && next >= idle)_state = MOUSE_MOVE;
	indexY = direction;


	_count++;
	movecount++;
	if (_count >= 10)
	{
		if (_state == MOUSE_MOVE)
		{
			mouse[0]->setFrameY(indexY);
			mouse[0]->setFrameX(indexX);
			_count = 0;
			indexX++;
			if (indexX > mouse[0]->getMaxFrameX())indexX = 0;
		}
		if (_state == MOUSE_IDLE)
		{
			mouse[1]->setFrameY(indexY);
			mouse[1]->setFrameX(indexH);
			idle--;
			_count = 0;
			indexH++;
			if (indexH > mouse[0]->getMaxFrameX())indexH = 0;
		}
	}
	if (movecount > 20 && next > 0 && next >= idle)
	{
		movecount = 0;
		if (direction == 0)_action->moveTo(mouseI, mouseI->getX(), mouseI->getY() + 30, 0.3f);
		if (direction == 1)_action->moveTo(mouseI, mouseI->getX(), mouseI->getY() - 30, 0.3f);
		if (direction == 2)_action->moveTo(mouseI, mouseI->getX() - 30, mouseI->getY(), 0.3f);
		if (direction == 3)_action->moveTo(mouseI, mouseI->getX() + 30, mouseI->getY(), 0.3f);
		next--;
		idle--;
	}
	if (idle < -5)
	{
		next = RND->getFromIntTo(3, 7);
		direction = findway;
		findway = RND->getInt(4);
		idle = next + 2;
	}
	_action->update();
	_rc = RectMake(mouseI->getX(), mouseI->getY(), mouseI->getFrameWidth(), mouseI->getFrameHeight());
}

void mouse::render()
{
	if (PRINTMANAGER->isDebug())
	{
		Rectangle(getMemDC(), _rc);
	}
	draw();
}

void mouse::draw()
{
	if (_state == MOUSE_MOVE)
	{
		mouse[0]->frameRender(getMemDC(), mouseI->getX(), mouseI->getY(), indexX, indexY);
	}
	if (_state == MOUSE_IDLE)
	{
		mouse[1]->frameRender(getMemDC(), mouseI->getX(), mouseI->getY(), indexH, indexY);
	}
}

void mouse::hitDamage(float damage)
{
	currentHP -= damage;
}

HRESULT blue::init()
{
	
	return S_OK;
}

HRESULT blue::init(POINT position)
{
	blue[0] = IMAGEMANAGER->addFrameImage("blueMX", "img/enemy/blue move mix.bmp", 762, 729, 4, 4, true, RGB(255, 0, 255));
	blue[1] = IMAGEMANAGER->addFrameImage("blueSMX", "img/enemy/blue search mix.bmp", 762, 729, 4, 4, true, RGB(255, 0, 255));


	x = position.x;
	y = position.y;

	blueI = blue[0];
	blueI->setX(x);
	blueI->setY(y);
	_state = BLUE_MOVE;
	_action = new action;
	_action->init();


	next = RND->getFromIntTo(5, 8);
	findway = RND->getInt(4);
	direction = RND->getInt(4);

	indexX = 0;
	indexY = direction;
	indexH = findway;
	maxHP = currentHP = 30;
	z = 1;

	radius = 300;
	_rc = RectMakeCenter(x, y, 80, 112);

	return S_OK;
}

void blue::release()
{
}

void blue::update()
{
	if (findway == 0 && next <= 0)_state = BLUE_SEARCH;
	if (findway == 1 && next <= 0)_state = BLUE_SEARCH;
	if (findway == 2 && next <= 0)_state = BLUE_SEARCH;
	if (findway == 3 && next <= 0)_state = BLUE_SEARCH;
	if (direction == 0 && next > 0)_state = BLUE_MOVE;
	if (direction == 1 && next > 0)_state = BLUE_MOVE;
	if (direction == 2 && next > 0)_state = BLUE_MOVE;
	if (direction == 3 && next > 0)_state = BLUE_MOVE;
	indexY = direction;

	_count++;
	movecount++;
	if (_count >= 20)
	{
		if (_state == BLUE_MOVE)
		{
			blue[0]->setFrameY(indexY);
			blue[0]->setFrameX(indexX);
			_count = 0;
			indexX++;
			if (indexX > blue[0]->getMaxFrameX())indexX = 0;
		}
		if (_state == BLUE_SEARCH)
		{

			blue[1]->setFrameY(indexY);
			if (direction == 0 && indexH == 0)indexH++;
			if (direction == 1 && indexH == 0)indexH++;
			if (direction == 2 && indexH == 3)indexH++;
			if (direction == 3 && indexH == 2)indexH++;
			blue[1]->setFrameX(indexH);
			indexH++;
			if (indexH > blue[1]->getMaxFrameX())indexH = 0;
			next--;
			_count = 0;
		}

	}

	if (movecount >= 20 && next > 0)
	{
		movecount = 0;
		if (direction == 0)_action->moveTo(blueI, blueI->getX(), blueI->getY() + 30, 0.3f);
		if (direction == 1)_action->moveTo(blueI, blueI->getX(), blueI->getY() - 30, 0.3f);
		if (direction == 2)_action->moveTo(blueI, blueI->getX() - 30, blueI->getY(), 0.3f);
		if (direction == 3)_action->moveTo(blueI, blueI->getX() + 30, blueI->getY(), 0.3f);
		next--;
	}

	if (direction == 0 && findway == 1)findway = RND->getInt(4);
	if (direction == 1 && findway == 0)findway = RND->getInt(4);
	if (direction == 2 && findway == 3)findway = RND->getInt(4);
	if (direction == 3 && findway == 2)findway = RND->getInt(4);

	if (next < -5)
	{
		next = RND->getFromIntTo(5, 8);
		if (direction == 0)direction = 1;
		else if (direction == 1)direction = 0;
		else if (direction == 2)direction = 3;
		else if (direction == 3)direction = 2;
		findway = RND->getInt(4);
	}
	_action->update();
	_rc = RectMake(blueI->getX() + (blueI->getFrameWidth() / 4), blueI->getY() + (blueI->getFrameHeight() / 4), blueI->getFrameWidth() / 2, blueI->getFrameHeight() / 2);
}

void blue::render()
{
	if (PRINTMANAGER->isDebug())
	{
		EllipseMakeCenter(getMemDC(), blueI->getX() + blueI->getFrameWidth() / 2, blueI->getY() + blueI->getFrameHeight() / 2, radius * 2, radius * 2);
		Rectangle(getMemDC(), _rc);

	}
	draw();
}

void blue::draw()
{
	if (_state == BLUE_MOVE)
	{
		blue[0]->frameRender(getMemDC(), blueI->getX(), blueI->getY(), indexX, indexY);
	}
	if (_state == BLUE_SEARCH)
	{
		blue[1]->frameRender(getMemDC(), blueI->getX(), blueI->getY(), indexH, indexY);
	}
}

void blue::hitDamage(float damage)
{
	currentHP -= damage;
}

HRESULT green::init()
{
	
	return S_OK;
}

HRESULT green::init(POINT position)
{
	green[0] = IMAGEMANAGER->addFrameImage("greenMX", "img/enemy/green move mix.bmp", 762, 729, 4, 4, true, RGB(255, 0, 255));
	green[1] = IMAGEMANAGER->addFrameImage("greenSMX", "img/enemy/green search mix.bmp", 762, 729, 4, 4, true, RGB(255, 0, 255));


	x = position.x;
	y = position.y;

	greenI = green[0];
	greenI->setX(x);
	greenI->setY(y);
	_state = GREEN_MOVE;
	_action = new action;
	_action->init();


	next = RND->getFromIntTo(5, 8);
	findway = RND->getInt(4);
	direction = RND->getInt(4);
	indexY = direction;
	indexH = findway;
	maxHP = currentHP = 30;
	z = 1;

	radius = 300;
	_rc = RectMakeCenter(x, y, 80, 112);

	indexX = 0;
	return S_OK;
}

void green::release()
{
}

void green::update()
{
	if (findway == 0 && next <= 0)_state = GREEN_SEARCH;
	if (findway == 1 && next <= 0)_state = GREEN_SEARCH;
	if (findway == 2 && next <= 0)_state = GREEN_SEARCH;
	if (findway == 3 && next <= 0)_state = GREEN_SEARCH;
	if (direction == 0 && next > 0)_state = GREEN_MOVE;
	if (direction == 1 && next > 0)_state = GREEN_MOVE;
	if (direction == 2 && next > 0)_state = GREEN_MOVE;
	if (direction == 3 && next > 0)_state = GREEN_MOVE;
	indexY = direction;

	_count++;
	movecount++;
	if (_count >= 20)
	{
		if (_state == GREEN_MOVE)
		{
			green[0]->setFrameY(indexY);
			green[0]->setFrameX(indexX);
			_count = 0;
			indexX++;
			if (indexX > green[0]->getMaxFrameX())indexX = 0;
		}
		if (_state == GREEN_SEARCH)
		{

			green[1]->setFrameY(indexY);
			if (direction == 0 && indexH == 0)indexH++;
			if (direction == 1 && indexH == 0)indexH++;
			if (direction == 2 && indexH == 3)indexH++;
			if (direction == 3 && indexH == 2)indexH++;
			green[1]->setFrameX(indexH);
			indexH++;
			if (indexH > green[1]->getMaxFrameX())indexH = 0;
			next--;
			_count = 0;
		}

	}

	if (movecount >= 20 && next > 0)
	{
		movecount = 0;
		if (direction == 0)_action->moveTo(greenI, greenI->getX(), greenI->getY() + 30, 0.3f);
		if (direction == 1)_action->moveTo(greenI, greenI->getX(), greenI->getY() - 30, 0.3f);
		if (direction == 2)_action->moveTo(greenI, greenI->getX() - 30, greenI->getY(), 0.3f);
		if (direction == 3)_action->moveTo(greenI, greenI->getX() + 30, greenI->getY(), 0.3f);
		next--;
	}

	if (direction == 0 && findway == 1)findway = RND->getInt(4);
	if (direction == 1 && findway == 0)findway = RND->getInt(4);
	if (direction == 2 && findway == 3)findway = RND->getInt(4);
	if (direction == 3 && findway == 2)findway = RND->getInt(4);

	if (next < -5)
	{
		next = RND->getFromIntTo(5, 8);
		if (direction == 0)direction = 1;
		else if (direction == 1)direction = 0;
		else if (direction == 2)direction = 3;
		else if (direction == 3)direction = 2;
		findway = RND->getInt(4);
	}
	_action->update();
	_rc = RectMake(greenI->getX() + (greenI->getFrameWidth() / 4), greenI->getY() + (greenI->getFrameHeight() / 4), greenI->getFrameWidth() / 2, greenI->getFrameHeight() / 2);
}

void green::render()
{
	if (PRINTMANAGER->isDebug())
	{
		EllipseMakeCenter(getMemDC(), greenI->getX() + greenI->getFrameWidth() / 2, greenI->getY() + greenI->getFrameHeight() / 2, radius * 2, radius * 2);
		Rectangle(getMemDC(), _rc);

	}
	draw();
}

void green::draw()
{
	if (_state == BLUE_MOVE)
	{
		green[0]->frameRender(getMemDC(), greenI->getX(), greenI->getY(), indexX, indexY);
	}
	if (_state == BLUE_SEARCH)
	{
		green[1]->frameRender(getMemDC(), greenI->getX(), greenI->getY(), indexH, indexY);
	}
}

void green::hitDamage(float damage)
{
	currentHP -= damage;
}
