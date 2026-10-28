#pragma once
#include "Object.h"
class Player : public Object
{
public:
	void Update() override;
	void Render(HDC hdc) override;
};

