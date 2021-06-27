#pragma once
#include "gameNode.h"

struct tile
{
	RECT rc[20];
};

enum ITEM
{
	ITEM_BOOMERANG = 2,
	ITEM_MUSHROOM = 4,
	ITEM_CANDELA = 10,
	ITEM_END
};

struct itemInfo
{
	ITEM itemKind;
	string itemName;
	image* img;
};

class item : public gameNode
{
private:
	tile _tile;

	RECT _selItemRc;

	vector<itemInfo> _vItem;
	vector<itemInfo>::iterator _viItem;

public:
	item() {};
	~item() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void itemSetup();
	void itemOutput();

	vector<itemInfo> getVItem() { return _vItem; }
};