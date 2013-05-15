#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Pieces.h"
#include <string>
class Board
{
public:
	Board(){};
	Board(int h,int w);
	std::string CheckOwner(int X,int Y);
	void Revert(Board G);
	void SetSize(int h,int w);
	void GenerateBoard();
private:
	int height;
	int width;
	std::vector<std::vector<Piece> > GameBoard;
};
#endif