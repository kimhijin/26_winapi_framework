#pragma once
#include "GameScene.h"

class Core
{
	DECLARE_SINGLETON(Core);
public:
	bool Init(HWND hWnd);
	void GameLoop();
	void CleanUp();
private:
	void MainUpdate();
	void MainRender();
private:
	void CreateBackBuffer();
	void ReleaseBackBuffer();
public:
	HWND GetHwnd() const { return m_hWnd; }
private :
	GameScene m_gameScene;

	HBITMAP m_hBackBit;
	HDC m_hBackDC;
	HWND m_hWnd;
	HDC m_hDC;
};

