#include "stdafx.h"
#include "uiManager.h"
#include "Player.h"

HRESULT uiManager::init(Player* player)
{
	//이미지
	_gauge = IMAGEMANAGER->addImage("gauge", "img/ui/gauge.bmp", 64, 168, true, PINK);
	_gaugeBack = IMAGEMANAGER->addImage("gauge_back", "img/ui/gauge_back.bmp", 32, 128, true, PINK);
	_xitem = IMAGEMANAGER->addImage("xitem", "img/ui/xitem.bmp", 88, 88, true, PINK);
	_money = IMAGEMANAGER->addImage("money", "img/ui/money.bmp", 32, 32, true, PINK);
	_bomb = IMAGEMANAGER->addImage("bomb", "img/ui/bomb.bmp", 32, 32, true, PINK);
	_arrow = IMAGEMANAGER->addImage("arrow", "img/ui/arrow.bmp", 56, 32, true, PINK);
	_lifeText = IMAGEMANAGER->addImage("life_text", "img/ui/life_text.bmp", 176, 28, true, PINK);

	for (int i = 0; i < MAXLIFE; i++) _life[i] = IMAGEMANAGER->addFrameImage("life", "img/ui/life.bmp", 84, 28, 3, 1, true, PINK);

	//mp
	_mp = 128;

	//숫자
	_moneyCount = 0;
	_bombCount = 0;
	_arrowCount = 0;

	char key[128], str[128];
	for (int i = 0; i < 10; i++)
	{
		sprintf_s(key, "number%d", i);
		sprintf_s(str, "img/ui/%d.bmp", i);
		_number[i] = IMAGEMANAGER->addImage(key, str, 28, 28, true, RGB(255, 0, 255));
	}


	//스탯

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
	//테스트용 코드
	//if (KEYMANAGER->isOnceKeyDown('1'))
	//	_moneyCount += 6;

	//if (KEYMANAGER->isOnceKeyDown('2'))
	//	_bombCount += 6;

	//if (KEYMANAGER->isOnceKeyDown('3'))
	//	_arrowCount += 6;


	//if (KEYMANAGER->isOnceKeyDown('4')) {
	//	_mp += 10;
	//	if (_mp > 128)
	//		_mp = 128;
	//}

	//if (KEYMANAGER->isOnceKeyDown('5')) {
	//	_mp -= 10;
	//	if (_mp < 0)
	//		_mp = 0;
	//}

	//if (_moneyCount > 999) _moneyCount = 999;
	//if (_bombCount > 99) _bombCount = 99;
	//if (_arrowCount > 99) _arrowCount = 99;
}

void uiManager::render(HDC hdc)
{
	RECT rc = CAMERAMANAGER->getScreen();

	char str[128];
	sprintf_s(str, "MP : %d", _mp);
	TextOut(hdc, rc.left + 20, rc.top + 20, str, strlen(str));

	_gaugeBack->render(hdc, rc.left + 79 + 16, rc.top + 71 + 20 + (128 - _mp), 0, 0, 32, _mp);
	_gauge->render(hdc, rc.left + 79, rc.top + 71);
	_xitem->render(hdc, rc.left + 147, rc.top + 79);
	_money->render(hdc, rc.left + 287, rc.top + 59);
	_bomb->render(hdc, rc.left + 399, rc.top + 59);
	_arrow->render(hdc, rc.left + 484, rc.top + 59);
	_lifeText->render(hdc, rc.left + 711, rc.top + 59);

	for (int i = 0; i < MAXLIFE; i++)	_life[i]->frameRender(hdc, rc.left + 643 + i * 32, rc.top + 95);

	//INVENTORYMANAGER->getvItem()[i]->getImage()->render(hdc, rc.left + 159, rc.top + 91);

	if (PRINTMANAGER->isDebug()) {
		_rc = RectMake(rc.left + 159, rc.top + 91, 64, 64);
		Rectangle(hdc, _rc);
	}

	//money
	_number[_moneyCount / 100]->render(hdc, rc.left + 260, rc.top + 95);
	_number[_moneyCount % 100 / 10]->render(hdc, rc.left + 291, rc.top + 95);
	_number[_moneyCount % 10]->render(hdc, rc.left + 323, rc.top + 95);

	//bomb
	_number[_bombCount % 100 / 10]->render(hdc, rc.left + 387, rc.top + 95);
	_number[_bombCount % 10]->render(hdc, rc.left + 419, rc.top + 95);

	//arrow
	_number[_arrowCount % 100 / 10]->render(hdc, rc.left + 483, rc.top + 95);
	_number[_arrowCount % 10]->render(hdc, rc.left + 515, rc.top + 95);
}