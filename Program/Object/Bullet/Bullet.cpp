#include "Bullet.h"
#include <Novice.h>

void Bullet::Initialize(const Vector2& position)
{

	// 位置
	position_ = position;

	// サイズ(半径)
	radius_ = 10.0f;

	// 速さ
	speed_ = 10.0f;

}

void Bullet::Update()
{

	Move();

	Death();

}

void Bullet::Draw()
{

	// 円を表示する
	Novice::DrawEllipse(static_cast<int>(position_.x), static_cast<int>(position_.y),
		static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, BLUE, kFillModeSolid);

}

void Bullet::Move()
{
	
	position_.y -= speed_;

}

void Bullet::Death()
{

	if (position_.y < -radius_) {
		isDead_ = true;
	}

}
