#pragma once
#include <Vector2.h>

/// <summary>
/// 
/// </summary>
class Player
{

private: // メンバ変数

	// 位置
	Vector2 position_;
	// 速度
	float speed_;

public: // メンバ関数

	Player();

	void Initialize();
	void Update();
	void Draw();

	// キーごとにコマンドを作る
	void MoveRight();
	void MoveLeft();

};

