#pragma once
#include "Vector2.h"
#include "../Bullet/Bullet.h"
#include <list>
#include <Program/InputManager/InputManager.h>

/// <summary>
/// プレイヤー
/// </summary>
class Player
{

public: // メンバ関数

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

public: // アクセッサ

	/// <summary>
	/// 弾取得
	/// </summary>
	/// <returns></returns>
	std::list<Bullet*> GetBullets() { return bullets_; }

private: // メンバ関数

	/// <summary>
	/// 移動
	/// </summary>
	void Move();

	/// <summary>
	/// 発射
	/// </summary>
	void Fire();

	/// <summary>
	/// 弾の更新
	/// </summary>
	void BulletsUpdate();

private: // メンバ変数

	// 位置
	Vector2 position_;

	// サイズ(半径)
	float radius_;

	// 速さ
	float speed_;

	// 弾
	std::list<Bullet*> bullets_;

	// 入力マネージャー
	InputManager* inputManager_;

};

