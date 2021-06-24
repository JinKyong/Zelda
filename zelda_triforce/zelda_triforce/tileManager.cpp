#include "stdafx.h"
#include "tileManager.h"

HRESULT tileManager::init()
{
	return S_OK;
}

HRESULT tileManager::init(image *img)
{
	//��Ʈ�� �̹��� ���
	_map = img;

	//���� �ʱ�ȭ
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
	//ī�޶� �������� renderŸ�� ����
	//�ٵ� �� ũ�⸦ �𸣳�?
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
