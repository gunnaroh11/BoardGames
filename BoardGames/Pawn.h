#ifndef PAWN_H
#define PAWN_H
#include "Pieces.h"

/*! \brief Brief description.
 *	Pawn is a derived class from Piece and implements its own function getMoves		
 */
class Pawn : Piece
{
public:
	//! Defeult constructor
	Pawn();
	//! Gets avalible moves for current Pawn
	/*!
		\param &points result vector of Point 
		\param boardSize Size of the board
	*/
	virtual void getMoves(std::vector<Point> &points, const int boardSize);
};
#endif