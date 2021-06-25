#pragma once
#include "gameNode.h"

class item;

class inventory : public gameNode
{
	image* _bg;
	item* _item;

	image* _bag;
	RECT _bagRC;

	RECT _selRect;
	image* _select;
	float _count;

public:
	inventory() {};
	~inventory() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void controlKey();
	void controlFrame();
};