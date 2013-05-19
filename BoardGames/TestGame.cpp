#include "Game.h"
#include "TestGame.h"

TestGame::TestGame()
{};
void TestGame::start()
{
	Debug = false;
	difficulty = 0;
	MaxPlays = 10;
	CurrentTurn = 0;
	CurrentPlayer = 1;
	GameBoard.SetSize(5,5);
};
	

