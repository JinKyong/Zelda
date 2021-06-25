#include "stdafx.h"
#include "testStage.h"
#include "Player.h"

HRESULT testStage::init(Player * player)
{
	Scene::init(player);

	//스테이지 배경
	_background = IMAGEMANAGER->addImage("testStage", "img/stage/sample.bmp", MAPWIDTH + 1, MAPHEIGHT + 1, false, RGB(0, 0, 0));
	//카메라 최대범위
	CAMERAMANAGER->setBackScreenSize(MAPWIDTH * TILEX, MAPHEIGHT * TILEY);
	//스테이지 타일 생성
	TILEMANAGER->initMap(_background);

	return S_OK;
}

void testStage::release()
{
}

void testStage::update()
{
	//카메라 스크린 갱신
	CAMERAMANAGER->updateScreen(_player->getX(), _player->getY());
	//이미지 클리핑 + z-order
	TILEMANAGER->update();
}

void testStage::render()
{
	TILEMANAGER->render(getMemDC());
}

void testStage::changeScene()
{
	//씬이 바뀌는 부분(경계) 설정해줘서 씬 바뀌도록
}