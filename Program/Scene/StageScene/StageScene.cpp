#include "StageScene.h"

void StageScene::Init()
{

	player_ = std::make_unique<Player>();
	player_->Initialize();

}

void StageScene::Update()
{

	player_->Update();

}

void StageScene::Draw()
{

	player_->Draw();

}
