#include "stdafx.h"
#include "boomerang.h"

HRESULT boomerang::init(float x, float y, float z)
{
	_img = IMAGEMANAGER->addImage("boomerang", "img/equip/boomerang.bmp", 64, 64, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_z = 0;
	_rc = RectMakeCenter(_x, _y, 64, 64);
	_type = BOOMERANG;
	return S_OK;
}

void boomerang::release()
{
}

void boomerang::update()
{
	//이건 인벤에서
	RECT camera = CAMERAMANAGER->getScreen();
	_x = camera.left + 160 + 96 * 2;
	_y = camera.top + 154;
	_rc = RectMakeCenter(_x, _y, 64, 64);


	//부메랑을 사용했을 때 맵에서 x,y,z좌표 변동(rect도)
}

void boomerang::render(HDC hdc)
{
	//부메랑을 사용했을 때 이미지 변동
	_img->render(hdc, _rc.left, _rc.top);
}

void boomerang::useItem()
{
}
