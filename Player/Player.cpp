#include "Player.h"
#include <Novice.h>
#include <cstdint>

Player::Player()
{
}

void Player::Initialize()
{

	position_ = { 100.0f, 100.0f};
	speed_ = 5.0f;

}

void Player::Update()
{
}

void Player::Draw()
{

	int radius = 50;
	Novice::DrawEllipse(static_cast<int32_t>(position_.x), static_cast<int32_t>(position_.y), radius, radius, 0.0f, RED, kFillModeSolid);

}

void Player::MoveRight()
{

	this->position_.x += this->speed_;

}

void Player::MoveLeft()
{

	this->position_.x -= this->speed_;

}
