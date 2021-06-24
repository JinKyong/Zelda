#pragma once
#include "gameNode.h"

class Player : public gameNode
{
private:
	//��ü
	float _x, _y, _z;
	int _direct;
	RECT _body;

	//����
	float _speed;

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
	void move(int direct); //�÷��̾� �̵��Լ�

	//================= ������ =================//
	void setX(float x) { _x = x; }
	float getX() { return _x; }
	void setY(float y) { _y = y; }
	float getY() { return _y; }
	void setZ(float z) { _z = z; }
	float getZ() { return _z; }
	void setDirect(int direct) { _direct = direct; } //���� ������
	int getDirect() { return _direct; }				 //���� ������

	void setRect(float x, float y, int width, int height) { _body = RectMakeCenter(x, y, width, height); } //�÷��̾� �ٵ� ������
	RECT getBody() { return _body; }
};