#include "pch.h"
#include"Player.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "Formation.h"

void GameScene::Init()
{
	Object* formation = AddObject<Formation>(Layer::Default);
	formation->SetPos({ WINDOW_WIDTH / 2,150.f });
	for (int i = 0; i < 5; ++i)
	{
		Enemy* enemy = AddObject<Enemy>(Layer::Enemy);
		enemy->SetPos({ 200 + i * 200, 100 });
		enemy->SetSize({ 50,50 });
		if (i == 2)
			enemy->Scale(1.5f);
		enemy->SetFormation(formation, { (i - 2) * 200.f, 0.f });
	}

	Object* player = AddObject<Player>(Layer::Player);
	player->SetPos({ WINDOW_WIDTH / 2,
		WINDOW_HEIGHT / 2 });
	player->SetSize({ 50,50 });
}
void GameScene::OnUpdate()
{
	if(GET_KEYDOWN(Key::ESC))
		GET_SINGLE(SceneManager)->LoadScene(L"Title");
}
void GameScene::OnRender(HDC hdc)
{
}

