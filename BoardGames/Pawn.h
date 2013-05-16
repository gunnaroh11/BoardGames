#ifndef PAWN_H
#define PAWN_H
#include "Pieces.h"
class Pawn : Piece
{
public:
	Pawn();
	virtual void getMoves(std::vector<Point> &points, const int boardSize);
};
#endif