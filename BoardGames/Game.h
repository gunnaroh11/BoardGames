#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
#include "Pieces.h"

using namespace std;

/*! \brief Brief description.
 *         Class Game use as base interface for 2 player board games.
 *
 *  Game class is used as parent class for each type of boardgames. The class has some 
 *  basic default actions. 
 */

class Game
{
public:
	bool m_finished;		/**< Indicates if still possible to make moves or if game has finished */
	Game();
	virtual void legal(vector<Point> &legalMoves, Piece &piece){};
	virtual void start();
	virtual void make(int FromX,int FromY,int ToX,int ToY);
	void go();
	void retract();
	virtual void display(int height,int with);
	
	void evaluate();
	void debug();
	void quit();
	string GetName();
	void setDifficulty(int diff);
	int getDifficulty();
	void GetTestGame();
<<<<<<< HEAD
	void checkFinished();
	bool Debug;				/**< Toggle switch for debugging, if true program prints debug info  */
	Board GameBoard;		/**< Game instance of class GameBoard */
=======
	virtual void checkFinished();
	bool Debug;
	Board GameBoard;
>>>>>>> a4ac5c15d42ba045452087062e26d138dffe3632
	bool canMake(Piece *piece, Point p);
protected:
	string GameName;		/**< Name of the game */
	int player1_pieces;
	int player2_pieces;
	int difficulty;
	vector<Board> history;
	int MaxPlays;
	int CurrentTurn;
	int CurrentPlayer;

};
#endif