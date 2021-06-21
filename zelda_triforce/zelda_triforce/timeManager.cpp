#include "stdafx.h"
#include "timeManager.h"


timeManager::timeManager()
	: _timer(NULL)
{
}

timeManager::~timeManager()
{
}

HRESULT timeManager::init()
{
	_timer = new timer;
	_timer->init();

	_start = _end = 0;
	_onTimer = false;

	return S_OK;
}

void timeManager::release()
{
	if (_timer != nullptr)
	{
		SAFE_DELETE(_timer);
	}
}

//FPS ���������� �����ϴ� ��
void timeManager::update(float lock)
{
	if (_timer != nullptr)
	{
		_timer->tick(lock);
	}

}

void timeManager::render(HDC hdc, float x, float y)
{
	char str[256];

#ifdef _DEBUG
	{
		if (_timer != nullptr)
		{
			//������ ���
			wsprintf(str, "framePerSec : %d", _timer->getFrameRate());
			TextOut(hdc, x, y, str, strlen(str));

			//���� Ÿ�� (����ð�)
			sprintf_s(str, "worldTime : %f", _timer->getWorldTime());
			TextOut(hdc, x, y + 20, str, strlen(str));

			//���� tick
			sprintf_s(str, "elapsedTime : %f", _timer->getElapsedTime());
			TextOut(hdc, x, y + 40, str, strlen(str));

			//Ÿ�̸�
			sprintf_s(str, "startTime : %f", _start);
			TextOut(hdc, x, y + 60, str, strlen(str));
			sprintf_s(str, "endTime : %f", _end);
			TextOut(hdc, x, y + 80, str, strlen(str));
		}
	}
#else
	{
		if (_timer != nullptr)
		{
			//������ ���
			wsprintf(str, "framePerSec : %d", _timer->getFrameRate());
			TextOut(hdc, x, y, str, strlen(str));
		}
	}
#endif
}

void timeManager::setTimer()
{
	if (_onTimer) return;

	_start = _timer->getWorldTime();
	_onTimer = true;
}

float timeManager::clock()
{
	if (_onTimer)
		_end = _timer->getWorldTime();
	
	return _end - _start;
}

void timeManager::endTimer()
{
	_start = _end = 0;
	_onTimer = false;
}
