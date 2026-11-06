#pragma once
#include"Object.h"

template<typename T>
concept ObjectType = std::is_convertible_v<T*, Object*>;

class Scene
{
public:
	Scene() = default;
	virtual ~Scene() {};
	Scene(const Scene&) = delete;
	Scene& operator = (const Scene&) = default;
public:
	virtual void Init() abstract;
	void Update();
	void Render(HDC hdc);
	void Release();

protected:
	virtual void OnUpdate() {};
	virtual void OnRender(HDC hdc) {};
	virtual void OnRelease() {};
public:
	template<typename T>
	T* AddObject(Layer layer)
	{
		auto obj = std::make_unique<T>();
		T* raw = obj.get();
		m_objects[(UINT)layer].push_back(std::move(obj));
		return raw;
	}
private:
	vector<std::unique_ptr<Object>> m_objects[(UINT)Layer::END];
};

