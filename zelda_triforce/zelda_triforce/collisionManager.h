#pragma once
#include "singletonBase.h"
#include <vector>

class Player;
class enemy;
class item;

class collisionManager : public singletonBase<collisionManager>
{
private:
	//�÷��̾�
	Player* _player;
	Scene* _scene;

	int _state;

public:
	collisionManager() {};
	~collisionManager() {};

	HRESULT init(Player* player);
	HRESULT init(Scene* scene);
	void release();

	//�÷��̾� �浹
	void collisionPlayer();
	void playerWithTile();
	void playerWithEnemy(enemy* Enemy);

	//�÷��̾� ��ȣ�ۿ�
	void interactPlayer();

	//���ʹ� �浹
	void collisionEnemy(enemy* Enemy);
	void enemyWithTile(enemy* Enemy);
	void enemyWithPlayer(enemy* Enemy);

	//������ �浹
	void collisionItem(item* Item);
	void itemWithPlayer(item* Item);
};
