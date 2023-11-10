#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize()
{

	// 位置
	position_ = {640.0f, 100.0f};

	// サイズ(半径)
	radius_ = 50.0f;

	// 速さ
	speed_ = 4.0f;

	// 移動方向
	isLeftMove_ = false;

	// 死亡フラグ
	isDead_ = false;

}

void Enemy::Update()
{

	Move();

}

void Enemy::Draw()
{

	// 円を表示する
	Novice::DrawEllipse(static_cast<int>(position_.x), static_cast<int>(position_.y),
		static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, BLACK, kFillModeSolid);


}

void Enemy::Move()
{

	if (isLeftMove_) {
		position_.x -= speed_;
		if (position_.x <= radius_) {
			position_.x = radius_;
			isLeftMove_ = false;
		}
	}
	else {
		position_.x += speed_;
		if (position_.x >= 1280.0f - radius_) {
			position_.x = 1280.0f - radius_;
			isLeftMove_ = true;
		}
	}

}
