#include "stdafx.h"
#include "inventory.h"
#include "item.h"

HRESULT inventory::init()
{
	_bg = IMAGEMANAGER->addImage("bg", "img/equip/all.bmp", 1024, 896, true, PINK);
	_select = IMAGEMANAGER->addFrameImage("select", "img/equip/select.bmp", 208, 104, 2, 1, true, PINK);

	_bag = IMAGEMANAGER->addImage("bag", "img/equip/5x4.bmp", 608, 480, true, PINK);
	_bagRC = RectMake(32, 60, 608, 480);

	_item = new item;
	_item->init();

	_selRect = RectMakeCenter(160, 156, 104, 104);

	_count = 0;

	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
	_item->update();

	controlKey();
	controlFrame();
}

void inventory::render()
{
	_bg->render(getMemDC());
	_bag->render(getMemDC(), _bagRC.left, _bagRC.top);
	_item->render();

	//Rectangle(getMemDC(), _selRect);
	_select->frameRender(getMemDC(), _selRect.left, _selRect.top);
}

void inventory::controlKey()
{
	if (_selRect.top > _bagRC.top && _selRect.bottom < _bagRC.bottom)
	{

		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _selRect.left > _bagRC.left)
		{
			_selRect.left -= 96;
			_selRect.right -= 96;

			if (_selRect.left < _bagRC.left)
			{
				_selRect.left += 480;
				_selRect.right += 480;
				_selRect.top -= 96;
				_selRect.bottom -= 96;
			}
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _selRect.right < _bagRC.right)
		{
			_selRect.left += 96;
			_selRect.right += 96;

			if (_selRect.right > _bagRC.right)
			{
				_selRect.left -= 480;
				_selRect.right -= 480;
				_selRect.top += 96;
				_selRect.bottom += 96;
			}
		}
	}
}

void inventory::controlFrame()
{
	_count += TIMEMANAGER->getElapsedTime();

	if (_count >= RENDERCOUNT2 * 5)
	{
		if (_select->getFrameX() >= _select->getMaxFrameX())
			_select->setFrameX(0);
		else
			_select->setFrameX(_select->getFrameX() + 1);

		_count = 0;
	}
}
