#include "Breakthrough.h"

using namespace std;
Breaktrough::Breaktrough()
{		
}

void Breaktrough::legal(vector<Point> &legalMoves, Piece &piece){
	
	vector<Point> moves;
	Point currentPoint = piece.getPostion();
	piece.getMoves(moves, GameBoard.getHeight());
	legalMoves.clear();

	if(CurrentPlayer == 0)
	{	
		if(Debug)
		{
			cout << endl << "Selected Player - Player One - Get all moves for piece and clear vector lecalMoves" << endl;
			for(int i = 0; i<(int)moves.size();i++)
			{
				cout << "1: ";  
				moves[i].print();				
			}
		}

		for(int i = 0; i < (int)moves.size();i++)
		{
			//upright		
			if(Point(currentPoint.m_x+1, currentPoint.m_y+1) == moves[i])
			{
				if(Debug)
				{
					cout << "Point found in moves, push_back to legalMoves" << endl;
					moves[i].print();
				}
				legalMoves.push_back(Point(currentPoint.m_x+1, currentPoint.m_y+1)); 
			}

			//up		
			if(Point(currentPoint.m_x, currentPoint.m_y+1) == moves[i])
			{
				if(Debug)
				{
					cout << "Point found in moves, push_back to legalMoves" << endl;
					moves[i].print();
				}
				legalMoves.push_back(Point(currentPoint.m_x, currentPoint.m_y+1)); 
			}

			//upleft
			if(Point(currentPoint.m_x-1, currentPoint.m_y+1) == moves[i])
			{
				if(Debug)
				{
					cout << "Point found in moves, push_back to legalMoves" << endl;
					moves[i].print();
				}
				legalMoves.push_back(Point(currentPoint.m_x-1, currentPoint.m_y+1)); 
			}
		}
	}
	else
	{
		if(Debug)
		{
			cout << endl << "Selected Player - Player One - Get all moves for piece and clear vector lecalMoves" << endl;
			for(int i = 0; i<(int)moves.size();i++)
			{
				cout << "1: ";  
				moves[i].print();				
			}
		}

		for(int i = 0; i < (int)moves.size();i++)
		{
			//downleft		
			if(Point(currentPoint.m_x-1, currentPoint.m_y-1) == moves[i])
			{
				if(Debug)
				{
					cout << "Point found in moves, push_back to legalMoves" << endl;
					moves[i].print();
				}
				legalMoves.push_back(Point(currentPoint.m_x-1, currentPoint.m_y-1)); 
			}

			//down
			if(Point(currentPoint.m_x, currentPoint.m_y-1) == moves[i])
			{
				if(Debug)
				{
					cout << "Point found in moves, push_back to legalMoves" << endl;
					moves[i].print();
				}
				legalMoves.push_back(Point(currentPoint.m_x, currentPoint.m_y-1)); 
			}

			//downright
			if(Point(currentPoint.m_x+1, currentPoint.m_y-1) == moves[i])
			{
				if(Debug)
				{
					cout << "Point found in moves, push_back to legalMoves" << endl;
					moves[i].print();
				}
				legalMoves.push_back(Point(currentPoint.m_x+1, currentPoint.m_y-1)); 
			}
		}
	}
}


void Breaktrough::start()
{
	GameName = "Breakthrough";
	m_finished = false;
		Debug = false;
		difficulty = 0;
		GameBoard.SetSize(7,7);
		player1_pieces = GameBoard.getWidth()*2;
		player2_pieces = GameBoard.getWidth()*2;
		MaxPlays = 100;
		CurrentTurn = 0;
		CurrentPlayer = 0;
		
		setMoveForPlayer(0);
		setMoveForPlayer(1);
	cout << "size of board is " << GameBoard.getHeight() << ":" << GameBoard.getWidth() << endl;
	//display(7,7);
	//	GameBoard.GenerateBoard();
		history.push_back(GameBoard);
}
void Breaktrough::setMoveForPlayer(int P)
{
	if(P == 0)
	{
		for(int i = 0; i<GameBoard.getWidth();i++)
		{
			for(int j= 0;j<2;j++)
			{

				GameBoard.GameBoard[i][j].setPlayer(0);
				GameBoard.GameBoard[i][j].setMoves(1,1,1,1);
			}
		}
	}
	else
	{
		for(int i = 0; i<GameBoard.getWidth();i++)
		{
			for(int j= GameBoard.getHeight()-2;j<GameBoard.getWidth();j++)
			{

				GameBoard.GameBoard[i][j].setPlayer(1);
				GameBoard.GameBoard[i][j].setMoves(1,1,1,1);
			}
		}
	}
}

void Breaktrough::SwapTiles(Point From,Point To,int player)
{
	Piece temp = Piece("0",2,From);
	GameBoard.GameBoard[To.m_x][To.m_y]=GameBoard.GameBoard[From.m_x][From.m_y];
	GameBoard.GameBoard[From.m_x][From.m_y] = temp; 
						GameBoard.GameBoard[To.m_x][To.m_y].setPosition(To);
						
	if(player == 0)
	{
		player1_pieces--;
	}
	else if(player == 1)
	{
		player2_pieces--;
	}
}


void Breaktrough::make(int FromX,int FromY,int ToX,int ToY)
{
	vector<Point> vect;
	vect.clear();
	legal(vect,GameBoard.GameBoard[FromX][FromY]);

	
	if(GameBoard.GameBoard[FromX][FromY].getPlayer() == CurrentPlayer)
		{
			
			
		vector<Point> vect;
	legal(vect,GameBoard.GameBoard[FromX][FromY]);
	if(Debug)
	{
		cout << endl << "Legal moves: " << endl;
		for(int i=0;i <(int)vect.size();i++)
		{
			vect[i].print();
		}
	}

			//if piece on the destination spot belongs to the other player
			if((GameBoard.GameBoard[ToX][ToY].getPlayer() != CurrentPlayer)&&(GameBoard.GameBoard[ToX][ToY].getPlayer() != 2))
			{
				//left end
				if(FromX == 0)
				{
					if(Point(ToX,ToY)==vect[1])
					{
						SwapTiles(Point(FromX,FromY),Point(ToX,ToY),GameBoard.GameBoard[ToX][ToY].getPlayer());
						checkFinished();

					}
					else
					{
						cout << "Pawns can not capture in a strieght line" << endl;
					}
				}
				//right end
				else if(FromX == GameBoard.getWidth())
				{
					if(Point(ToX,ToY)==vect[0])
					{
				SwapTiles(Point(FromX,FromY),Point(ToX,ToY),GameBoard.GameBoard[ToX][ToY].getPlayer());
						checkFinished();
					}
					else
					{
						cout << "Pawns can not capture in a strieght line" << endl;
					}
				}
				//middle
				else
				{
					if((Point(ToX,ToY)==vect[0])||(Point(ToX,ToY)==vect[2]))
					{
							SwapTiles(Point(FromX,FromY),Point(ToX,ToY),GameBoard.GameBoard[ToX][ToY].getPlayer());
						checkFinished();
					}
					else
					{
						cout << "Pawns can not capture in a strieght line" << endl;
					}
				}
				
				
				
			
				if(CurrentPlayer == 0)
				{
					CurrentPlayer = 1;
				}	
				else
				{
					
					CurrentPlayer = 0;
				}
				CurrentTurn++;
				history.push_back(GameBoard);
				checkFinished();

			}
			else if(GameBoard.GameBoard[ToX][ToY].getPlayer() == CurrentPlayer)
			{
				cout << "cant move there a piece belonging to you already ocupies the tile" << endl;
			}
			else
			{
				bool islegal = false;
				for(unsigned int i = 0;i<vect.size();i++)
				{
					if(Point(ToX,ToY)==vect[i])
					{
						islegal = true;
						
						SwapTiles(Point(FromX,FromY),Point(ToX,ToY),GameBoard.GameBoard[ToX][ToY].getPlayer());
						
						if(CurrentPlayer == 0)
						{
							CurrentPlayer = 1;
						}	
						else
						{
							CurrentPlayer = 0;
						}
						CurrentTurn++;
						history.push_back(GameBoard);
						checkFinished();
					}
				}
				if(islegal == false)
				{
					cout<<"illegal Move" << endl;
				}
			}
			
		}
		else
		{
			cout<< "that piece does not belong to the current player "<< endl;
		}
		display();
				
}

void Breaktrough::checkFinished()
{
	if(player1_pieces == 0)
		{
			cout << "Player 0 wins he did it in "<< CurrentTurn << " turns " <<endl;
			m_finished = true;
		}
		else if(player2_pieces == 0)
		{
			cout << "Player 1 wins he did it in "<< CurrentTurn << " turns " <<endl;
			m_finished = true;
		}
		else
		{
			for(int i = 0;i<GameBoard.getHeight();i++)
			{
				if(GameBoard.GameBoard[i][0].getPlayer() == 1)
				{
					cout << "Player 1 wins he did it in "<< CurrentTurn << " turns " <<endl;
					m_finished = true;
				}
			}
			for(int i = 0;i<GameBoard.getHeight();i++)
			{
				if(GameBoard.GameBoard[i][GameBoard.getHeight()-1].getPlayer() == 0)
				{
					cout << "Player 0 wins he did it in "<< CurrentTurn << " turns " <<endl;
					m_finished = true;
				}
			}
		}
}