#include "stdafx.h"
#include "sceneManager.h"
#include "Scene.h"

Player* sceneManager::_player = NULL;
Scene* sceneManager::_currentScene = NULL;

sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{
}

HRESULT sceneManager::init(Player* player)
{
	_player = player;
	_currentScene = NULL;

	return S_OK;
}

void sceneManager::release()
{
	mapSceneIter miSceneList = _mSceneList.begin();

	for (; miSceneList != _mSceneList.end();)
	{
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) miSceneList->second->release();
			SAFE_DELETE(miSceneList->second);
			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}

	_mSceneList.clear();
}

void sceneManager::update()
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render()
{
	if (_currentScene) _currentScene->render();
}

Scene* sceneManager::addScene(string sceneName, Scene* scene)
{
	if (!scene) return nullptr;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	mapSceneIter find = _mSceneList.find(sceneName);

	if (find == _mSceneList.end()) return E_FAIL;

	if (find->second == _currentScene) return S_OK;

	if (SUCCEEDED(find->second->init(_player)))
	{
		//����(�ִ�) ���� ������ �Լ��� �������ְ�
		if (_currentScene) _currentScene->release();

		//�ٲٷ��� ���� ��������� ü����
		_currentScene = find->second;

		CAMERAMANAGER->setFade(FADEIN);

		return S_OK;
	}

	return E_FAIL;
}