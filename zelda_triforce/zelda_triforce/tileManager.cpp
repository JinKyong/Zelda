#include "stdafx.h"
#include "tileManager.h"

HRESULT tileManager::init()
{
	return S_OK;
}

HRESULT tileManager::init(image *img)
{
	//비트맵 이미지 등록
	_map = img;

	//벡터 초기화
	_mapTile.clear();
	_renderTile.clear();

	for (int i = 0; i < _map->getHeight(); i += TILEY) {
		for (int j = 0; j < _map->getWidth(); j += TILEX) {
			_mapTile.push_back(makeTile(j * TILEX, i*TILEY, 0, 255, 255, 255));
		}
	}

	return S_OK;
}

void tileManager::release()
{
}

void tileManager::update()
{
	//카메라 기준으로 render타겟 설정
	//근데 맵 크기를 모르네?
}

void tileManager::render()
{
}

PTILE tileManager::makeTile(float x, float y, float z, int r, int g, int b)
{
	PTILE tile;
	tile = new TILE;

	tile->x = x;
	tile->y = y;
	tile->z = z;
	tile->r = r;
	tile->g = g;
	tile->b = b;

	return tile;
}
