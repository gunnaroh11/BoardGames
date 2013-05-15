#include "Game.cpp"
class TestGame : Game
{

	virtual void start()
	{
		Debug = false;
		difficulty = 0;
		MaxPlays = 10;
		CurrentTurn = 0;
		CurrentPlayer = 1;
		GameBoard.SetSize(5,5);
	}
	

};