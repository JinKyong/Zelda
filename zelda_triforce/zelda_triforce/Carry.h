#pragma once
#include "State.h"
class Carry :
	public State
{
private:
	bool _isCarry;
	bool _isMove;

public:
	Carry() {};
	~Carry() {};
	virtual HRESULT init(Player* player);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	virtual void updateDirect(int direct);
	virtual void updateRect();

	virtual int getStateNum() { return RUN; }

	void controlKey();
	void controlFrame();
};

