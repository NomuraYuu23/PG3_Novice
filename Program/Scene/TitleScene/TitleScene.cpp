#include "TitleScene.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{

	if (inputManager_->GetPreKeys()[DIK_SPACE] == 0 &&
		inputManager_->GetKeys()[DIK_SPACE] != 0) {
		sceneNo = STAGE;
	}

}

void TitleScene::Draw()
{

	Novice::ScreenPrintf(640, 350, "TITLE SCENE");
	Novice::ScreenPrintf(640, 370, "Push SPACE!");

}
