#include <Novice.h>
#include "Program/GameManager/GameManager.h"

const char kWindowTitle[] = "LE2A_16_ノムラユウ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// ゲームマネージャー
	std::unique_ptr<GameManager> gameManager;
	gameManager = std::make_unique<GameManager>();
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
