#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager()
{
	// 各シーン
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	// 初期シーン
	currentSceneNo_ = TITLE;
	prevSceneNo_ = TITLE;

	// シーンの静的初期化
	sceneArr_[currentSceneNo_]->StaticInit();

	// 入力マネージャー
	inputManager_ = InputManager::GetInstance();

}

GameManager::~GameManager(){}

int GameManager::Run()
{

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame(); // フレームの開始

		// 入力マネージャー更新
		inputManager_->Update();

		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		// 更新処理
		sceneArr_[currentSceneNo_]->Update(); // シーンごとの更新処理

		// 描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame(); // フレームの終了

		// ESCキーが押されたらループを抜ける
		if (inputManager_->GetPreKeys()[DIK_ESCAPE] == 0 && inputManager_->GetKeys()[DIK_ESCAPE] != 0) {
			break;
		}

	}

	return 0;
}
