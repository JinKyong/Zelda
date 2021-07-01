#include "stdafx.h"
#include "halfHeart.h"

HRESULT halfHeart::init(float x, float y, float z)
{
	RECT camera = CAMERAMANAGER->getScreen();
	_img = IMAGEMANAGER->addImage("halfHeart", "img/item/half_heart.bmp", 32, 32, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_z = z;
	_rc = RectMakeCenter(_x, _y, 32, 32);
	_type = HEART;

	return S_OK;
}

void halfHeart::release()
{
}

void halfHeart::update()
{
}

void halfHeart::render(HDC hdc, float x, float y)
{
	_img->render(hdc, x, y);
}
