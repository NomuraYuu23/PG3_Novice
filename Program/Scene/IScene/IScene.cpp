#include "IScene.h"

//タイトルシーンで初期化
int IScene::sceneNo = TITLE;

IScene::~IScene(){}

int IScene::GetSceneNo() { return sceneNo; }
