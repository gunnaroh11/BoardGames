#include <vector>
#include "Pieces.h"
#include <string>
class Board
{
public:
	Board(int h,int w){};
	std::string CheckOwner(int X,int Y){};
private:
	int height;
	int width;
	std::vector<std::vector<Piece> > GameBoard;
};