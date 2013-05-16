#include "Board.h"
#include <iostream>
Board::Board()
{
	height = 5;
	width = 5;
	for(int i = 0;i<height;i++)
	{
		std::vector<Piece> temp;
		for(int j = 0;j<width;j++)
		{
			temp.push_back(Piece("0",2,Point(i,j)));
		}
		GameBoard.push_back(temp);
	}

}


Board::Board(int h,int w)
{
	for(int i = 0;i<h;i++)
	{
		std::vector<Piece> temp;
		for(int j = 0;j<w;j++)
		{
			temp.push_back(Piece("0",2,Point(i,j)));
		}
		GameBoard.push_back(temp);
	}

}

std::string Board::CheckOwner(int X,int Y)
{
	if(GameBoard[X][Y].getPlayer() == 0)
				{
					return "P";
				}
				else if(GameBoard[X][Y].getPlayer() == 1)
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

int Board::getWidth(){
	return width;
}

int Board::getHeight(){
	return height;
}
void Board::GenerateBoard()
{
	for(int i = 0;i<height;i++)
		{
			for(int j = 0;j<width;j++)
			{
				GameBoard[i][j].print();
			}
			std::cout<<std::endl;
		}
}
