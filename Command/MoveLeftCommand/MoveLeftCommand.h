#pragma once
#include "../ICommand/ICommand.h"
class MoveLeftCommand : public ICommand{

public:
	void Execution(Player& player) override;

};

