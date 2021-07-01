#include "stdafx.h"
#include "enemyManager.h"

HRESULT enemyManager::init()
{
	_fire = new fireball;
	_fire->init(0, 500);
	_circul = new circulator;
	_circul->init(0, 500);
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
	_fire->update();
	_circul->update();
	
	fire();
	circulfire();
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
	_fire->render();
	_circul->render();
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

void enemyManager::fire()
{
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		if ((*_viBoss)->getD()==0&&(*_viBoss)->getPattern()==0&&!(*_viBoss)->getLightning())
		{
			
			if ((*_viBoss)->getaC()>=17)
			{
				_fire->setIndexY(0);
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx + (rc.right - rc.left) / 2, rc.bottom,
					getAngle(fx + (rc.right - rc.left) / 2, rc.bottom, 
						_ptMouse.x+CAMERAMANAGER->getScreen().left,
						_ptMouse.y+CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 1 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			
			if ((*_viBoss)->getaC() >= 17)
			{
				_fire->setIndexY(1);
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx + (rc.right - rc.left) / 2, rc.top,
					getAngle(fx + (rc.right - rc.left) / 2, rc.top,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 2 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			
			if ((*_viBoss)->getaC() >= 17)
			{
				_fire->setIndexY(2);
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx , fy+(rc.bottom-rc.top)/2,
					getAngle(fx, fy + (rc.bottom - rc.top) / 2,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 3 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			
			if ((*_viBoss)->getaC() >= 17)
			{
				_fire->setIndexY(3);
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(rc.right, fy + (rc.bottom - rc.top) / 2,
					getAngle(rc.right, fy + (rc.bottom - rc.top) / 2,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 4 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			
			if ((*_viBoss)->getaC() >= 17)
			{
				_fire->setIndexY(4);
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx, rc.bottom,
					getAngle(fx, rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 5 && (*_viBoss)->getPattern() == 0 && !(*_viBoss)->getLightning())
		{
			
			if ((*_viBoss)->getaC() >= 17)
			{
				_fire->setIndexY(5);
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_fire->fire(fx + (rc.right - rc.left), rc.bottom,
					getAngle(fx + (rc.right - rc.left), rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}

		
	}
}

void enemyManager::circulfire()
{
	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		if ((*_viBoss)->getD() == 0 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{

			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx + (rc.right - rc.left) / 2, rc.bottom,
					getAngle(fx + (rc.right - rc.left) / 2, rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 1 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{

			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx + (rc.right - rc.left) / 2, rc.top,
					getAngle(fx + (rc.right - rc.left) / 2, rc.top,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 2 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{

			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx, fy + (rc.bottom - rc.top) / 2,
					getAngle(fx, fy + (rc.bottom - rc.top) / 2,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 3 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{
			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(rc.right, fy + (rc.bottom - rc.top) / 2,
					getAngle(rc.right, fy + (rc.bottom - rc.top) / 2,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 4 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{
			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx, rc.bottom,
					getAngle(fx, rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
		if ((*_viBoss)->getD() == 5 && (*_viBoss)->getPattern() == 1 && !(*_viBoss)->getLightning())
		{

			if ((*_viBoss)->getaC() >= 17)
			{
				float fx = (*_viBoss)->getI()->getX();
				float fy = (*_viBoss)->getI()->getY();
				RECT rc = (*_viBoss)->getRect();
				_circul->fire(fx + (rc.right - rc.left), rc.bottom,
					getAngle(fx + (rc.right - rc.left), rc.bottom,
						_ptMouse.x + CAMERAMANAGER->getScreen().left,
						_ptMouse.y + CAMERAMANAGER->getScreen().top), 3.0f);
				break;
			}
		}
	}
}

//void enemyManager::spread()
//{
//}
