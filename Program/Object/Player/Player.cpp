#include "Player.h"
#include <Novice.h>
#include <cmath>

Player::~Player()
{

	bullets_.remove_if([](Bullet* bullet) {
		delete bullet;
		return true;
	});

}

void Player::Initialize()
{

	// 位置
	position_ = {640.0f, 360.0f};

	// サイズ(半径)
	radius_ = 50.0f;

	// 速さ
	speed_ = 5.0f;

	inputManager_ = InputManager::GetInstance();

}

void Player::Update()
{

	Move();

	Fire();

	BulletsUpdate();

}

void Player::Draw()
{

	// 弾を表示する
	for (Bullet* bullet : bullets_) {
		bullet->Draw();
	}

	// 円を表示する
	Novice::DrawEllipse(static_cast<int>(position_.x), static_cast<int>(position_.y),
		static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, RED, kFillModeSolid);

}

void Player::Move()
{

	// 移動用変数
	Vector2 move = { 0.0f,0.0f };
	float length = 0.0f;

	// キーの確認
	bool up = inputManager_->GetKeys()[DIK_W] || inputManager_->GetKeys()[DIK_UP];
	bool down = inputManager_->GetKeys()[DIK_S] || inputManager_->GetKeys()[DIK_DOWN];
	bool left = inputManager_->GetKeys()[DIK_A] || inputManager_->GetKeys()[DIK_LEFT];
	bool right = inputManager_->GetKeys()[DIK_D] || inputManager_->GetKeys()[DIK_RIGHT];

	if (up && down) {
		up = false;
		down = false;
	}

	if (left && right) {
		left = false;
		right = false;
	}

	// 移動しないのでリターン
	if (!(up || down || left || right)) {
		return;
	}

	// 移動方向確認
	if (up) {
		move.y = -1.0f;
	}
	if (down) {
		move.y = 1.0f;
	}
	if (left) {
		move.x = -1.0f;
	}
	if (right) {
		move.x = 1.0f;
	}

	// 正規化
	length = std::sqrtf(move.x * move.x + move.y * move.y);
	move.x = move.x / length;
	move.y = move.y / length;

	// 速度をかける
	move.x *= speed_;
	move.y *= speed_;

	// 移動
	position_.x += move.x;
	position_.y += move.y;

	// 制限
	if (position_.x < 0.0f + radius_) {
		position_.x = 0.0f + radius_;
	}
	if (position_.x > 1280.0f - radius_) {
		position_.x = 1280.0f - radius_;
	}
	if (position_.y < 0.0f + radius_) {
		position_.y = 0.0f + radius_;
	}
	if (position_.y > 720.0f - radius_) {
		position_.y = 720.0f - radius_;
	}

}

void Player::Fire()
{
	
	if (inputManager_->GetKeys()[DIK_SPACE] && inputManager_->GetPreKeys()[DIK_SPACE] == 0) {
		Bullet* bullet = new Bullet();
		bullet->Initialize(position_);
		bullets_.push_back(bullet);
	}

}

void Player::BulletsUpdate()
{

	bullets_.remove_if([](Bullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});

	for (Bullet* bullet : bullets_) {
		bullet->Update();
	}

}
