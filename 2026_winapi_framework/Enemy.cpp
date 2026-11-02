
#include "pch.h"
#include "Enemy.h"

void Enemy::Update()
{
	if (m_formation != nullptr)
		SetPos(m_formation->GetPos() + m_offset);
}

void Enemy::SetFormation(Object* formation, Vector2 offset)
{
	m_formation = formation;
	m_offset = offset;
	SetPos(formation->GetPos() + offset);
}

void Enemy::Render(HDC hdc)
{
	Utils::DrawRect(hdc, GetPos(), GetSize());

}


