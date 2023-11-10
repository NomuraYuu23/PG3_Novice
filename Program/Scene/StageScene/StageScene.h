#pragma once

#include "Program/Scene/IScene/IScene.h"

#include <memory>

#include "Program/Object/Player/Player.h"

class StageScene : public IScene
{

public: // メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	void Init() override;

	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private: // メンバ変数

	// プレイヤー
	std::unique_ptr<Player> player_;

};
