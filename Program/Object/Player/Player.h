#pragma once
#include "Vector2.h"

class Player
{

public: // メンバ関数

	void Initialize();

	void Update();

	void Draw();

private: // メンバ関数

	void Move();

	void Fire();

private: // メンバ変数

	// 位置
	Vector2 position_;

	// サイズ(半径)
	float radius_;

	// 速さ
	float speed_;

};

