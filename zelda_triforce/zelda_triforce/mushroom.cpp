#include "stdafx.h"
#include "mushroom.h"

HRESULT mushroom::init(float x, float y)
{
	_img = IMAGEMANAGER->addImage("mushroom", "img/equip/mushroom.bmp", 64, 64, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_rc = RectMakeCenter(_x, _y, 64, 64);
	_type = MUSHROOM;
	return S_OK;
}

void mushroom::release()
{
}

void mushroom::update()
{
}

void mushroom::render(HDC hdc)
{
	_img->render(hdc, _rc.left, _rc.top);
}

void mushroom::useItem()
{
}
