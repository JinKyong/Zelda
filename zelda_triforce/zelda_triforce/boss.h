#pragma once
#include "gameNode.h"
#include "action.h"

enum agahnim
{
	ATTACK,
	BOSS_MOVE,
	BOSSEND
};
class boss :public gameNode
{
private:

	agahnim _state;				//������Ʈ �̳� ����

	RECT _rc;					//ĳ���� ��Ʈ
	RECT _censor;				//���� ��Ʈ
	image* boss[3];				//�� �̹����� ���� ����
	image* bossI;

	action* _action;			//�׼� �ݹ�

	int _count;					//������Ʈ ������� ī��Ʈ
	int indexX;					//������ ���� �ε���
	int indexY;					//������ ���Ʒ� �ε���
	int movecount;				//�ʹ� �ٷιٷ� �����̸� �ȵǴϱ�
	int direction;				//����
	int pattern;				//��������
	int aCount;					//���� ī��Ʈ
	int mCount;					//���� ī��Ʈ
	int lCount;					//�ʻ�� ī��Ʈ

	float maxHP, currentHP;		//ü��, ����ü��
	float x, y, z;				//X,Y,Z��
	float cx, cy;				//����X, ����Y��
	float bodyDMG;				//���� ������
	float midW, midH;			//���ط�Ʈ�� ���μ��� �߾�

	bool lightning;				//�ʻ�� ���ɻ���
	bool aPossible;				//������ ������ �����ΰ�
	bool mPossible;				//�̵��� ������ �����ΰ�

public:
	virtual HRESULT init();
	virtual HRESULT init(POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	void draw();
	void hitDamage(float damage);
	float getHP() { return currentHP; }
	RECT getRect() { return _rc; }
	float getbodYDMG() { return bodyDMG; }
	int getaC() { return aCount; }
	int getmC() { return mCount; }
	int getindexX() { return indexX; }
	float getmidW() { return midW; }
	float getmidH() { return midH; }
};
