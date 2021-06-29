#pragma once
#include "item.h"
class boomerang :
	public item
{
private:

public:
	boomerang() {};
	~boomerang() {};

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void useItem();

	virtual int getType() { return _type; }
};
