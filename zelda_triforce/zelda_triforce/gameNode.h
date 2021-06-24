#pragma once
#include "image.h"

#define RENDERCOUNT		0.05
#define RENDERCOUNT2	RENDERCOUNT * 2

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", 20000, 20000);

enum DIRECT {
	DOWN,
	UP,
	RIGHT,
	LEFT,
	ENDDIRECT
};

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public:
	gameNode();
	virtual ~gameNode();

	//HRESULT ���� ���� ��ȯ�����ε�
	//S_OK, E_FAIL, SUCCEDED
	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� �Լ�
	virtual void render();			//�׸��� �Լ�

	//����� ������
	//void setBackBufferSize(float width, float height){ _backBuffer->setwidth}
	image* getBackBuffer() { return _backBuffer; }

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};