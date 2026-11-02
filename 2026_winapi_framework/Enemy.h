#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	void Update() override;
	void Render(HDC hdc) override;
	void SetFormation(Object* formation, Vector2 offset);
private :
	//float m_dir = 1.f;
	Object* m_formation = nullptr;
	Vector2 m_offset;
};