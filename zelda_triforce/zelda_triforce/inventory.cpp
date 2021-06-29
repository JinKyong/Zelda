#include "stdafx.h"
#include "inventory.h"
#include "candela.h"
#include "boomerang.h"
#include "mushroom.h"

HRESULT inventory::init()
{
	_bgImg = IMAGEMANAGER->addImage("bg", "img/equip/all.bmp", 1024, 896, true, PINK);
	_selImg = IMAGEMANAGER->addFrameImage("select", "img/equip/select.bmp", 208, 104, 2, 1, true, PINK);

	_bagImg = IMAGEMANAGER->addImage("bag", "img/equip/5x4.bmp", 608, 480, true, PINK);
	_bagRC = RectMake(32, 60, 608, 480);

	_selItemRc = RectMake(800, 100, 64, 64);

	_count = 0;
	_index = 0;

	_a = 160;
	_b = 156;

	boomerang* _boomerang = new boomerang;
	_boomerang->init(_a + 96 * 2, _b);
	_vItem.push_back(_boomerang);

	mushroom* _mushroom = new mushroom;
	_mushroom->init(_a + 96 * 4, _b);
	_vItem.push_back(_mushroom);

	candela* _candela = new candela;
	_candela->init(_a, _b + 96 * 2);
	_vItem.push_back(_candela);


	_selItemRc = RectMake(_vItem[_index]->getX(), _vItem[_index]->getY(), 104, 104);


	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
	controlKey();
	controlFrame();
}

void inventory::render()
{
	_bgImg->render(getMemDC());
	_bagImg->render(getMemDC(), _bagRC.left, _bagRC.top);

	//Rectangle(getMemDC(), _selItemRc);

	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		(*_viItem)->render(getMemDC());

	}
	_selItemRc = RectMakeCenter(_vItem[_index]->getX(), _vItem[_index]->getY(), 104, 104);

	_selImg->frameRender(getMemDC(), _selItemRc.left, _selItemRc.top);

	_vItem[_index]->getImage()->render(getMemDC(), _bagRC.right + 160, _bagRC.top + 35);
}

void inventory::controlKey()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _index > 0)
	{
		_index--;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _index < _vItem.size() - 1)
	{
		_index++;
	}
}

void inventory::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();

	if (_count >= RENDERCOUNT2 * 5)
	{
		if (_selImg->getFrameX() >= _selImg->getMaxFrameX())
			_selImg->setFrameX(0);
		else
			_selImg->setFrameX(_selImg->getFrameX() + 1);

		_count = 0;
	}
}