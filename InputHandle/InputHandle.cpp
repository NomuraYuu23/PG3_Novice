#include "InputHandle.h"
#include "Command/MoveLeftCommand/MoveLeftCommand.h"
#include "Command/MoveRightCommand/MoveRightCommand.h"
#include <Novice.h>

ICommand* InputHandle::HandleInput()
{
	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}

	return nullptr;
}

void InputHandle::AssignMoveLeftCommand2PressKeyA(){
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

void InputHandle::AssignMoveLeftCommand2PressKeyD()
{
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}
