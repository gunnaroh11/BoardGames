#ifndef PIECES_H
#define PIECES_H
#include <vector>
#include <iostream>

/*! \brief Brief description.
 *         struct Point simple struct for cords, implements comparision between Point instances and assigning values
 */

struct Point{
public:
	int m_x;	//!< x value for cord
	int m_y;	//!< y value for cord

	Point(){};
	//!< default constructor

	//! Constructor that takes cors as parameter and sets values
	/*!
		\param x X value for cord
		\param y Y value for cord
	*/
	Point(int x, int y):m_x(x), m_y(y){};
	
	
	void setEmpty(){
		m_x = 0;
		m_y = 0;
	};
	//!< Sets cord x and y values to 0

	void print(){
		std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
	};
	//!< prints out cordination as "(x, y)" 

	friend bool operator==(Point &lhs, Point &rhs)
	{
		if(lhs.m_x == rhs.m_x)
		{
			if(lhs.m_y == rhs.m_y)
			{
				return true;
			}
		}
		return false;
	};
	void operator=(const Point &rhs)
	{

	    m_x = rhs.m_x;
		m_y = rhs.m_y;
		
	};
};

/*! \brief Brief description.
 *         Simple struct that indicats how far a piece can move each turn for each direction
 */
struct MoveDir{
public:
	int N, E, S, W;
};

/*! \brief Brief description.
 *         Class Piece is a default piece class that can be derived from. And can have different settings and behavior
 */
class Piece{

public:
	Piece();
	Piece(char *type, int playerNumber, Point position);
	
	virtual void move(Point p);
	virtual void setPlayer(int p);
	virtual void setMoves(int dirN, int dirE, int dirS, int dirW);
	virtual void getMoves(std::vector<Point> &points, const int boardSize);
	
	void setPosition(int x, int y);
	void setPosition(Point p);
	void print();
	Point getPostion();
	MoveDir getMovDir();
	
	bool getHasMoved();
	int getPlayer();
	char* getType();
	
protected:
	
private:
	char *m_type;
	int m_playerNumber;
	bool m_hasMoved;
	int m_directionN, m_directionE, m_directionS, m_directionW;
	Point m_position;
	MoveDir m_moveDir;
};

#endif