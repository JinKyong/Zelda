#include "stdafx.h"
#include "testStage.h"
#include "Player.h"

HRESULT testStage::init(Player * player)
{
	Scene::init(player);

	//�������� ���
	_background = IMAGEMANAGER->addImage("testStage", "img/stage/sample.bmp", MAPWIDTH + 1, MAPHEIGHT + 1, false, RGB(0, 0, 0));
	//ī�޶� �ִ����
	CAMERAMANAGER->setBackScreenSize(MAPWIDTH * TILEX, MAPHEIGHT * TILEY);
	//�������� Ÿ�� ����
	TILEMANAGER->initMap(_background);

	return S_OK;
}

void testStage::release()
{
}

void testStage::update()
{
	//ī�޶� ��ũ�� ����
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
	//�̹��� Ŭ���� + z-order
	TILEMANAGER->update();
}

void testStage::render()
{
	TILEMANAGER->render(getMemDC());
}

void testStage::changeScene()
{
	//���� �ٲ�� �κ�(���) �������༭ �� �ٲ��
}