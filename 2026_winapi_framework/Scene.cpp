#include "pch.h"
#include "Scene.h"
#include"object.h"


void Scene::Update()
{
	for (auto& layer : m_objects)
	{
		//for (Object* obj : layer)
		for(size_t i =0; i<layer.size(); i++)
		{
			if (layer[i]->IsActive())
				layer[i]->Update();
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
			if(obj->IsActive())
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
