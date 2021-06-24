#pragma once
#include "Scene.h"

#define MAPWIDTH	5120
#define MAPHEIGHT	5120

class testStage : public Scene
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