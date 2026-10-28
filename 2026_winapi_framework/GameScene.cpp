#include "pch.h"
#include"Player.h"
#include "GameScene.h"

void GameScene::Init()
{
	for (int i = 0; i < 5; ++i)
	{
		Object* enemy = AddObject<Object>(Layer::Player);
		enemy->SetPos({ 200 + i * 200, 100 });
		AddObject<Object>(Layer::Enemy);
		enemy->SetSize({ 50,50 });
	}

	Object* player = AddObject<Player>(Layer::Player);
	player->SetPos({ WINDOW_WIDTH / 2,
		WINDOW_HEIGHT / 2 });
	player->SetSize({ 50,50 });
}
void GameScene::OnUpdate()
{
}
void GameScene::OnRender(HDC hdc)
{
}

