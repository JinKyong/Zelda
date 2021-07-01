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

	scoutS _state;				//������Ʈ �̳� ����

	RECT _rc;					//�� �̹����� ���� ����
	image* scout[3];				//�� �̹����� ���� ����
	image* scoutI;

	action* _action;			//�׼� �ݹ�

	int state;					//������Ʈ ������� �ҷ�����
	int next;					//���� �����̴� Ƚ��
	int findway;				//���� �����̴� ����
	int _count;					//������Ʈ ������� ī��Ʈ
	int indexX;					//������ ���� �ε���
	int indexY;					//������ ���Ʒ� �ε���
	int indexH;					//�Ӹ� �����̱� ���� �ε���
	int movecount;				//�ʹ� �ٷιٷ� �����̸� �ȵǴϱ�
	int direction;				//����

	float radius;				//��������
	float maxHP, currentHP;		//ü��, ����ü��
	float x, y, z;				//X,Y,Z��
	float bodyDMG;				//���� ������

	bool way;					//���� �� �� �ִ°� ���°�.

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

	snakeS _state;				//������Ʈ �̳� ����

	RECT _rc;					//�� �̹����� ���� ����
	image* snake[2];				//�� �̹����� ���� ����
	image* snakeI;

	action* _action;			//�׼� �ݹ�

	int state;					//������Ʈ ������� �ҷ�����
	int next;					//���� �����̴� Ƚ��
	int findway;				//���� �����̴� ����
	int _count;					//������Ʈ ������� ī��Ʈ
	int indexX;					//������ ���� �ε���
	int indexY;					//������ ���Ʒ� �ε���
	int movecount;				//�ʹ� �ٷιٷ� �����̸� �ȵǴϱ�
	int direction;				//����

	float maxHP, currentHP;		//ü��, ����ü��
	float x, y, z;				//X,Y,Z��
	float bodyDMG;				//���� ������

	bool way;					//���� �� �� �ִ°� ���°�.

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

	mouseM _state;				//������Ʈ �̳� ����

	RECT _rc;					//�� �̹����� ���� ����
	image* mouse[3];				//�� �̹����� ���� ����
	image* mouseI;

	action* _action;			//�׼� �ݹ�

	int state;					//������Ʈ ������� �ҷ�����
	int next;					//���� �����̴� Ƚ��
	int findway;				//���� �����̴� ����
	int _count;					//������Ʈ ������� ī��Ʈ
	int indexX;					//������ ���� �ε���
	int indexY;					//������ ���Ʒ� �ε���
	int indexH;					//���̵� ���� �ε���
	int movecount;				//�ʹ� �ٷιٷ� �����̸� �ȵǴϱ�
	int direction;				//����
	int idle;					//���̵� ���� ����

	float maxHP, currentHP;		//ü��, ����ü��
	float x, y, z;				//X,Y,Z��
	float bodyDMG;				//���� ������

	bool way;					//���� �� �� �ִ°� ���°�.

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
	blueB _state;				//������Ʈ �̳� ����

	RECT _rc;					//�� �̹����� ���� ����
	image* blue[3];				//�� �̹����� ���� ����
	image* blueI;

	action* _action;			//�׼� �ݹ�

	int state;					//������Ʈ ������� �ҷ�����
	int next;					//���� �����̴� Ƚ��
	int findway;				//���� �����̴� ����
	int _count;					//������Ʈ ������� ī��Ʈ
	int indexX;					//������ ���� �ε���
	int indexY;					//������ ���Ʒ� �ε���
	int indexH;					//�Ӹ� �����̱� ���� �ε���
	int movecount;				//�ʹ� �ٷιٷ� �����̸� �ȵǴϱ�
	int direction;				//����

	float radius;				//��������
	float maxHP, currentHP;		//ü��, ����ü��
	float x, y, z;				//X,Y,Z��
	float bodyDMG;				//���� ������


	bool way;					//���� �� �� �ִ°� ���°�.

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
	greenG _state;				//������Ʈ �̳� ����

	RECT _rc;					//�� �̹����� ���� ����
	image* green[3];				//�� �̹����� ���� ����
	image* greenI;

	action* _action;			//�׼� �ݹ�

	int state;					//������Ʈ ������� �ҷ�����
	int next;					//���� �����̴� Ƚ��
	int findway;				//���� �����̴� ����
	int _count;					//������Ʈ ������� ī��Ʈ
	int indexX;					//������ ���� �ε���
	int indexY;					//������ ���Ʒ� �ε���
	int indexH;					//�Ӹ� �����̱� ���� �ε���
	int movecount;				//�ʹ� �ٷιٷ� �����̸� �ȵǴϱ�
	int direction;				//����

	float radius;				//��������
	float maxHP, currentHP;		//ü��, ����ü��
	float x, y, z;				//X,Y,Z��
	float bodyDMG;				//���� ������


	bool way;					//���� �� �� �ִ°� ���°�.

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
