#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "Game.h"
class Breaktrough : public Game
{
public:
	Breaktrough();
	void setMoveForPlayer(int P);
	//void display(int height,int with);
	virtual void make(int FromX,int FromY,int ToX,int ToY);
	virtual void start();


	
private:
protected:
};
#endif
