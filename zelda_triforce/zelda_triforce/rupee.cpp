#include "stdafx.h"
#include "rupee.h"

HRESULT rupee::init(float x, float y, float z)
{
	RECT camera = CAMERAMANAGER->getScreen();
	_img = IMAGEMANAGER->addFrameImage("rupee", "img/item/rupee.bmp", 128, 56, 4, 1, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_z = z;
	_itemRC = RectMakeCenter(_x, _y, 32, 32);
	_type = RUPEE;

	return S_OK;
}

void rupee::release()
{
}

void rupee::update()
{
}

void rupee::render(HDC hdc, float x, float y)
{
}

void rupee::useItem(float x, float y, float angle)
{
}

void rupee::itemMove(float x, float y, float angle)
{
}

void rupee::controlFrame()
{
}
