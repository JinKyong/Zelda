#include "stdafx.h"
#include "tileManager.h"
#include "Player.h"

HRESULT tileManager::init(Player* player)
{
	_player = player;

	//모든 타일 이미지 등록
	addTileImages();

	return S_OK;
}

HRESULT tileManager::initMap(image * img)
{
	//배경 이미지
	_background = img;

	//타일 생성
	for (int i = 0; i < _background->getHeight(); i++)
		for (int j = 0; j < _background->getWidth(); j++)
			createTile(j, i);

	return S_OK;
}

void tileManager::release()
{
	tileIter iter = _mapGTile.begin();
	//벡터 비우기
	for (; iter != _mapGTile.end();) {
		if ((*iter) != nullptr) {
			SAFE_DELETE((*iter));
			iter = _mapGTile.erase(iter);
		}
		else ++iter;
	}

	iter = _mapBTile.begin();
	//벡터 비우기
	for (; iter != _mapBTile.end();) {
		if ((*iter) != nullptr) {
			SAFE_DELETE((*iter));
			iter = _mapBTile.erase(iter);
		}
		else ++iter;
	}

	_mapGTile.clear();
	_mapBTile.clear();
}

void tileManager::update()
{
	updateTile();
	//플레이어 추가
	_renderTile.push_back(new TILE(0, 0, PLAYER, _player->getX(), _player->getY(), _player->getZ(), nullptr));
	//에너미 추가
	//

	sort(_renderTile.begin(), _renderTile.end(), compare);
}

void tileManager::render(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(72, 152, 72));
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

	RECT rc = CAMERAMANAGER->getScreen();
	Rectangle(hdc, rc);

	SelectObject(hdc, oldbrush);
	DeleteObject(brush);
	////베이스 뿌리기
	//for (; iter != _renderTile.end(); ++iter)
	//	IMAGEMANAGER->findImage(BASE)->render(hdc, (*iter)->x, (*iter)->y);


	tileIter iter = _renderTile.begin();

	//객체 뿌리기
	for (; iter != _renderTile.end(); ++iter) {
		switch ((*iter)->b) {
		case PLAYER:
			//디버깅
			if (PRINTMANAGER->isDebug()) {
				RECT rc = _player->getBody();
				Rectangle(hdc, rc);
			}
			STATEMANAGER->render(hdc);
			break;

		default:
			if ((*iter)->img == nullptr) continue;

			//디버깅
			if (PRINTMANAGER->isDebug()) {
				Rectangle(hdc, (*iter)->body);
			}
			(*iter)->img->render(hdc, (*iter)->x, (*iter)->y);
			break;
		}
	}
}

void tileManager::addTileImages()
{
	char str[128];

	//========= bush =========//
	IMAGEMANAGER->addImage(BUSH, "img/tile/bush/bush.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BUSHOFF, "img/tile/bush/bush_off.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(GRASS, "img/tile/bush/grass.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(GRASSOFF, "img/tile/bush/grass_off.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(WEED, "img/tile/bush/weed.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(RUG, "img/tile/bush/rug.bmp", TILEX, TILEY, true, RGB(255, 0, 255));

	//========= tree =========//
	for (int i = 1, j = TREELEAF1; j <= TREELEAF8; i++, j++) {
		sprintf_s(str, "img/tile/tree/treeLeaf%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = TREELEAFINTER1; j <= TREELEAFINTER2; i++, j++) {
		sprintf_s(str, "img/tile/tree/treeLeafInter%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = TREESTUMP1; j <= TREESTUMP12; i++, j++) {
		sprintf_s(str, "img/tile/tree/treeStump%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = TREESTUMPINTER1; j <= TREESTUMPINTER3; i++, j++) {
		sprintf_s(str, "img/tile/tree/treeStumpInter%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}

	//========= stone =========//
	IMAGEMANAGER->addImage(STONE, "img/tile/stone/stone.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(STONEB, "img/tile/stone/stoneBlack.bmp", TILEX, TILEY, true, RGB(255, 0, 255));
	for (int i = 1, j = BIGSTONE1; j <= BIGSTONE4; i++, j++) {
		sprintf_s(str, "img/tile/stone/bigStone%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = BIGSTONEB1; j <= BIGSTONEB4; i++, j++) {
		sprintf_s(str, "img/tile/stone/bigStoneBlack%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = ST5NE1; j <= ST5NE4; i++, j++) {
		sprintf_s(str, "img/tile/stone/st5ne%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}

	//========= house =========//
	for (int i = 1, j = HOUSE1; j <= HOUSE38; i++, j++) {
		sprintf_s(str, "img/tile/house/%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}



	//========= ground =========//
	for (int i = 1, j = FENCE1; j <= FENCE5; i++, j++) {
		sprintf_s(str, "img/tile/ground/fence%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}

	for (int i = 1, j = CLIFF1; j <= CLIFF27; i++, j++) {
		sprintf_s(str, "img/tile/ground/cliff%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = CLIFFIN1; j <= CLIFFIN10; i++, j++) {
		sprintf_s(str, "img/tile/ground/cliffIn%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
}

void tileManager::createTile(float x, float y)
{
	COLORREF rgb = GetPixel(_background->getMemDC(), x, y);

	_mapGTile.push_back(makeTile(x * TILEX, y * TILEY, GetGValue(rgb)));
	_mapBTile.push_back(makeTile(x * TILEX, y * TILEY, GetBValue(rgb)));
}

void tileManager::updateTile()
{
	RECT _screen = CAMERAMANAGER->getScreen();

	int initY = _screen.top / TILEY;
	int endY = _screen.bottom / TILEY;
	int initX = _screen.left / TILEX;
	int endX = _screen.right / TILEX;

	int cols = _screen.right / TILEX - _screen.left / TILEX + 1;
	int width = _background->getWidth();

	int size = (endY - initY + 1) * cols;

	_renderTile.clear();
	_renderTile.resize(size * 2);

	tileIter iter;
	for (int i = initY, j = 0; i <= endY; i++, j++) {
		iter = _mapBTile.begin() + (i * width + initX);
		copy(iter, iter + cols, _renderTile.begin() + j * cols);
	}
	for (int i = initY, j = 0; i <= endY; i++, j++) {
		iter = _mapGTile.begin() + (i * width + initX);
		copy(iter, iter + cols, _renderTile.begin() + size + j * cols);
	}
}

bool tileManager::compare(PTILE a, PTILE b)
{
	if (a->z == b->z)	return a->body.bottom < b->body.bottom;
	else				return a->z < b->z;
}