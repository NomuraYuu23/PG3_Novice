#pragma once
#include "Vector2.h"

/// <summary>
/// 弾
/// </summary>
class Bullet
{

public: // メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="position">位置</param>
	void Initialize(const Vector2& position);

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
	/// しんでるか
	/// </summary>
	/// <returns></returns>
	bool IsDead() { return isDead_; }

private: // メンバ関数

	/// <summary>
	/// 移動
	/// </summary>
	void Move();

	/// <summary>
	/// 死亡判定
	/// </summary>
	void Death();

private: // メンバ変数

	// 位置
	Vector2 position_;

	// サイズ(半径)
	float radius_;

	// 速さ
	float speed_;

	// 死亡フラグ
	bool isDead_;

};

