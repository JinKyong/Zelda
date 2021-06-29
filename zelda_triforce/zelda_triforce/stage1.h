#pragma once
#include "Scene.h"

#define MAPWIDTH	128
#define MAPHEIGHT	128

class stage1 : public Scene
{
private:
	image* _background;

public:
	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void changeScene();
};
