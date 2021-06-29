#pragma once
//#include "singletonBase.h"
#include "gameNode.h"
#include "item.h"

class item;

class inventory : public gameNode
{
private:
	typedef vector<item*>			itemList;
	typedef vector<item*>::iterator itemIter;

private:
	itemList _vItem;
	itemIter _viItem;

	image* _bgImg;

	int _a, _b;
	//RECT _bagRC;
	//image* _bagImg;

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
	virtual void render();

	void addItem(item* item);

	void controlKey();
	void controlFrame();
};