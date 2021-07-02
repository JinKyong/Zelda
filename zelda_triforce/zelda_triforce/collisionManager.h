#pragma once
#include "singletonBase.h"
#include <vector>

class Player;
class enemy;

class collisionManager : public singletonBase<collisionManager>
{
private:
	//�÷��̾�
	Player* _player;
	Scene* _scene;

	int _state;

	bool _collision;

public:
	collisionManager() {};
	~collisionManager() {};

	HRESULT init(Player* player);
	HRESULT init(Scene* scene);

	//�÷��̾� �浹
	void collisionPlayer();
	void playerWithTile();

	//�÷��̾� ��ȣ�ۿ�
	void interactPlayer();

	void collisionEnemy(enemy* Enemy);
	void enemyWithTile(enemy* Enemy);
	void enemyWithPlayer(enemy* Enemy);

	void release();
};
