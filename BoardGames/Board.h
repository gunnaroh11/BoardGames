#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Pieces.h"
#include <string>
class Board
{
public:
	Board();
	Board(int h,int w);
	std::string CheckOwner(int X,int Y);
	void Revert(Board G);
	void SetSize(int h,int w);
	int getWidth();
	int getHeight();
	void GenerateBoard();
	std::vector<std::vector<Piece> > GameBoard;
private:
	int height;
	int width;
	
};
#endif