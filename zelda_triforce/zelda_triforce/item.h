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

// 넹....... 일단해봐야죠모
// 그럼 완성보단 좀더.. 공부해보라는? 느낌으로?? 가라는거죠?
// 넵 'ω')>
// 벡가놈

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