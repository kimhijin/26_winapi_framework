#include "pch.h"
#include "Bullet.h"

void Bullet::Update()
{
	Translate( m_velocity * fDT);
	if (IsOutOfBounds())
		SetActive(false);
}

void Bullet::Render(HDC hdc)
{
	HBRUSH brush = ::CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, brush);
	Utils::DrawElipse(hdc, GetPos(), GetSize());
}

bool Bullet::IsOutOfBounds() const
{
	Vec2 pos = GetPos();
	Vec2 half = GetSize() / 2.f;
	return pos.x + half.x < 0.f || pos.x - half.x > WINDOW_WIDTH
		|| pos.y + half.y < 0.f || pos.y - half.y > WINDOW_HEIGHT;
}
