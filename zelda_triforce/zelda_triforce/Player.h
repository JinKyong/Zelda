#pragma once
#include "gameNode.h"

class Player : public gameNode
{
private:
	//��ü
	float _x, _y, _z;
	RECT _body;

	//����

	//����

	//����Ʈ

public:
	Player() {};
	~Player() {};

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� �Լ�
	virtual void render();			//�׸��� �Լ�

	//���� ����

	//����

	//================= ������ =================//
	void setX(float x) { _x = x; }
	float getX() { return _x; }
	void setY(float y) { _y = y; }
	float getY() { return _y; }
	void setZ(float z) { _z = z; }
	float getZ() { return _z; }

	RECT getBody() { return _body; }
};