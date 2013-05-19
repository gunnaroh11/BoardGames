#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include "Game.h"
#include "Pieces.h"

/*! \brief Brief description.
 *         Class Breaktrough derived from Game interface class
 *
 *  Breaktrough implements the game "Breaktrough", a two player boardgame
 *  A piece may move one space straight or diagonally forward if the target square is empty. 
 *  In the diagram on the right, the white piece on c5 can move into any of the marked squares.
 *  A piece may move into a square containing an opponent's piece if and only if that square is 
 *  one step diagonally forward. The opponent's piece is removed and the player's piece replaces it. 
 *  For example, the black piece can capture either the white piece e2 or the one on g2; it would 
 *  replace them if it chose to capture. Note that capturing is not compulsory, nor is it "chained" 
 *  as in checkers.
 *  The first player to reach the opponent's home row - the one farthest from the player - is the winner. 
 *  If all the pieces of a player are captured, that player loses. A draw is impossible because pieces 
 *  can only move ahead (or be captured), and the piece closest to the opponent's home row always has at 
 *  least one forward diagonal move available.
 */

class Breaktrough : public Game
{
public:
	//! Default Breaktrhough game constructor
	Breaktrough();
	
	//! initialize pieces for players and set distance for moves for each direction
	/*! \param P player number */
	void setMoveForPlayer(int P);
	
	//! Make move from current cord to dest cord
	/*!
		\param FromX x value for from cord
		\param FromY y value for from cord
		\param ToX x value for To cord
		\param ToY y value for To cord
	*/
	virtual void make(int FromX,int FromY,int ToX,int ToY);
	

	//! Initialize and starta game Breakthrough	
	virtual void start();

	//! Get legal moves for piece, returns up to 3 legal cords depending on position. Front, FrontRight, and FrontLeft
	/*! \param &legalMoves result vector of Point for legal destination cords
		\param &piece reference to piece to move		
		\sa Point
		\sa Game::getMoves(std::vector<Point> &points, const int boardSize)
	*/
	void legal(vector<Point> &legalMoves, Piece &piece);
	
	virtual void checkFinished();
	//!< Check if game has ended

	//! Swaps pieces from one point to another when making moves
	/*! \param From source cord
		\param To destination cord
		\param player player number
	*/
	void SwapTiles(Point From,Point To,int player);
	

private:
protected:
};
#endif
