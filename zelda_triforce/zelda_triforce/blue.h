#pragma once
#include "enemy.h"

enum blueB
{
	BLUE_MOVE,
	BLUE_SEARCH,
	BLUE_FALL,
	BLUE_HIT,
	BLUEEND
};

class blue:public enemy
{
private:
	blueB _state;				//스테이트 이넘 선언

	RECT _sword;				//검범위 렉트

	image* blue[3];				//각 이미지에 따른 선언
	image* blueI;

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

