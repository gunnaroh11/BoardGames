#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "Game.h"
class Breaktrough : Game
{
public:
	Breaktrough();
	void setMoveForPlayer(int P);
	virtual void make(int FromX,int FromY,int ToX,int ToY);
	virtual void start();


	
private:
protected:
};
#endif
