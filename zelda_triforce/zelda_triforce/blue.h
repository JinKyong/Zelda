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
	blueB _state;				//������Ʈ �̳� ����



	image* blue[3];				//�� �̹����� ���� ����
	image* blueI;

public:
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void draw();
	virtual void hitDamage(float damage);

};

