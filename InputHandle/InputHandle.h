#pragma once
#include "Command/ICommand/ICommand.h"

class InputHandle
{
public: 
	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveLeftCommand2PressKeyD();

private:

	ICommand* pressKeyA_;
	ICommand* pressKeyD_;

};

