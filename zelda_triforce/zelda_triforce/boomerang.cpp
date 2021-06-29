#include "stdafx.h"
#include "boomerang.h"

HRESULT boomerang::init(float x, float y)
{
	_img = IMAGEMANAGER->addImage("boomerang", "img/equip/boomerang.bmp", 64, 64, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, 64, 64);
	_type = BOOMERANG;
	return S_OK;
}

void boomerang::release()
{
}

void boomerang::update()
{
}

void boomerang::render(HDC hdc)
{
	_img->render(hdc, _rc.left, _rc.top);
}

void boomerang::useItem()
{
}