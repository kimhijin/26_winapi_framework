#include "pch.h"
#include "Player.h"
#include "SceneManager.h"
#include "Bullet.h"
#include "Scene.h"

void Player::Update()
{
    if (GET_KEY(Key::LEFT))
        Translate({ -100.f * fDT, 0 });
    if (GET_KEY(Key::RIGHT))
        Translate({ 100.f * fDT, 0 });
    if (GET_KEY(Key::UP))
        Translate({ 0,-100.f * fDT });
    if (GET_KEY(Key::DOWN))
        Translate({ 0,100.f * fDT });
    if (GET_KEYDOWN(Key::Z))
        Scale(0.5f);
    if (GET_KEYDOWN(Key::X))
        Scale(std::pow(2.f, fDT));

    constexpr float FIRE_INTERVAL = 0.1f;
    if (m_fireTimer > 0.f)
        m_fireTimer -= fDT;
    if (GET_KEY(Key::SPACE) && m_fireTimer <= 0.f)
    {
        Fire();
        m_fireTimer += FIRE_INTERVAL;
    }
}

void Player::Fire()
{
   Bullet* bullet = GET_SINGLE(SceneManager)->GetCurScene()
        ->AddObject<Bullet>(Layer::PlayerBullet);
   bullet->SetSize({ 10.f,20.f });
   bullet->SetPos({ GetPos() - Vector2{0.f, GetSize().y / 2} });
}

void Player::Render(HDC hdc)
{
    Utils::DrawElipse(hdc, GetPos(), GetSize());
}


