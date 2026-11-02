#include "pch.h"
#include "Formation.h"

void Formation::Update()
{
	constexpr float RANGE = 180.f;
	constexpr float SPEED = 500.f;

	float step = m_dir * SPEED * fDT;
	Translate({ step, 0.f });

	m_moved += step;
	if (m_moved > RANGE)
		m_dir = -1.f;
	else if(m_moved< -RANGE)
		m_dir = 1.f;
}
