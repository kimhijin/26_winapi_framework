#pragma once
#include "Object.h"
class Player : public Object
{
	Object player;
public:
	void Update() override;
	void Render(HDC hdc) override;
};

