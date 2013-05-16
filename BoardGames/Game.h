#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "Board.h"

class Game
{
public:
	bool m_finished;
	Game();
	void legal();
	virtual void start();
	virtual void make(int FromX,int FromY,int ToX,int ToY);
	void go();
	void retract();
	virtual void display(int height,int with);
	
	void evaluate();
	void level(std::string difficulty);
	void debug();
	void quit();
	std::string GetName();
	void setDifficulty(int diff);
	int getDifficulty();
	void GetTestGame();
	void checkFinished();
	bool Debug;
	Board GameBoard;

protected:
	std::string GameName;
	int player1_pieces;
	int player2_pieces;
	int difficulty;
	std::vector<Board> history;
	int MaxPlays;
	int CurrentTurn;
	int CurrentPlayer;

};
#endif