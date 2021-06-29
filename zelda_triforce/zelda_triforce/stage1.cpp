#include "stdafx.h"
#include "stage1.h"
#include "Player.h"

HRESULT stage1::init(Player * player)
{
	Scene::init(player);

	_background = IMAGEMANAGER->addImage("stage1", "img/stage/stage1_sample.bmp", MAPWIDTH + 1, MAPHEIGHT + 1, false, RGB(0, 0, 0));
	CAMERAMANAGER->setBackScreenSize(MAPWIDTH * TILEX, MAPHEIGHT * TILEY);
	TILEMANAGER->initMap(_background, RGB(72, 152, 72));

	return S_OK;
}

void stage1::release()
{
}

void stage1::update()
{
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
	TILEMANAGER->update();
}

void stage1::render()
{
	//Z순서 맞춰주기 필요(던전에서는)
	for (int i = Z0; i <= Z2; i += 2) {
		if (_player->getZ() < i)
			_player->render();
		TILEMANAGER->render(getMemDC(), i);
	}
}

void stage1::changeScene()
{
}