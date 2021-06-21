#pragma once
#include "singletonBase.h"
#include <vector>

class Player;

class collisionManager : public singletonBase<collisionManager>
{
private:
	//플레이어
	Player* _player;
	int _state;	

public:
	collisionManager() {};
	~collisionManager() {};

	HRESULT init();
	HRESULT init(Scene* scene);
	void release();
};
