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
	//! Default Game constructor 	
	Game();					

	//!< Virtual void, returns legal moves for piece in current game with moves ref
	/*!
		\param &legalMoves a reference to vector of Point. Returns legal moves in vector
		\param &piece a reference to piece being moved	
	*/
	virtual void legal(vector<Point> &legalMoves, Piece &piece){}; 
	
	//!< Virtual void to start game
	virtual void start();	

	//!< Virtual void to make move, move 1 piece from cord to other cord
	/*!
		\param FromX x value for piece to be moved
		\param FromY y value for piece to be moved
		\param ToX x value for destination
		\param ToY y value for destination
	*/
	virtual void make(int FromX,int FromY,int ToX,int ToY); 

	//!< Virtual void function to let cpu make move according to difficult level
	virtual void go();				
	
	//!< Retract last move, pops GameBoard state and sets game to last state
	void retract();			
	
	//!< Display board
	virtual void display(); 
	
	//!< Virtual void, evaluate if player can make move in current position and set score
	virtual void evaluate();		
	
	//!< Switch between debug mode and non-debug mode
	void debug();					
	
	//!< Exit program
	void quit();		

	//!< Returns name 
	string GetName();				

	//!< Sets difficult state 0 = random, 1 = easy, 2 = medium, 3 = hard
	void setDifficulty(int diff);	

	//!< Returns current difficulty level
	int getDifficulty();			

	//!< Runs Test game
	void GetTestGame();				

	/**< Indicates if still possible to make moves or if game has finished */
	bool m_finished;		

	//!< Prints out result if game has finished
	void checkFinished();	

	/**< Toggle switch for debugging, if true program prints debug info  */
	bool Debug;				

	/**< Game instance of class GameBoard */
	Board GameBoard;		

	//!< Cheks if piece can make move to cord p
	bool canMake(Piece *piece, Point p);	

protected:
	/**< Name of the game */
	string GameName;		
	/**< Amount of pieces for player 1 */
	int player1_pieces;		
	/**< Amount of pieces for player 2 */
	int player2_pieces;		
	/**< Keeps difficulty level */
	int difficulty;			
	/**< Vector of each game state, changes each turn */
	vector<Board> history;	
	/**< Keeps max moves in game */
	int MaxPlays;			
	/**< Keeps current move, counts each move */
	int CurrentTurn;		
	/**< Indicates who´s player turn it is */
	int CurrentPlayer;		

};
#endif