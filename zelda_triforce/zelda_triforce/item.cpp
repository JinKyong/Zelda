#include "stdafx.h"
#include "item.h"

HRESULT item::init()
{
	// ºÎ¸Þ¶û[2] ¹ö¼¸[4] Ä­µ¨¶ó[10] ///// ÀáÀÚ¸®Ã¤[13] º´[15]

	_tile.rc[0] = RectMake(128, 124, 64, 64);
	_selItemRc = RectMake(800, 100, 64, 64);

	for (int i = 1; i < 20; i++)
	{
		if (i / 5 == 0) _tile.rc[i] = RectMake(_tile.rc[0].left + i * 96, _tile.rc[0].top, 64, 64);
		if (i / 5 == 1) _tile.rc[i] = RectMake(_tile.rc[0].left + i % 5 * 96, _tile.rc[0].top + 96, 64, 64);
		if (i / 5 == 2) _tile.rc[i] = RectMake(_tile.rc[0].left + i % 10 * 96, _tile.rc[0].top + 96 * 2, 64, 64);
		if (i / 5 == 3) _tile.rc[i] = RectMake(_tile.rc[0].left + i % 15 * 96, _tile.rc[0].top + 96 * 3, 64, 64);
		if (i / 5 == 4) _tile.rc[i] = RectMake(_tile.rc[0].left + i % 20 * 96, _tile.rc[0].top + 96 * 4, 64, 64);
	}

	return S_OK;
}

void item::release()
{
}

void item::update()
{
	itemSetup();
}

void item::render()
{
	itemOutput();

	if (KEYMANAGER->isStayKeyDown(VK_TAB))
	{
		for (int i = 0; i < 20; i++)
		{
			Rectangle(getMemDC(), _tile.rc[i]);
		}
		Rectangle(getMemDC(), _selItemRc);
	}
}

void item::itemSetup()
{
	itemInfo candela;
	candela.itemName = "Ä­µ¨¶ó";
	candela.itemKind = ITEM_CANDELA;
	candela.img = IMAGEMANAGER->findImage("candela");
	_vItem.push_back(candela);

	itemInfo boomerang;
	boomerang.itemName = "ºÎ¸Þ¶û";
	boomerang.itemKind = ITEM_BOOMERANG;
	boomerang.img = IMAGEMANAGER->findImage("bmrang");
	_vItem.push_back(boomerang);

	itemInfo mushroom;
	mushroom.itemName = "¹ö¼¸";
	mushroom.itemKind = ITEM_MUSHROOM;
	mushroom.img = IMAGEMANAGER->findImage("mushroom");
	_vItem.push_back(mushroom);
}

void item::itemOutput()
{
	for (_viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem)
	{
		_viItem->img->render(getMemDC(), _tile.rc[_viItem->itemKind].left, _tile.rc[_viItem->itemKind].top);
	}
}
