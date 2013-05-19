#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Pieces.h"
#include <string>
class Board
{
public:
	Board();
	Board(int h,int w);
	Board& operator=(Board& rhs);
	std::string CheckOwner(int X,int Y);
	void Revert(Board G);
	void SetSize(int h,int w);
	int getWidth();
	int getHeight();
	void GenerateBoard();
	std::vector<std::vector<Piece> > GameBoard;
	/**< Amount of pieces for player 1 */
	int player1_pieces;		
	/**< Amount of pieces for player 2 */
	int player2_pieces;	
private:
	int height;
	int width;
	
};
#endif