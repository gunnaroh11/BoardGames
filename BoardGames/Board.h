#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Pieces.h"
#include <string>

/*! \brief Brief description.
 *	Gameboard used by class Game, contains pieces and size etc for common properties and functions for 
 *	board games		
 */
class Board
{
public:
	//! default constructor
	Board(); 
	//! constructor sets height and width of board
	/*!
		\param h heigt
		\param w width
	*/
	Board(int h,int w); 
	//! assignment operator
	Board& operator=(Board& rhs); 
	//! Checks for owner of piece placed on provided cord returns string value for player
	/*!
		\param X x value for piece position cord
		\param Y y value for piece position cord
	*/
	std::string CheckOwner(int X,int Y); 
	//! Reverts moves
	/*!	
		\param G Current board to revert
	*/
	void Revert(Board G);
	//! Sets size of board
	/*!
		\param h heigt
		\param w width
	*/
	//! Returns width of the board
	void SetSize(int h,int w);
	//! Returns width of the board
	int getWidth(); 
	//! Returns height of the board
	int getHeight();
	//! Generates board
	void GenerateBoard(); 
	//! Vector of gameboards and states of game
	std::vector<std::vector<Piece> > GameBoard;
	
	//! Amount of pieces for player 1 
	int player1_pieces;		
	//! Amount of pieces for player 2 
	int player2_pieces;		
	
private:
	int height; //!< Height of the board
	int width; //!< Width of the board	
	
};
#endif