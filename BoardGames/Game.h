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
	Game();					//!< Default Game constructor
	virtual void legal(vector<Point> &legalMoves, Piece &piece){}; //!< Virtual void, returns legal moves for piece in current game with moves ref
	virtual void start();	//!< Virtual void to start game
	virtual void make(int FromX,int FromY,int ToX,int ToY); //!< Virtual void to make move, move 1 piece from cord to other cord
	virtual void go();				//!< Virtual void function to let cpu make move according to difficult level
	void retract();			//!< Retract last move, pops GameBoard state and sets game to last state
	virtual void display(int height,int with); //!< Display board
	
	virtual void evaluate();		//!< Virtual void, evaluate if player can make move in current position and set score
	void debug();					//!< Switch between debug mode and non-debug mode
	void quit();					//!< Exit program
	string GetName();				//!< Returns name 
	void setDifficulty(int diff);	//!< Sets difficult state 0 = random, 1 = easy, 2 = medium, 3 = hard
	int getDifficulty();			//!< Returns current difficulty level
	void GetTestGame();				//!< Runs Test game

	void checkFinished();			//!< Prints out result if game has finished
	bool Debug;				/**< Toggle switch for debugging, if true program prints debug info  */
	Board GameBoard;		/**< Game instance of class GameBoard */
	bool canMake(Piece *piece, Point p);	//!< Cheks if piece can make move to cord p
protected:
	string GameName;		/**< Name of the game */
	int player1_pieces;		/**< Amount of pieces for player 1 */
	int player2_pieces;		/**< Amount of pieces for player 2 */
	int difficulty;			/**< Keeps difficulty level */
	vector<Board> history;	/**< Vector of each game state, changes each turn */
	int MaxPlays;			/**< Keeps max moves in game */
	int CurrentTurn;		/**< Keeps current move, counts each move */
	int CurrentPlayer;		/**< Indicates who´s player turn it is */

};
#endif