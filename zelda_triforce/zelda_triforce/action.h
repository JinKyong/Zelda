#pragma once
#include "gameNode.h"

class action : public gameNode
{
private:
	image* _image;				//����� �̹���
	RECT _rc;					//����� ��Ʈ
	float _startX, _startY;		//���� ��ǥ
	float _endX, _endY;			//���� ��ǥ	

	float _angle;				//����
	float _travelRange;			//����Ÿ� (������ �Ÿ�)
	float _worldTimeCount;
	float _time;

	bool _isMoving;

public:
	action();
	~action();

	HRESULT init();
	void release();
	void update();
	void render();

	void moveTo(image* image, float endX, float endY, float time);

	void moving();

	bool getIsMoving() { return _isMoving; }
};
