#include "pch.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"

void SceneManager::Init()
{
	RegisterScene<TitleScene>(L"Title");
	RegisterScene<GameScene>(L"Game");

	LoadScene(L"Game");
}

void SceneManager::Update()
{
	if (m_curScene != nullptr)
		m_curScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	if(m_curScene != nullptr)
		m_curScene->Render(hdc);
}

void SceneManager::Release()
{
	for (auto& [name, scene] : m_scenes)
		SAFE_DELETE(scene);
	m_scenes.clear();
	m_curScene = nullptr;
}

void SceneManager::LoadScene(const wstring& sceneName)
{
	//load - curScene에다가 scene을 준거
	//chang - 씬 변경하면서 release init
	auto iter = m_scenes.find(sceneName);
	if (iter == m_scenes.end())
		return;
	if (m_curScene != nullptr)
		m_curScene->Release();

	m_curScene->Release();
	m_curScene = iter->second;
	m_curScene->Init();

}
