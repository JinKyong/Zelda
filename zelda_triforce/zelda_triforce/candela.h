#pragma once
#include "item.h"
class candela :	public item
{
private:

public:
	candela() {};
	~candela() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void useItem();

	virtual int getType() { return _type; }
};

