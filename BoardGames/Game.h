#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
using namespace std;

class Game
{
public:
	bool m_finished;
	Game();
	void legal();
	virtual void start();
	void make(int FromX,int FromY,int ToX,int ToY);
	void go();
	void retract();
	virtual void display(int height,int with);
	
	void evaluate();
	void level(std::string difficulty);
	void debug();
	void quit();
	string GetName();
	void setDifficulty(int diff);
	int getDifficulty();
	void GetTestGame();

protected:
	string GameName;
	bool Debug;
	int difficulty;
	Board GameBoard;
	vector<Board> history;
	int MaxPlays;
	int CurrentTurn;
	int CurrentPlayer;

};
#endif