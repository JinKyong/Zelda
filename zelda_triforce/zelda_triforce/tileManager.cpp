#include "stdafx.h"
#include "tileManager.h"
#include "Player.h"

HRESULT tileManager::init(Player* player)
{
	_player = player;

	//��� Ÿ�� �̹��� ���
	addTileImages();

	return S_OK;
}

HRESULT tileManager::initMap(image * img, COLORREF rgb)
{
	//��� �̹���
	_background = img;
	_backColor = rgb;

	_mapBTile.clear();
	_mapGTile.clear();

	//Ÿ�� ����
	for (int i = 0; i < _background->getHeight(); i++)
		for (int j = 0; j < _background->getWidth(); j++)
			createTile(j, i);

	return S_OK;
}

void tileManager::release()
{
	tileIter iter = _mapGTile.begin();
	//���� ����
	for (; iter != _mapGTile.end();) {
		if ((*iter) != nullptr) {
			SAFE_DELETE((*iter));
			iter = _mapGTile.erase(iter);
		}
		else ++iter;
	}

	iter = _mapBTile.begin();
	//���� ����
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
	//�̹���Ŭ����
	updateTile();

	//sort(_renderTile.begin(), _renderTile.end(), compare);
	sort(_renderBTile.begin(), _renderBTile.end(), compare);
	sort(_renderGTile.begin(), _renderGTile.end(), compare);
}

void tileManager::render(HDC hdc, int z)
{
	if (z == 0) {
		//���̽� �Ѹ���
		HBRUSH brush = CreateSolidBrush(_backColor);
		FillRect(hdc, &CAMERAMANAGER->getScreen(), brush);
		DeleteObject(brush);

		_BTileIter = _renderBTile.begin();
		_GTileIter = _renderGTile.begin();
	}

	//��ü �Ѹ���(B)
	for (; _BTileIter != _renderBTile.end(); ++_BTileIter) {
		if ((*_BTileIter)->z > z) break;

		//�����
		if (PRINTMANAGER->isDebug()) {
			Rectangle(hdc, (*_BTileIter)->body);
		}

		(*_BTileIter)->img->render(hdc, (*_BTileIter)->x, (*_BTileIter)->y);
	}


	//��ü �Ѹ���(G)
	for (; _GTileIter != _renderGTile.end(); ++_GTileIter) {
		if ((*_GTileIter)->z > z) break;

		//�����
		if (PRINTMANAGER->isDebug()) {
			Rectangle(hdc, (*_GTileIter)->body);
		}

		(*_GTileIter)->img->render(hdc, (*_GTileIter)->x, (*_GTileIter)->y);
	}
}


void tileManager::createTile(float x, float y)
{
	COLORREF rgb = GetPixel(_background->getMemDC(), x, y);

	if (rgb == EXCOLOR) {
		_mapGTile.push_back(new TILE(0, 0, 0, 0, 0, 0, 0, 0, nullptr));
		_mapBTile.push_back(new TILE(0, 0, 0, 0, 0, 0, 0, 0, nullptr));
	}
	else {
		_mapGTile.push_back(makeTile(x * TILEX, y * TILEY, GetGValue(rgb), GetRValue(rgb)));
		_mapBTile.push_back(makeTile(x * TILEX, y * TILEY, GetBValue(rgb), GetRValue(rgb)));
	}
}

void tileManager::updateTile()
{
	RECT _screen = CAMERAMANAGER->getScreen();

	//���� ���� ���(�̹��� Ŭ����)
	int initY = _screen.top / TILEY - MARGIN;
	int endY = _screen.bottom / TILEY;
	int initX = _screen.left / TILEX - MARGIN;
	int endX = _screen.right / TILEX;


	//����ó��
	if (initY < 0)
		initY = 0;
	if (initX < 0)
		initX = 0;

	//����� Ÿ�� ���� �ʱ�ȭ
	_renderBTile.clear();
	_renderGTile.clear();
	int width = _background->getWidth();


	//���Ÿ�� ����
	for (int i = initY; i <= endY; i++) {
		for (int j = initX; j <= endX; j++) {
			int index = i * width + j;
			if (_mapBTile[index]->img == nullptr) continue;

			_renderBTile.push_back(_mapBTile[index]);
		}
	}
	for (int i = initY; i <= endY; i++) {
		for (int j = initX; j <= endX; j++) {
			int index = i * width + j;
			if (_mapGTile[index]->img == nullptr) continue;

			_renderGTile.push_back(_mapGTile[index]);
		}
	}

	/*int cols = endX - initX + 1;
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
	}*/
}

bool tileManager::compare(PTILE a, PTILE b)
{
	if (a->z == b->z)	return a->body.bottom < b->body.bottom;
	else				return a->z < b->z;
}