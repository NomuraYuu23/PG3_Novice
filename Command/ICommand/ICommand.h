#pragma once

// 前方宣言
class Player;

class ICommand
{
public: // メンバ関数

	virtual ~ICommand() = default;
	virtual void Execution(Player &player) = 0;

};

