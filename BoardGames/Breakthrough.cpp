#include "Breakthrough.h"

Breaktrough::Breaktrough()
{
}

void Breaktrough::start()
{
	m_finished = false;
		GameName = "Breakthogh";
			Debug = false;
		difficulty = 0;
		GameBoard.SetSize(7,7);
		player1_pieces = GameBoard.getWidth()*2;
		player2_pieces = GameBoard.getWidth()*2;
		MaxPlays = 100;
		CurrentTurn = 0;
		CurrentPlayer = 0;
		
		setMoveForPlayer(0);
		setMoveForPlayer(1);
		
		GameBoard.GenerateBoard();
		history.push_back(GameBoard);
}
void Breaktrough::setMoveForPlayer(int P)
{
	if(P == 0)
	{
		for(int i = 0; i<2;i++)
		{
			for(int j= 0;j<GameBoard.getWidth();j++)
			{
				GameBoard.GameBoard[i][j].setPlayer(0);
				GameBoard.GameBoard[i][j].setMoves(1,1,1,1);
			}
		}
	}
	else
	{
	}
}

void Breaktrough::make(int FromX,int FromY,int ToX,int ToY)
{

}