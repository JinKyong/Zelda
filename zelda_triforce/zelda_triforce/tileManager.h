#pragma once
#include "singletonBase.h"
#include "tileInfo.h"

class tileManager : public singletonBase<tileManager>
{
private:
	image* _map;
	vector<PTILE> _mapTile;
	vector<PTILE> _renderTile;

public:
	HRESULT init();
	HRESULT init(image* img);
	void release();
	void update();
	void render();

	PTILE makeTile(float x, float y, float z, int r, int g, int b);
};

