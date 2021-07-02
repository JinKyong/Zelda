#pragma once
#include "enemy.h"


enum greenG
{
	GREEN_MOVE,
	GREEN_SEARCH,
	GREEN_FALL,
	GREEN_HIT,
	GREENEND
};

class green : public enemy
{
private:
	greenG _state;				//������Ʈ �̳� ����


	image* green[3];				//�� �̹����� ���� ����
	image* greenI;
public:

	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

	virtual void hitDamage(float damage);

};

