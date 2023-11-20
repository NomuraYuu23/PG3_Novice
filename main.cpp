#include <Novice.h>
#include "Player/Player.h"
#include "InputHandle/InputHandle.h"
#include "Command/ICommand/ICommand.h"

const char kWindowTitle[] = "LE2A_16_ノムラユウ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//変数
	InputHandle* inputHandle_ = new InputHandle();
	inputHandle_->AssignMoveLeftCommand2PressKeyA();
	inputHandle_->AssignMoveLeftCommand2PressKeyD();
	ICommand* command_ = nullptr;
	Player* player_ = new Player();
	player_->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		command_ = inputHandle_->HandleInput();

		if (command_) {
			command_->Execution(*player_);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player_->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
