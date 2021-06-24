#include "stdafx.h"
#include "testStage.h"
#include "Player.h"

HRESULT testStage::init(Player * player)
{
	Scene::init(player);

	_background = IMAGEMANAGER->addImage("testStage", "img/stage/sample_back.bmp", MAPWIDTH + TILEX, MAPHEIGHT + TILEY, false, RGB(0, 0, 0));
	CAMERAMANAGER->setBackScreenSize(MAPWIDTH, MAPHEIGHT);
	TILEMANAGER->initMap(_background);

	return S_OK;
}

void testStage::release()
{
}

void testStage::update()
{
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
	TILEMANAGER->update();
}

void testStage::render()
{
	TILEMANAGER->render(getMemDC());
}

void testStage::changeScene()
{
}