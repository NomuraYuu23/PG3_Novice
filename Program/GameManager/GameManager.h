#pragma once

#include <memory>
#include "Program/Scene/IScene/IScene.h"
#include "Program/Scene/TitleScene/TitleScene.h"
#include "Program/Scene/StageScene/StageScene.h"
#include "Program/Scene/ClearScene/ClearScene.h"

#include "Program/InputManager/InputManager.h"

/// <summary>
/// ゲームマネージャー
/// </summary>
class GameManager
{

private: // メンバ変数

	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	// どのステージを呼び出すかを管理する変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_; // 前のシーン

	// 入力マネージャー
	InputManager* inputManager_;

public: // メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameManager();

	/// <summary>
	/// ゲームループを呼び出す
	/// </summary>
	/// <returns></returns>
	int Run(); 

};

