#include "MoveRightCommand.h"
#include "Player/Player.h"

void MoveRightCommand::Execution(Player& player)
{
	player.MoveRight();
}
