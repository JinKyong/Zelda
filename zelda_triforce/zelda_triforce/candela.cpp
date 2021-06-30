#include "stdafx.h"
#include "candela.h"

HRESULT candela::init(float x, float y, float z)
{
	RECT camera = CAMERAMANAGER->getScreen();
	_img = IMAGEMANAGER->addImage("candela", "img/equip/candela2.bmp", 64, 64, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_z = z;
	_invX = 128;
	_invY = 124 + 96 * 2;
	_rc = RectMakeCenter(_x, _y, 64, 64);
	_type = CANDELA;

	return S_OK;
}

void candela::release()
{
}

void candela::update()
{
}

void candela::render(HDC hdc, float x, float y)
{
	_img->render(hdc, x, y);
}

void candela::useItem()
{
}
