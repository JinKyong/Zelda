#pragma once
#include "Scene.h"

class item;

class inventory : public Scene
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

	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void changeScene();

	void controlKey();
	void controlFrame();
};