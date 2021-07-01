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

	agahnim _state;				//스테이트 이넘 선언

	RECT _rc;					//캐릭터 렉트
	RECT _censor;				//센서 렉트
	image* boss[3];				//각 이미지에 따른 선언
	image* bossI;

	action* _action;			//액션 콜백

	int _count;					//스테이트 끌어오기 카운트
	int indexX;					//프레임 순서 인덱스
	int indexY;					//프레임 위아래 인덱스
	int movecount;				//너무 바로바로 움직이면 안되니까
	int direction;				//방향
	int pattern;				//공격패턴
	int aCount;					//어택 카운트
	int mCount;					//무브 카운트
	int lCount;					//필살기 카운트

	float maxHP, currentHP;		//체력, 현재체력
	float x, y, z;				//X,Y,Z값
	float cx, cy;				//센서X, 센서Y값
	float bodyDMG;				//몸박 데미지
	float midW, midH;			//기준렉트의 가로세로 중앙

	bool lightning;				//필살기 가능상태
	bool aPossible;				//공격이 가능한 상태인가
	bool mPossible;				//이동이 가능한 상태인가

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
