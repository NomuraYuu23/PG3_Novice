#include "Player.h"
#include <Novice.h>

void Player::Initialize()
{

	// 位置
	position_ = {640.0f, 360.0f};

	// サイズ(半径)
	radius_ = 50.0f;

	// 速さ
	speed_ = 3.0f;

}

void Player::Update()
{

	Move();

	Fire();

}

void Player::Draw()
{
	// 円を表示する
	Novice::DrawEllipse(static_cast<int>(position_.x), static_cast<int>(position_.y),
		static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, RED, kFillModeSolid);

}

void Player::Move()
{
}

void Player::Fire()
{
}
