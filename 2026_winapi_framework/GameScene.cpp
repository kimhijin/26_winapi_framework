#include "pch.h"
#include"Player.h"
#include "GameScene.h"

void GameScene::Init()
{
	for (int i = 0; i < 5; ++i)
	{
		Object enemy;
		enemy.SetPos({ 200 + i * 200, 100 });
		enemy.SetSize({ 50,50 });
		AddObject(enemy, Layer::Enemy);
	}

	Player player;
	player.SetPos({ WINDOW_WIDTH / 2,
		WINDOW_HEIGHT / 2 });
	player.SetSize({ 50,50 });
	AddObject(player, Layer::Player);
}
