#pragma once
#include "gameNode.h"
#include "action.h"

enum scoutS
{
	SCOUT_MOVE,
	SCOUT_SHIFT,
	SCOUTEND
};
enum blueB
{
	BLUE_MOVE,
	BLUE_SEARCH,
	BLUE_FALL,
	BLUE_HIT,
	BLUEEND
};
enum greenG
{
	GREEN_MOVE,
	GREEN_SEARCH,
	GREEN_FALL,
	GREEN_HIT,
	GREENEND
};
enum snakeS
{
	SNAKE_MOVE,
	SNAKEEND
};
enum mouseM
{
	MOUSE_MOVE,
	MOUSE_IDLE,
	MOUSEEND
};
class scout :public gameNode
{
private:

	scoutS _state;				//스테이트 이넘 선언

	RECT _rc;					//각 이미지에 따른 선언
	image* scout[3];				//각 이미지에 따른 선언
	image* scoutI;

	action* _action;			//액션 콜백

	int state;					//스테이트 현재상태 불러오기
	int next;					//다음 움직이는 횟수
	int findway;				//다음 움직이는 방향
	int _count;					//스테이트 끌어오기 카운트
	int indexX;					//프레임 순서 인덱스
	int indexY;					//프레임 위아래 인덱스
	int indexH;					//머리 움직이기 전용 인덱스
	int movecount;				//너무 바로바로 움직이면 안되니까
	int direction;				//방향

	float radius;				//센서범위
	float maxHP, currentHP;		//체력, 현재체력
	float x, y, z;				//X,Y,Z값
	float bodyDMG;				//몸박 데미지

	bool way;					//길을 갈 수 있는가 없는가.

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
	int getN() { return next; }
};

class snake :public gameNode
{
private:

	snakeS _state;				//스테이트 이넘 선언

	RECT _rc;					//각 이미지에 따른 선언
	image* snake[2];				//각 이미지에 따른 선언
	image* snakeI;

	action* _action;			//액션 콜백

	int state;					//스테이트 현재상태 불러오기
	int next;					//다음 움직이는 횟수
	int findway;				//다음 움직이는 방향
	int _count;					//스테이트 끌어오기 카운트
	int indexX;					//프레임 순서 인덱스
	int indexY;					//프레임 위아래 인덱스
	int movecount;				//너무 바로바로 움직이면 안되니까
	int direction;				//방향

	float maxHP, currentHP;		//체력, 현재체력
	float x, y, z;				//X,Y,Z값
	float bodyDMG;				//몸박 데미지

	bool way;					//길을 갈 수 있는가 없는가.

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
};

class mouse :public gameNode
{
private:

	mouseM _state;				//스테이트 이넘 선언

	RECT _rc;					//각 이미지에 따른 선언
	image* mouse[3];				//각 이미지에 따른 선언
	image* mouseI;

	action* _action;			//액션 콜백

	int state;					//스테이트 현재상태 불러오기
	int next;					//다음 움직이는 횟수
	int findway;				//다음 움직이는 방향
	int _count;					//스테이트 끌어오기 카운트
	int indexX;					//프레임 순서 인덱스
	int indexY;					//프레임 위아래 인덱스
	int indexH;					//아이들 상태 인덱스
	int movecount;				//너무 바로바로 움직이면 안되니까
	int direction;				//방향
	int idle;					//아이들 상태 유지

	float maxHP, currentHP;		//체력, 현재체력
	float x, y, z;				//X,Y,Z값
	float bodyDMG;				//몸박 데미지

	bool way;					//길을 갈 수 있는가 없는가.

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
	int getN() { return next; }
	int getI() { return idle; }
	int getZ() { return z; }
};

class blue :public gameNode
{
	blueB _state;				//스테이트 이넘 선언

	RECT _rc;					//각 이미지에 따른 선언
	image* blue[3];				//각 이미지에 따른 선언
	image* blueI;

	action* _action;			//액션 콜백

	int state;					//스테이트 현재상태 불러오기
	int next;					//다음 움직이는 횟수
	int findway;				//다음 움직이는 방향
	int _count;					//스테이트 끌어오기 카운트
	int indexX;					//프레임 순서 인덱스
	int indexY;					//프레임 위아래 인덱스
	int indexH;					//머리 움직이기 전용 인덱스
	int movecount;				//너무 바로바로 움직이면 안되니까
	int direction;				//방향

	float radius;				//센서범위
	float maxHP, currentHP;		//체력, 현재체력
	float x, y, z;				//X,Y,Z값
	float bodyDMG;				//몸박 데미지


	bool way;					//길을 갈 수 있는가 없는가.

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
	int getN() { return next; }
};

class green : public gameNode
{
	greenG _state;				//스테이트 이넘 선언

	RECT _rc;					//각 이미지에 따른 선언
	image* green[3];				//각 이미지에 따른 선언
	image* greenI;

	action* _action;			//액션 콜백

	int state;					//스테이트 현재상태 불러오기
	int next;					//다음 움직이는 횟수
	int findway;				//다음 움직이는 방향
	int _count;					//스테이트 끌어오기 카운트
	int indexX;					//프레임 순서 인덱스
	int indexY;					//프레임 위아래 인덱스
	int indexH;					//머리 움직이기 전용 인덱스
	int movecount;				//너무 바로바로 움직이면 안되니까
	int direction;				//방향

	float radius;				//센서범위
	float maxHP, currentHP;		//체력, 현재체력
	float x, y, z;				//X,Y,Z값
	float bodyDMG;				//몸박 데미지


	bool way;					//길을 갈 수 있는가 없는가.

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
	int getN() { return next; }
};
