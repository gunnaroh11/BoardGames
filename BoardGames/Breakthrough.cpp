#include "Breakthrough.h"
using namespace std;
Breaktrough::Breaktrough()
{
	GameName = "Breakthogh";
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
		//setMoveForPlayer(1);
		
}

void Breaktrough::start()
{
	cout << "size of board is " << GameBoard.getHeight() << ":" << GameBoard.getWidth() << endl;
	display(7,7);
	//	GameBoard.GenerateBoard();
		history.push_back(GameBoard);
}
void Breaktrough::setMoveForPlayer(int P)
{
	if(P == 0)
	{
		for(int i = 0; i<2;i++)
		{
			for(int j= 0;j<GameBoard.getWidth()-2;j++)
			{

				GameBoard.GameBoard[i][j].setPlayer(0);
				//GameBoard.GameBoard[i][j].setMoves(1,1,1,1);
			}
		}
	}
	else
	{
	}
}

void Breaktrough::make(int FromX,int FromY,int ToX,int ToY)
{
	if(GameBoard.GameBoard[FromX][FromY].getPlayer() == CurrentPlayer)
		{
			int *i= new int();
			*i = player1_pieces;
			if(CurrentPlayer == 1)
			{
				*i = player2_pieces;
			}
			
			vector<Point> vect;
			GameBoard.GameBoard[2][1].getMoves(vect, 5);
			//if piece on the destination spot belongs to the other player
			if((GameBoard.GameBoard[ToX][ToY].getPlayer() != CurrentPlayer)&&(GameBoard.GameBoard[ToX][ToY].getPlayer() != CurrentPlayer))
			{
				//left end
				if(FromX == 0)
				{
					if(Point(ToX,ToY)==vect[1])
					{
						Piece temp = Piece("0",2,Point(FromX,FromY));
						GameBoard.GameBoard[ToX][ToY]=GameBoard.GameBoard[FromX][FromY];
						GameBoard.GameBoard[FromX][FromY] = temp; 
						i--;
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
						Piece temp = Piece("0",2,Point(FromX,FromY));
						GameBoard.GameBoard[ToX][ToY]=GameBoard.GameBoard[FromX][FromY];
						GameBoard.GameBoard[FromX][FromY] = temp; 
						i--;
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
						Piece temp = Piece("0",2,Point(FromX,FromY));
						GameBoard.GameBoard[ToX][ToY]=GameBoard.GameBoard[FromX][FromY];
						GameBoard.GameBoard[FromX][FromY] = temp; 
						i--;
					}
					else
					{
						cout << "Pawns can not capture in a strieght line" << endl;
					}
				}
				
				
				
			
				if(CurrentPlayer == 0)
				{
					player2_pieces--;
					CurrentPlayer = 1;
				}	
				else
				{
					player1_pieces--;
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
						Piece temp = GameBoard.GameBoard[ToX][ToY];
						GameBoard.GameBoard[ToX][ToY]=GameBoard.GameBoard[FromX][FromY];
						GameBoard.GameBoard[FromX][FromY] = temp; 
			
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
		display(5,5);
		//check if the piece at fromX,fromY belongs to current player
		//evaluate if move is leagal
		//if(evaluate(fromX,fromY,toX,toY){
		//exchange GameBoard[FromX,FromY] with GameBoard[ToX,ToY]
				//else{cout<<"illegal Move"<<end;}
}