#include "stdafx.h"
#include "uiManager.h"
#include "Player.h"

HRESULT uiManager::init(Player* player)
{
	//이미지
	_gauge = IMAGEMANAGER->addImage("gauge", "img/ui/gauge.bmp", 64, 168, true, PINK);
	_gaugeBack = IMAGEMANAGER->addImage("gauge_back", "img/ui/gauge_back.bmp", 64, 168, true, PINK);
	_xitem = IMAGEMANAGER->addImage("xitem", "img/ui/xitem.bmp", 88, 88, true, PINK);
	_money = IMAGEMANAGER->addImage("money", "img/ui/money.bmp", 32, 32, true, PINK);
	_bomb = IMAGEMANAGER->addImage("bomb", "img/ui/bomb.bmp", 32, 32, true, PINK);
	_arrow = IMAGEMANAGER->addImage("arrow", "img/ui/arrow.bmp", 56, 32, true, PINK);
	_lifeText = IMAGEMANAGER->addImage("life_text", "img/ui/life_text.bmp", 176, 28, true, PINK);

	//숫자
	char str[128];
	for (int i = 0; i < 10; i++)
	{
		_number[i] = new image;
		sprintf_s(str, "img/%d.bmp", i);
		_number[i]->init(str, 28, 28, true, RGB(255, 0, 255));
	}

	//스탯

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::render(HDC hdc)
{
	RECT rc = CAMERAMANAGER->getScreen();

	_gaugeBack->render(hdc, rc.left + 79, rc.top + 71);
	_gauge->render(hdc, rc.left + 79, rc.top + 71);
	_xitem->render(hdc, rc.left + 147, rc.top + 79);
	_money->render(hdc, rc.left + 287, rc.top + 59);
	_bomb->render(hdc, rc.left + 399, rc.top + 59);
	_arrow->render(hdc, rc.left + 484, rc.top + 59);
	_lifeText->render(hdc, rc.left + 711, rc.top + 59);
}