#pragma once
#include <Vector2.h>

/// <summary>
/// エネミー
/// </summary>
class Enemy
{

public: // メンバ関数

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
	/// しんでるか
	/// </summary>
	/// <returns></returns>
	bool IsDead() { return isDead_; }

	/// <summary>
	/// 死ぬ
	/// </summary>
	/// <returns></returns>
	void SetIsDead(bool isDead) { isDead_ = isDead; }

	/// <summary>
	/// 位置取得
	/// </summary>
	/// <returns></returns>
	Vector2 GetPosition() { return position_; }

	/// <summary>
	/// 半径取得
	/// </summary>
	/// <returns></returns>
	float GetRadius() { return radius_; }

private: // メンバ関数

	/// <summary>
	/// 移動
	/// </summary>
	void Move();

private: // メンバ変数

	// 位置
	Vector2 position_;

	// サイズ(半径)
	float radius_;

	// 速さ
	float speed_;

	// 移動方向
	bool isLeftMove_;

	// 死亡フラグ
	bool isDead_;

};

