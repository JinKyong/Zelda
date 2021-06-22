#pragma once
#include "gameNode.h"

class playGround : public gameNode
{
private:
	bool _debug;
	bool _test;


public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual HRESULT init(const char* str);
	virtual void release();
	virtual void update();
	virtual void render();
};