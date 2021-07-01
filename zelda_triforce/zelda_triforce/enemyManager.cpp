#include "stdafx.h"
#include "enemyManager.h"

HRESULT enemyManager::init()
{
	_vScout.clear();
	_vGreen.clear();
	_vBlue.clear();
	_vMouse.clear();
	_vSnake.clear();
	_vBoss.clear();

	return	S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viScout = _vScout.begin(); _viScout != _vScout.end(); ++_viScout)
	{
		(*_viScout)->update();
	}
	for (_viGreen = _vGreen.begin(); _viGreen != _vGreen.end(); ++_viGreen)
	{
		(*_viGreen)->update();
	}
	for (_viBlue = _vBlue.begin(); _viBlue != _vBlue.end(); ++_viBlue)
	{
		(*_viBlue)->update();
	}
	for (_viMouse = _vMouse.begin(); _viMouse != _vMouse.end(); ++_viMouse)
	{
		(*_viMouse)->update();
	}
	for (_viSnake = _vSnake.begin(); _viSnake != _vSnake.end(); ++_viSnake)
	{
		(*_viSnake)->update();
	}
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		(*_viBoss)->update();
	}
}

void enemyManager::render(int z)
{
	RECT rc = CAMERAMANAGER->getScreen();

	for (_viScout = _vScout.begin(); _viScout != _vScout.end(); ++_viScout)
	{
		(*_viScout)->render();
	}
	for (_viGreen = _vGreen.begin(); _viGreen != _vGreen.end(); ++_viGreen)
	{
		(*_viGreen)->render();
	}
	for (_viBlue = _vBlue.begin(); _viBlue != _vBlue.end(); ++_viBlue)
	{
		(*_viBlue)->render();
	}
	for (_viMouse = _vMouse.begin(); _viMouse != _vMouse.end(); ++_viMouse)
	{
		RECT tmp;
		if (IntersectRect(&tmp, &rc, &(*_viMouse)->getRect())) {

			if ((*_viMouse)->getZ() < z)
				(*_viMouse)->render();
		}
	}
	for (_viSnake = _vSnake.begin(); _viSnake != _vSnake.end(); ++_viSnake)
	{
		(*_viSnake)->render();
	}
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		(*_viBoss)->render();
	}
}

void enemyManager::setEnemy(int ET, int i, int j)
{
	switch (ET)
	{
	case 0://stage1 : ¹ÚÁã2 ¸¶¸®, ½ºÄ«¿ô 3¸¶¸®
		eScout = new scout;
		eScout->init(PointMake(i, j));
		_vScout.push_back(eScout);
		break;
	case 1:
		eGreen = new green;
		eGreen->init(PointMake(i, j));
		_vGreen.push_back(eGreen);
		break;
	case 2:
		eBlue = new blue;
		eBlue->init(PointMake(i, j));
		_vBlue.push_back(eBlue);
		break;
	case 3:
		eMouse = new mouse;
		eMouse->init(PointMake(i, j));
		_vMouse.push_back(eMouse);
		break;
	case 4:
		eSnake = new snake;
		eSnake->init(PointMake(i, j));
		_vSnake.push_back(eSnake);
		break;
	case 5:
		eBoss = new boss;
		eBoss->init(PointMake(i, j));
		_vBoss.push_back(eBoss);
	}
}

void enemyManager::removeScout(int arrNum)
{
	_vScout.erase(_vScout.begin() + arrNum);
}

void enemyManager::removeBlue(int arrNum)
{
	_vBlue.erase(_vBlue.begin() + arrNum);
}

void enemyManager::removeGreen(int arrNum)
{
	_vGreen.erase(_vGreen.begin() + arrNum);
}

void enemyManager::removeSnake(int arrNum)
{
	_vSnake.erase(_vSnake.begin() + arrNum);
}

void enemyManager::removeMouse(int arrNum)
{
	_vMouse.erase(_vMouse.begin() + arrNum);
}

void enemyManager::removeBoss(int arrNum)
{
	_vBoss.erase(_vBoss.begin() + arrNum);
}
