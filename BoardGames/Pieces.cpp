#include "Pieces.h"

Piece::Piece(){
	m_hasMoved = false;
}

//Piece constructor, initialize piece type, what player the piece belongs to
// and position on the gameboard.
Piece::Piece(char *type, int playerNumber, Point position){
	m_type = type;
	m_playerNumber = playerNumber;
	setPosition(position);
	m_hasMoved = false;
}

// Move piece, to be overridden
void Piece::move(Point p){};

// Set what direction piece can move and how far each direction, 0 = cant move that direction;
void Piece::setMoves(int dirN, int dirE, int dirS, int dirW){
	m_directionN = dirN;
	m_directionE = dirE;
	m_directionS = dirS;
	m_directionW = dirW;
}

void Piece::getMoves(Point *points[], const int boardSize){

	// TODO  Á EFTIR AÐ KLÁRA
	for(int i = m_position.m_x; i < boardSize; i++)
	{
		if((m_directionN + m_position.m_x) <= boardSize)
			points[i]->m_x = i;
	}
	
}

// Set position for piece
void Piece::setPosition(int x, int y){
	m_position.m_x = x;
	m_position.m_y;
}

// Set position for piece
void Piece::setPosition(Point p){
	m_position = p;
}

//Returns current position for piece
Point Piece::getPostion(){
	return m_position;
}

//Indicates if selected piece has moved from starting position
bool Piece::getHasMoved(){
	return m_hasMoved;
}

//Returns wich player this piece belongs to
int Piece::getPlayer(){
	return m_playerNumber;
}

//Returns what type selected piece is, if relevant
char* Piece::getType(){
	return m_type;
}



Point Piece::getMoves(){}

