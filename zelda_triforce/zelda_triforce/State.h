#pragma once

class Player;

/*************** KEY ***************/
#define KEY_RIGHT	VK_RIGHT
#define KEY_LEFT	VK_LEFT
#define KEY_UP		VK_UP
#define KEY_DOWN	VK_DOWN

#define KEY_SLASH   'A'
#define KEY_CARRY	'S'
/***********************************/

enum PLAYERSTATE {
	IDLE,
	RUN,
	SLASH,
	CHARGING,
	CHARGEATTACK,
	CARRY,
	THROW,
	PUSH
};

class State
{
private:

protected:
	static Player* _player;

	image* _img;
	int _count;
	int _direct;
	bool _reverse;

public:
	State() {};
	~State() {};

	virtual HRESULT init(Player* player);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(HDC hdc) = 0;
	virtual void updateDirect(int direct) = 0;
	virtual void updateRect() = 0;

	virtual int getStateNum() = 0;
};