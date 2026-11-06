#pragma once
#include "Object.h"
class Bullet : public Object
{
public:
	void Update() override;
	void Render(HDC hdc) override;
	void SetVelocity(Vec2 velocity) { m_velocity = velocity; }
private:
	bool IsOutOfBounds() const;
private:
	Vec2 m_velocity = {};
};

