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
}

void Piece::getMoves(vector<Point> &points, const int boardSize){

	// TODO  Á EFTIR AÐ KLÁRA

	Point p;
	p = getPostion();
	int count = 0;
	

	if((p.m_x + m_moveDir.E) <= boardSize)
	{
		for(int i = p.m_x; i < (p.m_x + m_moveDir.E); i++)
		{
			points.push_back(Point(i, p.m_y));
			/*
			points[count]->m_x = i;
			points[count]->m_y = p.m_y;
			*/count++;
		}
	}

	if((p.m_x - m_moveDir.E) >= 0)
	{
		for(int i = p.m_x; i > (p.m_x - m_moveDir.W); i--)
		{
			points.push_back(Point(i, p.m_y));
			/*
			points[count]->m_x = i;
			points[count]->m_y = p.m_y;
			count++;*/
		}
	}

	if((p.m_y + m_moveDir.N) <= boardSize)
	{
		for(int i = p.m_y; i < (p.m_y + m_moveDir.E); i++)
		{
			points.push_back(Point(p.m_x, i));
			/*
			points[count]->m_x = p.m_x;
			points[count]->m_y = i;
			count++;*/
		}
	}

	if((p.m_y - m_moveDir.S) >= 0)
	{
		for(int i = p.m_y; i > (p.m_y - m_moveDir.S); i--)
		{
			points.push_back(Point(p.m_x, i));
			/*
			points[count]->m_x = p.m_x;
			points[count]->m_y = i;
			count++;
			*/
		}
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


