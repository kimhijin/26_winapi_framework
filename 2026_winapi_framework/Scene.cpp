#include "pch.h"
#include "Scene.h"
#include"object.h"


void Scene::Update()
{
	for (auto& layer : m_objects)
	{
		for (Object* obj : layer)
		{
			obj->Update();
		}
	}
	OnUpdate();
}

void Scene::Render(HDC hdc)
{
	for (auto& layer : m_objects)
	{
		for (Object* obj : layer)
		{
			obj->Render(hdc);
		}
	}
	OnRender(hdc);
}

void Scene::Release()
{
	OnRelease();

	for (auto& layer : m_objects)
	{
		for (Object* obj : layer)
		{
			SAFE_DELETE(obj);

		}
		layer.clear();
	}
}
