#pragma once
#include "singletonBase.h"

#define MAXLIFE 3

class uiManager : public singletonBase<uiManager>
{
private:
	image* _gauge;
	image* _gaugeBack;
	image* _xitem;
	image* _money;
	image* _bomb;
	image* _arrow;
	image* _lifeText;
	image* _life[MAXLIFE];

	RECT _rc;

	image* _number[10];

	int _moneyCount;
	int _bombCount;
	int _arrowCount;

public:
	uiManager() {};
	~uiManager() {};

	HRESULT init(Player* player);
	void release();
	void update();
	void render(HDC hdc);
};