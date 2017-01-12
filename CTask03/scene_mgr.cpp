#include"scene_mgr.h"

void SceneMgr::SetScene(int scene)
{
	m_scene = scene;
}

int SceneMgr::GetScene()
{
	return m_scene;
}

int SceneMgr::m_scene = SCENE_INIT;
