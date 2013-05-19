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
<<<<<<< HEAD
=======
struct PlayerPieces
{

};
struct PlayedGames
{
	Point From;
	Point To;
	int score;

	PlayedGames(Point F,Point T,int S)
	{
		From = F;
		To = T;
		score = S;
	}
};

>>>>>>> 66a1f031ff56ce17cc7a86bebe47e02e639c9472
class Game
{
public:
	
	Game();					
<<<<<<< HEAD
	//!< Default Game constructor 	
	
	
	virtual void legal(vector<Point> &legalMoves, Piece &piece){}; 
	//!< Virtual void, returns legal moves for piece in current game with moves ref
	
	
=======

	//!< Virtual void, returns legal moves for piece in current game with moves ref
	/*!
		\param &legalMoves a reference to vector of Point. Returns legal moves in vector
		\param &piece a reference to piece being moved	
	*/
	virtual void legal(vector<Point> &legalMoves, Piece &piece); 
	virtual void PlayerLegal(vector<PlayedGames> &Moves,int player); 
	//!< Virtual void to start game
>>>>>>> 66a1f031ff56ce17cc7a86bebe47e02e639c9472
	virtual void start();	
	//!< Virtual void to start game
	
	virtual void make(int FromX,int FromY,int ToX,int ToY); 
<<<<<<< HEAD
	//!< Virtual void to make move, move 1 piece from cord to other cord
	
	
	virtual void go();				
	//!< Virtual void function to let cpu make move according to difficult level
=======

	//!< Virtual void function to let cpu make move according to difficult level
	virtual void go();		
	virtual PlayedGames go(Board B,int player,int deapth);
>>>>>>> 66a1f031ff56ce17cc7a86bebe47e02e639c9472
	
	void retract();			
	//!< Retract last move, pops GameBoard state and sets game to last state
	
	virtual void display(); 
	//!< Display board
	//!< Virtual void, evaluate if player can make move in current position and set score
	//virtual void evaluate();		
	virtual int evaluate(Board B,int P);		//!< Virtual void, 

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