#pragma once
#include "singletonBase.h"
#include <vector>

class Player;
class enemy;

class collisionManager : public singletonBase<collisionManager>
{
private:
	//플레이어
	Player* _player;
	Scene* _scene;

	int _state;

	bool _collision;

public:
	collisionManager() {};
	~collisionManager() {};

	HRESULT init(Player* player);
	HRESULT init(Scene* scene);

	//플레이어 충돌
	void collisionPlayer();
	void playerWithTile();

	//플레이어 상호작용
	void interactPlayer();

	void collisionEnemy(enemy* Enemy);
	void enemyWithTile(enemy* Enemy);
	void enemyWithPlayer(enemy* Enemy);

	void release();
};
