#pragma once
#include "singletonBase.h"
#include "image.h"

#define FADE	500

class cameraManager : public singletonBase<cameraManager>
{
private:
	//ī�޶� ���ߴ� ȭ�� ũ��(WINSIZEX, WINSIZEY)�� ��ǥ(left, right, top, bottom)
	RECT _screen;
	int _backWidth, _backHeight;	//backDC ũ��
	int _frontWidth, _frontHeight;	//frontDC ũ��
	//fade
	image* _fadeScreen;
	float _alpha;
	int _fade;

	//ī�޶� ������
	float _count;	//������ �� ����ϴ� count
	float _ratioX;	//�߽��� ��ġ ���� (x)
	float _ratioY;	//�߽��� ��ġ ���� (y)
	float _zoom;	//Ȯ����
	float _camY;	//ī�޶� �ø��� ������
	bool _onMove;	//ī�޶� �ø��� ������ �Ǻ�

public:
	cameraManager();
	~cameraManager();

	HRESULT init(int width, int height);
	void release();

	//ī�޶� ��ġ(screen) ����
	void updateScreen(float standardX, float standardY);
	void moveCam(int direct);
	void resetCam();

	//FadeIN, FadeOUT
	void fadeIn(HDC hdc);
	void fadeOut(HDC hdc);

	//ī�޶� ����
	void vibrateScreen(float standardX, float standardY,
		float magnitude = 5.0f, float interval = 0);
	void vibrateScreenOut(float standardX, float standardY,
		float magnitude = 5.0f, float interval = 0);

	//ī�޶� ���
	void render(HDC frontDC, int destX, int destY, HDC backDC);

	//ī�޶� ����ó��
	void onWindow(float& x, float& y);

	//============ ������ ============//
	RECT getScreen() { return _screen; }

	void setBackScreenSize(float width, float height) { _backWidth = width, _backHeight = height; }
	//void setFrontScreenSize(float width, float height) { _frontWidth = width, _frontHeight = height; }
	float getBackScreenWidth() { return _backWidth; }
	float getBackScreenHeight() { return _backHeight; }

	float getAlpha() { return _alpha; }

	void setFade(int fade) { _fade = fade; }
	int getFade() { return _fade; }

	void setRatioX(float ratio) { _ratioX = ratio; }
	float getRatioX() { return _ratioX; }
	void setRatioY(float ratio) { _ratioY = ratio; }
	float getRatioY() { return _ratioY; }

	void setZoom(float zoom) { _zoom = zoom; }
	float getZoom() { return _zoom; }

	void setCamY(float count) { _camY = count; }
	float getCamY() { return _camY; }

	void setMove(bool b) { _onMove = b; }
	bool getMove() { return _onMove; }
};

