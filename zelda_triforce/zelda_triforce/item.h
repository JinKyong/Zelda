#pragma once
#include "gameNode.h"

struct tagItem
{
	image* img;
	RECT rc;
	bool get;

	int x, y;
};

struct tile
{
	RECT rc[4][5];
	int x[4][5], y[4][5];
};

class item : public gameNode
{
	tagItem _candela;
	tile _tile;

public:
	item() {};
	~item() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};