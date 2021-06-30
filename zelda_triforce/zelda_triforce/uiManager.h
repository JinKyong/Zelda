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

	image* _number[10];

public:
	uiManager() {};
	~uiManager() {};

	HRESULT init(Player* player);
	void release();
	void render(HDC hdc);
};

