#pragma once
#include "singletonBase.h"
#include "item.h"

class item;

class inventory : public singletonBase<inventory>
{
private:
	typedef vector<item*>			itemList;
	typedef vector<item*>::iterator itemIter;

private:
	itemList _vItem;
	itemIter _viItem;

	image* _bgImg;

	item* _boomerang;
	item* _candela;
	item* _mushroom;

	int _a, _b;

	RECT _selItemRc;
	image* _selImg;
	float _count;
	int _index;

public:
	inventory() {};
	~inventory() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void addItem(item* item);

	void controlKey();
	void controlFrame();
};