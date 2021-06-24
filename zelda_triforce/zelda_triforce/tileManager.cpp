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
	_width = _background->getWidth() / TILEX;

	//타일 생성
	for (int i = 0; i < _background->getHeight(); i += TILEY)
		for (int j = 0; j < _background->getWidth(); j += TILEX)
			createTile(j, i);

	return S_OK;
}

void tileManager::release()
{
	tileIter iter = _mapTile.begin();

	//벡터 비우기
	for (; iter != _mapTile.end();) {
		if ((*iter) != nullptr) {
			SAFE_DELETE((*iter));
			iter = _mapTile.erase(iter);
		}
		else ++iter;
	}

	_mapTile.clear();
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
		//플레이어
		if ((*iter)->b == PLAYER)
			Rectangle(hdc, (*iter)->body);
		//타일
		else if ((*iter)->img == nullptr)
			continue;
		else
			(*iter)->img->render(hdc, (*iter)->x, (*iter)->y);
	}
}

void tileManager::addTileImages()
{
	char str[128];

	//======= tree =======//
	for (int i = 1, j = TREELEAF1; i <= TREELEAF10; i++, j++) {
		sprintf_s(str, "img/tile/tree/treeLeaf%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}
	for (int i = 1, j = TREESTUMP1; i <= TREESTUMP10; i++, j++) {
		sprintf_s(str, "img/tile/tree/treeStump%d.bmp", i);
		IMAGEMANAGER->addImage(j, str, TILEX, TILEY, true, RGB(255, 0, 255));
	}


}

void tileManager::createTile(float x, float y)
{
	COLORREF rgb = GetPixel(_background->getMemDC(), x, y);
	int ID = GetBValue(rgb);

	switch (ID) {
	case TREELEAF1:
	case TREELEAF2:
	case TREELEAF3:
	case TREELEAF4:
	case TREELEAF5:
	case TREELEAF6:
	case TREELEAF7:
	case TREELEAF8:
	case TREELEAF9:
	case TREELEAF10:
		_mapTile.push_back(new TILE(PASSABLE, IMMUTABLE, ID,
			x, y, 2, IMAGEMANAGER->findImage(ID)));
		break;

	case TREESTUMP1:
	case TREESTUMP2:
	case TREESTUMP3:
	case TREESTUMP4:
	case TREESTUMP5:
	case TREESTUMP6:
	case TREESTUMP7:
	case TREESTUMP8:
	case TREESTUMP9:
	case TREESTUMP10:
		_mapTile.push_back(new TILE(IMPASSABLE, IMMUTABLE, ID,
			x, y, 0, IMAGEMANAGER->findImage(ID)));
		break;

	default:
		_mapTile.push_back(new TILE(PASSABLE, IMMUTABLE, ID,
			x, y, 0, nullptr));
		break;
	}
}

void tileManager::updateTile()
{
	RECT _screen = CAMERAMANAGER->getScreen();

	int initY = _screen.top / TILEY;
	int endY = _screen.bottom / TILEY;
	int initX = _screen.left / TILEX;
	int endX = _screen.right / TILEX;

	int cols = _screen.right / TILEX - _screen.left / TILEX + 1;

	_renderTile.clear();
	_renderTile.resize((endY - initY + 1) * cols);

	tileIter iter;
	for (int i = initY, j = 0; i <= endY; i++, j++) {
		iter = _mapTile.begin() + (i * _width + initX);
		copy(iter, iter + cols, _renderTile.begin() + j * cols);
	}
}

bool tileManager::compare(PTILE a, PTILE b)
{
	if (a->z == b->z)	return a->body.bottom < b->body.bottom;
	else				return a->z < b->z;
}