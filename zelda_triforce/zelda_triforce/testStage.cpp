#include "stdafx.h"
#include "testStage.h"
#include "Player.h"

HRESULT testStage::init(Player * player)
{
	Scene::init(player);

	_background = IMAGEMANAGER->addImage("testStage", "img/stage/sample1.bmp", MAPWIDTH + 1, MAPHEIGHT + 1, false, RGB(0, 0, 0));
	CAMERAMANAGER->setBackScreenSize(MAPWIDTH * TILEX, MAPHEIGHT * TILEY);
	TILEMANAGER->initMap(_background, RGB(72, 152, 72));

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
	//Z순서 맞춰주기 필요(던전에서는)
	for (int i = Z0; i < Z4; i += 2) {
		if (_player->getZ() < i)
			_player->render();
		TILEMANAGER->render(getMemDC(), i);
	}
}

void testStage::changeScene()
{
}