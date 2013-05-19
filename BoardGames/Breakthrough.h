#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "Game.h"
#include "Pieces.h"

class Breaktrough : public Game
{
public:
	
	Breaktrough();
	//!< Default Breaktrhough game constructor
	
	void setMoveForPlayer(int P);
	//!< initialize pieces for players and set distance for moves for each direction

	virtual void make(int FromX,int FromY,int ToX,int ToY);
	//!< Make move from current cord to dest cord

	
	virtual void start();
	//!< Initialize and starta game Breakthrough
	
	void legal(vector<Point> &legalMoves, Piece &piece);
	//!< Get legal moves for piece, returns up to 3 legal cords depending on position. Front, FrontRight, and FrontLeft
	
	virtual void checkFinished();
	//!< Check if game has ended
private:
protected:
};
#endif
