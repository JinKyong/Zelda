#include "stdafx.h"
#include "inventoryManager.h"
#include "candela.h"
#include "boomerang.h"
#include "mushroom.h"

HRESULT inventoryManager::init()
{
	_bgImg = IMAGEMANAGER->addImage("bg", "img/equip/all.bmp", 1024, 896, true, RGB(255, 0, 255));
	_selImg = IMAGEMANAGER->addFrameImage("select", "img/equip/select.bmp", 208, 104, 2, 1, true, RGB(255, 0, 255));

	_selItemRc = RectMake(800, 100, 64, 64);

	_count = 0;
	_index = 0;

	RECT rc = CAMERAMANAGER->getScreen();

	//첫번째 아이템 (left, top)
	_a = rc.left + 160;
	_b = rc.top + 156;

	_boomerang = new boomerang;
	_boomerang->init(_a + 96 * 2, _b, 0);
	_vItem.push_back(_boomerang);

	_mushroom = new mushroom;
	_mushroom->init(_a + 96 * 4, _b, 0);
	_vItem.push_back(_mushroom);

	_candela = new candela;
	_candela->init(_a, _b + 96 * 2, 0);
	_vItem.push_back(_candela);

	_selItemRc = RectMake(_vItem[_index]->getInvX(), _vItem[_index]->getInvY(), 104, 104);

	return S_OK;
}

void inventoryManager::release()
{
}

void inventoryManager::update()
{
	controlKey();
	controlFrame();
}

void inventoryManager::render(HDC hdc)
{
	RECT rc = CAMERAMANAGER->getScreen();
	_bgImg->render(hdc, rc.left, rc.top);

	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem)->render(hdc, rc.left + (*_viItem)->getInvX(), rc.top + (*_viItem)->getInvY());
	}

	_selItemRc = RectMake(rc.left + _vItem[_index]->getInvX() - 20, rc.top + _vItem[_index]->getInvY() - 20, 104, 104);
	_selImg->frameRender(hdc, _selItemRc.left, _selItemRc.top);

	_vItem[_index]->getImage()->render(hdc, rc.left + 800, rc.top + 100);
}

void inventoryManager::addItem(item * item)
{
	_vItem.push_back(item);
}

void inventoryManager::controlKey()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_index = (_index - 1 + _vItem.size()) % _vItem.size();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_index = (_index + 1) % _vItem.size();
	}
}

void inventoryManager::controlFrame()
{
	_count++;

	if (_count >= 10)
	{
		if (_selImg->getFrameX() >= _selImg->getMaxFrameX())
			_selImg->setFrameX(0);
		else
			_selImg->setFrameX(_selImg->getFrameX() + 1);

		_count = 0;
	}
}