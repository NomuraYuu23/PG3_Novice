#include "MoveLeftCommand.h"
#include "Player/Player.h"

void MoveLeftCommand::Execution(Player& player)
{
	player.MoveLeft();
}
