#pragma once
#include"Object.h"
class Scene
{
public:
	virtual void Init() abstract;
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	void AddObject(const Object& obj, Layer layer)
	{
		m_objects[(UINT)layer].push_back(obj);
	}
private:
	vector<Object*> m_objects[(UINT)Layer::END];
};

