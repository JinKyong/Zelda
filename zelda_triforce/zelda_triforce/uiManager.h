#pragma once
#include "singletonBase.h"

class uiManager : public singletonBase<uiManager>
{
private:

public:
	uiManager() {};
	~uiManager() {};

	HRESULT init(Player* player);
	void release();
	void render(HDC hdc);
};

