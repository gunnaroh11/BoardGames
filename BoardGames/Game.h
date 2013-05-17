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
	virtual void legal(vector<Point> &legalMoves, Piece &piece);
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
	void checkFinished();
	bool Debug;
	Board GameBoard;
	bool canMake(Piece *piece, Point p);
protected:
	string GameName;
	int player1_pieces;
	int player2_pieces;
	int difficulty;
	vector<Board> history;
	int MaxPlays;
	int CurrentTurn;
	int CurrentPlayer;

};
#endif