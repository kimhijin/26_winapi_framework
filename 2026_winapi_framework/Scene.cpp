#include "pch.h"
#include "Scene.h"


void Scene::Update()
{
	for (auto& layer : m_objects)
	{
		for (Object& obj : layer)
		{
			obj.Update();
		}
	}
}

void Scene::Render(HDC hdc)
{
	for (auto& layer : m_objects)
	{
		for (Object& obj : layer)
		{
			obj.Render(hdc);
		}
	}
}

void Scene::Release()
{
}
