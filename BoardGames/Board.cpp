#include "Board.h"

Board::Board(int h,int w)
{
	for(int i = 0;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			GameBoard[i,j]= new Piece("0",0,Point(i,j));
		}
	}

}

Board::CheckOwner(int X,int Y)
{
	if(GameBoard[X,Y].m_playerNumber == 1)
				{
					return "P";
				}
				else if(GameBoard[X,Y].m_playerNumber == 2)
				{
					return "p";
				}
				else
				{
				return "0";
				}
}