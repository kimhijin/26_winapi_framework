#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	void Init() override;
protected:
	void OnUpdate() override;
	void OnRender(HDC hdc) override;
};

