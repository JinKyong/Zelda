#pragma once
#include "gameNode.h"
#include "Player.h"
#include "inventory.h"

class playGround : public gameNode
{
private:
	Player* _player;
	inventory* _inven;

	bool _invOpen;
	bool _debug;

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual HRESULT init(const char* str);
	virtual void release();
	virtual void update();
	virtual void render();
};