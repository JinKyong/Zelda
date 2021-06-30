#include "stdafx.h"
#include "boomerang.h"

HRESULT boomerang::init(float x, float y, float z)
{
	RECT camera = CAMERAMANAGER->getScreen();
	_img = IMAGEMANAGER->addImage("boomerang", "img/equip/boomerang.bmp", 64, 64, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_z = z;
	_invX = 128 + 96 * 2;
	_invY = 124;
	_rc = RectMakeCenter(_x, _y, 64, 64);
	_type = BOOMERANG;
	return S_OK;
}

void boomerang::release()
{
}

void boomerang::update()
{
	//�θ޶��� ������� �� �ʿ��� x,y,z��ǥ ����(rect��)
}

void boomerang::render(HDC hdc, float x, float y)
{
	//�θ޶��� ������� �� �̹��� ����
	_img->render(hdc, x, y);
}

void boomerang::useItem()
{
}
