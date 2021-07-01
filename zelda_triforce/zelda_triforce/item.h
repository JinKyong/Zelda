#pragma once

enum ITEM
{
	BOOMERANG,
	MUSHROOM,
	CANDELA,
	HEART,
	RUPEE,
	ENDITEM
};

class item
{
protected:
	RECT _rc;
	image* _img;
	float _x, _y, _z;
	float _invX, _invY;
	int _type;

public:
	item() {};
	~item() {};

	virtual HRESULT init(float x, float y, float z = 0) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(HDC hdc, float x, float y) = 0;

	float getX() { return _x; }
	float getY() { return _y; }
	float getInvX() { return _invX; }
	float getInvY() { return _invY; }

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	image* getImage() { return _img; }
};