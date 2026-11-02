#pragma once
#include "Object.h"
class Formation : public Object
{
public:
	void Update() override;
private :
	float m_dir = 1.f;
	float m_moved = 0.f;
};

