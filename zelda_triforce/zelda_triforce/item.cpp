#include "stdafx.h"
#include "item.h"

HRESULT item::init()
{
	//Ä­µ¨¶ó(2, 0) º´(3, 0) ºÎ¸Þ¶û (0, 1) ÀáÀÚ¸®Ã¤(2, 3) ¹ö¼¸(0, 4)

	//

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 && j == 0) _tile.rc[i][j] = RectMake(128, 124, 64, 64);
			if (i == 0 && j > 0) _tile.rc[i][j] = RectMake(_tile.rc[0][0].left + j * 96, _tile.rc[0][0].top, 64, 64);
			if (i > 0) _tile.rc[i][j] = RectMake(_tile.rc[0][0].left + j * 96, _tile.rc[0][0].top + i * 96, 64, 64);

			_tile.x[i][j] = (_tile.rc[0][0].left + _tile.rc[0][0].right) / 2;
			_tile.y[i][j] = (_tile.rc[0][0].top + _tile.rc[0][0].bottom) / 2;
		}
	}

	//_candela.img = IMAGEMANAGER->findImage("candela");
	//_candela.rc = RectMake(WINSIZEX / 2 + 100, WINSIZEY / 2, 64, 64);
	//_candela.get = false;

	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render()
{
	if (KEYMANAGER->isStayKeyDown(VK_TAB))
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)	Rectangle(getMemDC(), _tile.rc[i][j]);
		}
	}

	if(_candela.get) _candela.img->render(getMemDC(), _tile.rc[0][2].left, _tile.rc[0][2].top);
}