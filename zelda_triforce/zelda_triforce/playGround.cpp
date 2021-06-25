#include "stdafx.h"
#include "playGround.h"
#include "testStage.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init(true);

	_player = new Player;
	_player->init();

	IMAGEMANAGER->addImage("bmrang", "img/equip/boomerang.bmp", 64, 64, true, PINK);
	IMAGEMANAGER->addImage("candela", "img/equip/candela2.bmp", 64, 64, true, PINK);
	IMAGEMANAGER->addImage("mushroom", "img/equip/mushroom.bmp", 64, 64, true, PINK);

	TILEMANAGER->init(_player);
	SCENEMANAGER->init(_player);

	SCENEMANAGER->addScene("test", new testStage);
	SCENEMANAGER->addScene("inven", new inventory); //!!

	SCENEMANAGER->changeScene("test");

	_invOpen = false;
	_debug = false;

	return S_OK;
}

HRESULT playGround::init(const char * str)
{
	gameNode::init(true);

	_debug = false;

	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();

	TILEMANAGER->release();
	TILEMANAGER->releaseSingleton();

	SCENEMANAGER->release();
	SCENEMANAGER->releaseSingleton();
}


void playGround::update()
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
		_debug = !_debug;
		PRINTMANAGER->setDebug(_debug);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (!_invOpen)
		{
			SCENEMANAGER->changeScene("inven");
			_invOpen = true;
		}
		else
		{
			SCENEMANAGER->changeScene("����");
			_invOpen = false;
		}
	}

	_player->update();
	SCENEMANAGER->update();
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//================���� �� ���̿� �� �׸��ô�==========================

	//���� ���� ���
	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	//_player->render();
	SCENEMANAGER->render();

	//���� �귯��
	/*HBRUSH myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), myBrush);

	HPEN myPen = (HPEN)CreatePen(1, 2, RGB(255, 0, 0));
	SelectObject(getMemDC(), myPen);

	SelectObject(getMemDC(), oldBrush);
	DeleteObject(myPen);
	DeleteObject(myBrush);*/

	//==================================================
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(getHDC(), 0, 0, getMemDC());
}