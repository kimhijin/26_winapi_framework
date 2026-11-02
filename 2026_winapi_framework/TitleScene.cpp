#include "pch.h"
#include "TitleScene.h"
#include "SceneManager.h"

void TitleScene::Init()
{
}

void TitleScene::OnUpdate()
{
	if (GET_KEYDOWN(Key::ENTER))
		GET_SINGLE(SceneManager)->LoadScene(L"Game");
}

void TitleScene::OnRender(HDC hdc)
{
	Utils::DrawTextBox(hdc, { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 }, { WINDOW_WIDTH, 100 },
		L"TITLE  -  Press ENTER");
}


