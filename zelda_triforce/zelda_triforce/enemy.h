#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:

	RECT _rc;					//�� �̹����� ��Ʈ
	RECT _sword;				//�˹��� ��Ʈ

	int _state;					//������Ʈ ������� �ҷ�����
	int _next;					//���� �����̴� Ƚ��
	int _findway;				//���� �����̴� ����
	int _count;					//������Ʈ ������� ī��Ʈ
	int _indexX;					//������ ���� �ε���
	int _indexY;					//������ ���Ʒ� �ε���
	int _indexH;					//�Ӹ� �����̱� ���� �ε���
	int _movecount;				//�ʹ� �ٷιٷ� �����̸� �ȵǴϱ�
	int _direction;				//����

	float _radius;
	float _maxHP, _currentHP;		//ü��, ����ü��
	float _x, _y, _z;				//X,Y,Z��
	float _bodyDMG;				//���� ������

	bool _way;					//���� �� �� �ִ°� ���°�.

public:
	virtual HRESULT init(POINT position) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void draw() = 0;
	virtual void hitDamage(float damage) = 0;

	float getHP() { return _currentHP; }

	RECT getRC() { return _rc; }
	RECT getSword() { return _sword; }

	void setRC(float x, float y, int width, int height) { _rc = RectMakeCenter(x, y, width, height); }

	float getBodyDMG() { return _bodyDMG; }
	int getN() { return _next; }

	float getX() { return _x; }
	void setX(float x) { _x = x; }
	float getY() { return _y; }
	void setY(float y) { _y = y; }
	float getZ() { return _z; }
	void setZ(float z) { _z = z; }
	bool getWay() { return _way; }
	void setWay(bool Way) { _way=Way; }
};