#pragma once
#include "Scene.h"

class title : public Scene
{
private:
	bool _change;

public:
	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void changeScene();
};

