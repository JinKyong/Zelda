#pragma once
#include "enemy.h"

enum scoutS
{
	SCOUT_MOVE,
	SCOUT_SHIFT,
	SCOUTEND
};
class scout:public enemy
{
private:

	scoutS _state;				//������Ʈ �̳� ����

	image* scout[3];				//�� �̹����� ���� ����
	image* scoutI;

public:
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();
	virtual void hitDamage(float damage);
};

