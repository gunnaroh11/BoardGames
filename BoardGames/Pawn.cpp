#include "Pawn.h"

using namespace std;

Pawn::Pawn()
{
}
void Pawn::getMoves(vector<Point> &points, const int boardSize)
{

	Point temp = getPostion();
	//if player = 0
	if(getPlayer()== 0)
	{
		//if left end
		if(temp.m_x == 0)
		{
			points.push_back(Point(temp.m_x,temp.m_y+1));
			points.push_back(Point(temp.m_x+1,temp.m_y+1));
		}
		//if Right end
		else if(temp.m_x == boardSize)
		{
			points.push_back(Point(temp.m_x,temp.m_y+1));
			points.push_back(Point(temp.m_x-1,temp.m_y+1));
		}
		else
		{
			points.push_back(Point(temp.m_x,temp.m_y+1));
			points.push_back(Point(temp.m_x-1,temp.m_y+1));
			points.push_back(Point(temp.m_x+1,temp.m_y+1));
		}
	}
	else
	{
	///if player = 1
		//if left end
		if(temp.m_x == 0)
		{
			points.push_back(Point(temp.m_x,temp.m_y-1));
			points.push_back(Point(temp.m_x+1,temp.m_y-1));
		}
		//if Right end
		else if(temp.m_x == boardSize)
		{
			points.push_back(Point(temp.m_x,temp.m_y-1));
			points.push_back(Point(temp.m_x-1,temp.m_y-1));
		}
		else
		{
			points.push_back(Point(temp.m_x,temp.m_y-1));
			points.push_back(Point(temp.m_x-1,temp.m_y-1));
			points.push_back(Point(temp.m_x+1,temp.m_y-1));
		}
	}
};