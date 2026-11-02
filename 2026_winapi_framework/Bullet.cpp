#include "pch.h"
#include "Bullet.h"

void Bullet::Update()
{
	Translate({ 0.f, -500.f * fDT });
	if (GetPos().y + GetSize().y / 2 < 0.f)
		SetActive(false);
}

void Bullet::Render(HDC hdc)
{
	Utils::DrawElipse(hdc, GetPos(), GetSize());
}
