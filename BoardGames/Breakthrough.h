#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "Game.h"
#include "Pieces.h"

class Breaktrough : public Game
{
public:
	Breaktrough();
	void setMoveForPlayer(int P);
	//void display(int height,int with);
	virtual void make(int FromX,int FromY,int ToX,int ToY);
	virtual void start();
	void legal(vector<Point> &legalMoves, Piece &piece);

	void legal(vector<Point> &legalMoves, Piece &piece);

	virtual void checkFinished();
	
private:
protected:
};
#endif
