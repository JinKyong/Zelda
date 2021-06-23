#pragma once
#include "gameNode.h"

class Player : public gameNode
{
private:
	//몸체
	float _x, _y, _z;
	RECT _body;

	//스탯

	//상태

	//이펙트

public:
	Player() {};
	~Player() {};

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 함수
	virtual void render();			//그리기 함수

	//스탯 증감

	//동작

	//================= 접근자 =================//
	void setX(float x) { _x = x; }
	float getX() { return _x; }
	void setY(float y) { _y = y; }
	float getY() { return _y; }
	void setZ(float z) { _z = z; }
	float getZ() { return _z; }

	RECT getBody() { return _body; }
};