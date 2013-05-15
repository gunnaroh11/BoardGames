#include "Board.h"

Board::Board(int h,int w)
{
	for(int i = 0;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			//GameBoard[i,j]= Piece("0",0,Point(i,j));
		}
	}

}

std::string Board::CheckOwner(int X,int Y)
{
	if(GameBoard[X][Y].getPlayer() == 1)
				{
					return "P";
				}
				else if(GameBoard[X][Y].getPlayer() == 2)
				{
					return "p";
				}
				else
				{
				return "0";
				}
}
void Board::Revert(Board G)
{
	//GameBoard = G;
}
void Board::SetSize(int h,int w)
{
	height = h;
	width = w;
}
