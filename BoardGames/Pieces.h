#ifndef PIECES_H
#define PIECES_H
#include <vector>
#include <iostream>
struct Point{
public:
	int m_x;
	int m_y;

	Point(){};
	Point(int x, int y):m_x(x), m_y(y){};
	
	void setEmpty(){
		m_x = 0;
		m_y = 0;
	};

	void print(){
		std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
	};

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
};

struct MoveDir{
public:
	int N, E, S, W;
};

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