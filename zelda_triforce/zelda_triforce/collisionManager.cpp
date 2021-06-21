#include "stdafx.h"
#include "collisionManager.h"
#include "Player.h"
#include "Scene.h"

HRESULT collisionManager::init()
{
	return S_OK;
}

HRESULT collisionManager::init(Scene* scene)
{
	_player = scene->getPlayer();
	_state = 0;

	return S_OK;
}

void collisionManager::release()
{
}