#pragma once

class Player;

/*************** KEY ***************/
#define KEY_RIGHT	VK_RIGHT
#define KEY_LEFT	VK_LEFT
#define KEY_UP		VK_UP
#define KEY_DOWN	VK_DOWN
/***********************************/

enum PLAYERSTATE {

};

class State
{
private:

protected:
	static Player* _player;

	image* _img;
	float _count;
	int _direct;
	bool _reverse;

public:
	State() {};
	~State() {};

	virtual HRESULT init(Player* player, bool reverse = false);
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(HDC hdc) = 0;
	virtual void updateDirect(int direct) = 0;
	virtual void updateRect() = 0;

	virtual int getStateNum() = 0;
};