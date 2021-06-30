#include "stdafx.h"
#include "playGround.h"
#include "testStage.h"
#include "stage1.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

//���
//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init(true);

	_player = new Player;
	_player->init();

	INVENTORYMANAGER->init();

	TILEMANAGER->init(_player);
	SCENEMANAGER->init(_player);
	UIMANAGER->init(_player);

	SCENEMANAGER->addScene("test", new testStage);
	SCENEMANAGER->addScene("stage1", new stage1);

	SCENEMANAGER->changeScene("stage1");

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

	INVENTORYMANAGER->release();
	INVENTORYMANAGER->releaseSingleton();

	TILEMANAGER->release();
	TILEMANAGER->releaseSingleton();

	UIMANAGER->release();
	UIMANAGER->releaseSingleton();

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
		if (INVENTORYMANAGER->isOpen())
		{
			//SCENEMANAGER->changeScene("inven");
			INVENTORYMANAGER->setOpen(false);
		}
		else
		{
			//SCENEMANAGER->changeScene("����");
			INVENTORYMANAGER->setOpen(true);
		}
	}

	if (INVENTORYMANAGER->isOpen()) INVENTORYMANAGER->update();
	
	_player->update();

	UIMANAGER->update();
	SCENEMANAGER->update();
	//CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
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
	UIMANAGER->render(getMemDC());

	if (INVENTORYMANAGER->isOpen()) INVENTORYMANAGER->render(getMemDC());

	//���� �귯��
	/*HBRUSH myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), myBrush);

	HPEN myPen = (HPEN)CreatePen(1, 2, RGB(255, 0, 0));
	SelectObject(getMemDC(), myPen);

	SelectObject(getMemDC(), oldBrush);
	DeleteObject(myPen);
	DeleteObject(myBrush);*/

	//==================================================s
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(getHDC(), 0, 0, getMemDC());
}