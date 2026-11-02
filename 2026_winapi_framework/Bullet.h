#pragma once
#include "Object.h"
class Bullet : public Object
{
public:
	void Update() override;
	void Render(HDC hdc) override;
};

