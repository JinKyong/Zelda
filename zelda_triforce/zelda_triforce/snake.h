#pragma once
#include "enemy.h"

enum snakeS
{
	SNAKE_MOVE,
	SNAKEEND
};

class snake: public enemy
{
private:

	snakeS _state;				//������Ʈ �̳� ����

	image* snake[2];				//�� �̹����� ���� ����
	image* snakeI;

public:
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
	virtual void hitDamage(float damage);
	virtual float getHP() { return _currentHP; }
	virtual RECT getRC() { return _rc; }
	virtual float getBodyDMG() { return _bodyDMG; }
	virtual int getN() { return _next; }
};

