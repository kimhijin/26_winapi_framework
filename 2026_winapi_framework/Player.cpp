#include "pch.h"
#include "Player.h"

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

}

void Player::Render(HDC hdc)
{
    Utils::DrawElipse(hdc, GetPos(), GetSize());
}
