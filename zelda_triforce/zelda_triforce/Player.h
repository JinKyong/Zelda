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

};