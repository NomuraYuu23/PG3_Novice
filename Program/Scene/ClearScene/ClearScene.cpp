#include "ClearScene.h"

void ClearScene::Init()
{
}

void ClearScene::Update()
{

	if (inputManager_->GetPreKeys()[DIK_SPACE] == 0 &&
		inputManager_->GetKeys()[DIK_SPACE] != 0) {
		sceneNo = TITLE;
	}

}

void ClearScene::Draw()
{

	Novice::ScreenPrintf(640, 350, "CLEAR SCENE");
	Novice::ScreenPrintf(640, 370, "Push SPACE!");

}
