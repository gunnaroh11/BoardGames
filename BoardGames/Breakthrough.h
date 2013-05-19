#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "Game.h"
#include "Pieces.h"

class Breaktrough : public Game
{
public:
	//!< Default Breaktrhough game constructor
	Breaktrough();

	//!< initialize pieces for players and set distance for moves for each direction
	/*!
		\param P indicates what player, 0=player1 and 1 = player2
	*/
	void setMoveForPlayer(int P);
	
	//void display(int height,int with);

	//!< Make move from current cord to dest cord
	/*!
		\param FromX cord
		\param FromY cord
		\param ToX cord
		\param ToY cord
	*/
	virtual void make(int FromX,int FromY,int ToX,int ToY);


	//!< Initialize and starta game Breakthrough
	virtual void start();

	//!< Get legal moves for piece, returns up to 3 legal cords depending on position. Front, FrontRight, and FrontLeft
	/*!
		\param &legalMoves reference to result vector
		\param &piece reference to piece being moved
	*/	
	void legal(vector<Point> &legalMoves, Piece &piece);

	//!< Check if game has ended
	virtual void checkFinished();

	void SwapTiles(Point From,Point To,int player);
	
private:
protected:
};
#endif
