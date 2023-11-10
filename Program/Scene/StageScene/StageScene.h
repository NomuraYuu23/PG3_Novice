#pragma once

#include "Program/Scene/IScene/IScene.h"

#include <memory>

#include "Program/Object/Player/Player.h"
#include <Program/Object/Enemy/Enemy.h>

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


private: // メンバ関数

	/// <summary>
	/// 衝突処理
	/// </summary>
	void Collision();

private: // メンバ変数

	// プレイヤー
	std::unique_ptr<Player> player_;

	// エネミー
	std::unique_ptr<Enemy> enemy_;

};
