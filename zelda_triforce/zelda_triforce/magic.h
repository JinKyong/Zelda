#pragma once
#include "gameNode.h"
#include "boss.h"
#include <vector>

struct tagFire
{
	image* _fireImage;		//�Ѿ� �̹��� 
	RECT _rc;				//�Ѿ� ��Ʈ
	float _x, _y;				//�Ѿ� ��ǥ(�ǽð�)
	float _angle;			//�Ѿ� ����
	float _radius;			//�Ѿ� ������
	float _speed;			//�Ѿ� ���ǵ�
	float _dmg;
	float _fireX, _fireY;		//�Ѿ� �߻�� ó�� ��ǥ(�߻�� ��ǥ)
	bool _isFire;
	int _count;				//�Ѿ� ������ī��Ʈ��
};
struct tagCircul
{
	image* _circulImage;		//�Ѿ� �̹��� 
	RECT _rc;				//�Ѿ� ��Ʈ
	float _x, _y;				//�Ѿ� ��ǥ(�ǽð�)
	float _angle;			//�Ѿ� ����
	float _radius;			//�Ѿ� ������
	float _speed;			//�Ѿ� ���ǵ�
	float _dmg;
	float _fireX, _fireY;		//�Ѿ� �߻�� ó�� ��ǥ(�߻�� ��ǥ)
	bool _isFire;
	int _count;				//�Ѿ� ������ī��Ʈ��
};
struct tagSpread
{
	image* _spreadImage;		//�Ѿ� �̹��� 
	RECT _rc;				//�Ѿ� ��Ʈ
	float _x, _y;				//�Ѿ� ��ǥ(�ǽð�)
	float _angle;			//�Ѿ� ����
	float _radius;			//�Ѿ� ������
	float _speed;			//�Ѿ� ���ǵ�
	float _dmg;
	float _fireX, _fireY;		//�Ѿ� �߻�� ó�� ��ǥ(�߻�� ��ǥ)
	bool _isFire;
	int _count;				//�Ѿ� ������ī��Ʈ��
	int indexY;
};
class fireball : public gameNode
{
private:
	vector<tagFire>				 _vFire;
	vector<tagFire>::iterator	 _viFire;

	float _range;
	int _fireMax;
	int _indexY;
	boss* _boss;
public:
	fireball() {};
	~fireball() {};

	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);

	void move();

	void setIndexY(int IndexY) { _indexY = IndexY; }
	int getIndexY() { return _indexY; }
	//�Ѿ��� �����޶�� �����ϴ� �Լ�
	void removeBullet(int arrNum);



	vector<tagFire> getVFire() { return _vFire; }
	vector<tagFire>::iterator getViFire() { return _viFire; }

};

class circulator : public gameNode
{
private:
	vector<tagCircul>				 _vCircul;
	vector<tagCircul>::iterator		_viCircul;

	vector<tagSpread>				 _vSpread;
	vector<tagSpread>::iterator		_viSpread;

	float _range;
	int _fireMax;
	int _index=0;
	int _spreadMax;
	int _indexs = 0;
	float innerX;
	float innerY;
	
	boss* _boss;
	
public:
	circulator() {};
	~circulator() {};

	HRESULT init(int bulletMax,int spreadMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);
	void spreadfire(float x, float y, float angle, float speed, int indexY);

	void move();


	//�Ѿ��� �����޶�� �����ϴ� �Լ�
	void removeBullet(int arrNum);
	void removeSpread(int arrNum);



	vector<tagCircul> getVCir() { return _vCircul; }
	vector<tagCircul>::iterator getViCir() { return _viCircul; }
	vector<tagSpread> getVSpread() { return _vSpread; }
	vector<tagSpread>::iterator getViSpread() { return _viSpread; }

};

//class thunder :public gameNode
//{
//private:
//	
//
//	float _range;
//	int _fireMax;
//	int _indexY;
//	boss* _boss;
//public:
//	thunder() {};
//	~thunder() {};
//
//	HRESULT init(int bulletMax, float range);
//	void release();
//	void update();
//	void render();
//
//	void fire(float x, float y, float angle, float speed);
//
//	void setIndexY(int IndexY) { _indexY = IndexY; }
//	int getIndexY() { return _indexY; }
//	//�Ѿ��� �����޶�� �����ϴ� �Լ�
//	void removeBullet(int arrNum);
//
//
//
//	
//};

class magic
{
};

