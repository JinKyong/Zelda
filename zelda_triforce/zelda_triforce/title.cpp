#include "stdafx.h"
#include "title.h"
#include "Player.h"

HRESULT title::init(Player * player)
{
	Scene::init(player);

	CAMERAMANAGER->setFade(FADEOUT);
	CAMERAMANAGER->setBackScreenSize(WINSIZEX, WINSIZEY);

	STREAMMANAGER->addVideo("title", "video/title.wmv");
	STREAMMANAGER->playVideo("title");

	_change = false;

	return S_OK;
}

void title::release()
{
	STREAMMANAGER->closeVideo("title");
}

void title::update()
{
	changeScene();
}

void title::render()
{
}

void title::changeScene()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) {
		STREAMMANAGER->closeVideo("title");
		CAMERAMANAGER->setFade(FADEOUT);
		_change = true;
	}

	if (_change) {
		if (CAMERAMANAGER->getAlpha() == 255) {
			SCENEMANAGER->changeScene("stage0");

			_player->setX(WINSIZEX / 2);
			_player->setY(WINSIZEY / 2);
		}
	}
}
