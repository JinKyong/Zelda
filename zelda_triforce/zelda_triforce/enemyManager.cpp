#include "stdafx.h"
#include "enemyManager.h"

HRESULT enemyManager::init()
{

	_vBoss.clear();
	_vEnemy.clear();
	return	S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->update();
	}
	
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		(*_viBoss)->update();
	}
}

void enemyManager::render(int z)
{
	RECT rc = CAMERAMANAGER->getScreen();

	
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}
	
	

	//for (_viMouse = _vMouse.begin(); _viMouse != _vMouse.end(); ++_viMouse)
	//{
	//	RECT tmp;
	//	if (IntersectRect(&tmp, &rc, &(*_viMouse)->getRC())) {
	//
	//		if ((*_viMouse)->getZ() < z)
	//			(*_viMouse)->render();
	//	}
	//}
	
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
		_vEnemy.push_back(eScout);
		break;
	case 1:
		eGreen = new green;
		eGreen->init(PointMake(i, j));
		_vEnemy.push_back(eGreen);
		break;
	case 2:
		eBlue = new blue;
		eBlue->init(PointMake(i, j));
		_vEnemy.push_back(eBlue);
		break;
	case 3:
		eMouse = new mouse;
		eMouse->init(PointMake(i, j));
		_vEnemy.push_back(eMouse);
		break;
	case 4:
		eSnake = new snake;
		eSnake->init(PointMake(i, j));
		_vEnemy.push_back(eSnake);
		break;
	case 5:
		eBoss = new boss;
		eBoss->init(PointMake(i, j));
		_vBoss.push_back(eBoss);
	}
}

void enemyManager::removeEnemy(int arrNum)
{
	_vEnemy.erase(_vEnemy.begin() + arrNum);
}

void enemyManager::removeBoss(int arrNum)
{
	_vBoss.erase(_vBoss.begin() + arrNum);
}
