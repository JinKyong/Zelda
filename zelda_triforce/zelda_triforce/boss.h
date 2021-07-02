#pragma once
#include "gameNode.h"

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


	int _count;					//������Ʈ ������� ī��Ʈ
	int _indexX;					//������ ���� �ε���
	int _indexY;					//������ ���Ʒ� �ε���
	int _movecount;				//�ʹ� �ٷιٷ� �����̸� �ȵǴϱ�
	int _direction;				//����
	int _pattern;				//��������
	int _aCount;					//���� ī��Ʈ
	int _mCount;					//���� ī��Ʈ
	int _lCount;					//�ʻ�� ī��Ʈ

	float _maxHP, _currentHP;		//ü��, ����ü��
	float _x,_y, _z;				//X,Y,Z��
	float _cx, _cy;				//����X, ����Y��
	float _bodyDMG;				//���� ������
	float _midW, _midH;			//���ط�Ʈ�� ���μ��� �߾�

	bool _lightning;				//�ʻ�� ���ɻ���
	bool _aPossible;				//������ ������ �����ΰ�
	bool _mPossible;				//�̵��� ������ �����ΰ�

public:
	HRESULT init();
	HRESULT init(POINT position);
	void release();
	void update();
	void render();
	void draw();
	void hitDamage(float damage);


	float getHP() { return _currentHP; }
	RECT getRect() { return _rc; }
	float getbodYDMG() { return _bodyDMG; }
	int getaC() { return _aCount; }
	int getmC() { return _mCount; }
	int getindexX() { return _indexX; }
	float getmidW() { return _midW; }
	float getmidH() { return _midH; }
	int getD() { return _direction; }
	bool getLightning() { return _lightning; }
	image* getI() { return bossI; }
	int getPattern(){ return _pattern; }

	float getZ() { return _z; }
};
