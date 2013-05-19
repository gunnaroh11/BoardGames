#include "Pieces.h"
#include <iostream>

using namespace std;
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

	m_moveDir.N = dirN;
	m_moveDir.E = dirE;
	m_moveDir.S = dirS;
	m_moveDir.W = dirW;
	
}

void Piece::getMoves(vector<Point> &points, const int boardSize){

	// TODO  Á EFTIR AÐ KLÁRA

	Point p;
	p = getPostion();
	int count = 0;
	
	points.clear();

	// move right
	if(p.m_x < boardSize)	// ef x + E minni en mörk
	{
		count = 0;
		for(int i = p.m_x; i < (p.m_x + m_moveDir.E); i++)
		{
			count++;
			points.push_back(Point(p.m_x + count, p.m_y)); // x + 1, y = y => einn til hægri
			
			if(p.m_y < boardSize)
			{
				points.push_back(Point(p.m_x + count, p.m_y+ count)); // x + 1, y + 1 => ská upp til hægri
			}			
		}
	}

	// move left
	if(p.m_x > 0) // ef x - W stærra en 0
	{
		count = 0;
		for(int i = p.m_x; i > (p.m_x - m_moveDir.W); i--)
		{
			count++;
			points.push_back(Point(p.m_x - count, p.m_y));	// x - 1, y = y => einn til vinstri

			if((p.m_y - count) <= boardSize)
			{
				points.push_back(Point(p.m_x - count, p.m_y - count)); // x-1, y-1 => ská niður til vinstri
			}
		}
	}

	if(p.m_y < boardSize) // upp - ef y minna en boardSize
	{
		count = 0;
		for(int i = p.m_y; i < (p.m_y + m_moveDir.E); i++)
		{
			count++;
			if((p.m_y + count) <= boardSize)
			{
				points.push_back(Point(p.m_x, p.m_y+count));	// x = x, y+1 => Upp
			}

			if((p.m_x-count) >= 0) // > boardsize
			{
				points.push_back(Point(p.m_x - count, p.m_y+ count)); // x-1, y+1 => ská upp vinstrir
			}			
		}
	}

	if(p.m_y > 0)
	{
		count = 0;
		for(int i = p.m_y; i > (p.m_y - m_moveDir.S); i--)
		{
			count++;
			points.push_back(Point(p.m_x, p.m_y - count));		// x=x, y-1 => Niður

			if((p.m_x+count <= boardSize) && (p.m_y-count >=0))
			{
				points.push_back(Point(p.m_x + count, p.m_y- count)); // x+1, y-1 => ská niður hægri
			}			
		}
	}

	
}

// Set position for piece
void Piece::setPosition(int x, int y){
	m_position.m_x = x;
	m_position.m_y = y;
}

// Set position for piece
void Piece::setPosition(Point p){
	m_position = p;
}

//Returns current position for piece
Point Piece::getPostion(){
	return m_position;
}

void Piece::print()
{
	if(m_playerNumber == 0)
		cout << 'P';
	if(m_playerNumber == 1)
		cout << 'p';
	if(m_playerNumber == 2) // empty slot
		cout << '.';
	if(m_playerNumber == 4) // á eftir að implimenta löglega reiti
		cout << '*';
}

MoveDir Piece::getMovDir(){
	m_moveDir.N = m_directionN;
	m_moveDir.E = m_directionE;
	m_moveDir.S = m_directionS;
	m_moveDir.W = m_directionW;

	return m_moveDir; 
}

//Indicates if selected piece has moved from starting position
bool Piece::getHasMoved(){
	return m_hasMoved;
}

//Returns wich player this piece belongs to
int Piece::getPlayer(){
	return m_playerNumber;
}

void Piece::setPlayer(int p)
{
	m_playerNumber = p;	
}

//Returns what type selected piece is, if relevant
char* Piece::getType(){
	return m_type;
}


