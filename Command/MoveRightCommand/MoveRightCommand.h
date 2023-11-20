#pragma once
#include "../ICommand/ICommand.h"

class MoveRightCommand : public ICommand{

public: 
	void Execution(Player& player) override;

};

