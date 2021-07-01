#pragma once
#include "enemy.h"

enum mouseM
{
	MOUSE_MOVE,
	MOUSE_IDLE,
	MOUSEEND
};

class mouse:public enemy
{
private:
	mouseM _state;				//������Ʈ �̳� ����

	image* mouse[3];				//�� �̹����� ���� ����
	image* mouseI;

	int _idle;					//���̵� ���� ����

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
	virtual int getI() { return _idle; }
	virtual int getZ() { return _z; }
};

