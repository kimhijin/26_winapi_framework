#pragma once
#include"Scene.h"
class Object
{
public:
	Object();
	virtual ~Object(); // 가상 소멸자
public:
	virtual void Update() {};
	virtual void Render(HDC hdc);
public:
	Vector2 GetPos() const { return m_pos; }
	void SetPos(Vector2 pos) { m_pos = pos; }

	Vector2 GetSize() const { return m_size; }
	void SetSize(Vector2 size) { m_size = size; }
public:
	void Translate(Vector2 delta)
	{
		m_pos += delta;
	}
public:
	Scene* m_scene;
	Vector2 m_pos;
	Vector2 m_size;
};

