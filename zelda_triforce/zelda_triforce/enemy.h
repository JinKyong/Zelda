#pragma once
#include "gameNode.h"
#include "action.h"

class enemy : public gameNode
{
protected:

	RECT _rc;					//�� �̹����� ��Ʈ

	action* _action;			//�׼� �ݹ�

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

	bool way;					//���� �� �� �ִ°� ���°�.

public:
	virtual HRESULT init(POINT position)=0;
	virtual void release()=0;
	virtual void update()=0;
	virtual void render()=0;
	virtual void draw()=0;
	virtual void hitDamage(float damage)=0;
	virtual float getHP() = 0;
	virtual float getBodyDMG() = 0;
	virtual int getN() = 0;
};

