#pragma once
#include "gameNode.h"
#include "enemy.h"
#include "boss.h"
#include <vector>

enum enemyType
{
	_Escout,
	_Egreen,
	_Eblue,
	_Emouse,
	_Esnake,
	_Eboss,
	_EEND
};

class enemyManager : public gameNode
{
private:
	typedef vector<scout*>					vEScout;
	typedef vector<scout*>::iterator		viEScout;

	typedef vector<green*>					vEGreen;
	typedef vector<green*>::iterator		viEGreen;

	typedef vector<blue*>					vEBlue;
	typedef vector<blue*>::iterator			viEBlue;

	typedef vector<mouse*>					vEMouse;
	typedef vector<mouse*>::iterator		viEMouse;

	typedef vector<snake*>					vESnake;
	typedef vector<snake*>::iterator   	    viESnake;

	typedef vector<boss*>					vEBoss;
	typedef vector<boss*>::iterator		    viEBoss;

private:

	vEScout _vScout;
	viEScout _viScout;
	vEGreen _vGreen;
	viEGreen _viGreen;
	vEBlue _vBlue;
	viEBlue _viBlue;
	vEMouse _vMouse;
	viEMouse _viMouse;
	vESnake _vSnake;
	viESnake _viSnake;


	vEBoss _vBoss;
	viEBoss _viBoss;

	scout* eScout;
	blue* eBlue;
	green* eGreen;
	snake* eSnake;
	mouse* eMouse;
	boss* eBoss;

	RECT prc;

	int r;
	float x2;
	float y2;

public:
	enemyManager() {};
	~enemyManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemy(int ET, int i, int j);

	void removeScout(int arrNum);
	void removeBlue(int arrNum);
	void removeGreen(int arrNum);
	void removeSnake(int arrNum);
	void removeMouse(int arrNum);
	void removeBoss(int arrNum);

	vector<scout*> getVScout() { return _vScout; }
	vector<scout*>::iterator getVIScout() { return _viScout; }

	vector<green*> getVGreen() { return _vGreen; }
	vector<green*>::iterator getVIGreen() { return _viGreen; }

	vector<blue*> getVBlue() { return _vBlue; }
	vector<blue*>::iterator getVIBlue() { return _viBlue; }

	vector<snake*> getVSnake() { return _vSnake; }
	vector<snake*>::iterator getVISnake() { return _viSnake; }

	vector<mouse*> getVMouse() { return _vMouse; }
	vector<mouse*>::iterator getVIMouse() { return _viMouse; }

	vector<boss*> getVBoss() { return _vBoss; }
	vector<boss*>::iterator getVIBoss() { return _viBoss; }

};

