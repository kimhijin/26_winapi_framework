#pragma once
#include "Object.h"
class Player : public Object
{
public:
	void Update() override;
	void Render(HDC hdc) override;
protected:
	void Fire();
private:
	float m_fireTimer = 0.f;
};

