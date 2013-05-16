#include "Game.h"
using namespace std;

	Game::Game()
	{
	}
	void legal()
	{
		//foreach piece on board get leagal moves

	}
	void Game::start()
	{

	cout << "blarg start is not possible"<< endl;
	
	//GameBoard.GenerateBoard();
	//make(1,1,2,1);
	//make(3,1,2,1);
//	GameBoard.GenerateBoard();
	}

	// check if piece can move to provided cords
	bool Game::canMake(Piece *piece, Point p)
	{
		vector<Point> points;
		piece->getMoves(points, GameBoard.getHeight());

		for(int i = 0; i < (int)points.size(); i++)
		{
			if(points[i] == p)
			{
				return true;
			}
		}
		return false;
	}

	void Game::make(int FromX,int FromY,int ToX,int ToY)
	{
		if(GameBoard.GameBoard[FromX][FromY].getPlayer() == CurrentPlayer)
		{
			//if piece on the destination spot belongs to the other player
			if((GameBoard.GameBoard[ToX][ToY].getPlayer() != CurrentPlayer)&&(GameBoard.GameBoard[ToX][ToY].getPlayer() != CurrentPlayer))
			{
				Piece temp = Piece("0",2,Point(FromX,FromY));
				GameBoard.GameBoard[ToX][ToY]=GameBoard.GameBoard[FromX][FromY];
				GameBoard.GameBoard[FromX][FromY] = temp; 
			
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
	void Game::go()
	{
		
	}
	void Game::retract()
	{
		if(CurrentTurn != 0)
		{
		CurrentTurn-=1;
		GameBoard = history[CurrentTurn];
		//GameBoard.Revert(history[CurrentTurn]);
		display(5,5);
		}
		else
		{
			cout << " this is the begining state you can not retract past the begining state"<< endl;
		}
	}
	void Game::display(int height,int with)
	{
		cout << "current player is "<< CurrentPlayer << " and turn is " << CurrentTurn << "off "<<MaxPlays <<" turns "<< endl;
		GameBoard.GenerateBoard();
	}
	void Game::evaluate()
		{
			//to be implemented;
		}
	void Game::level(string difficulty)
	{
		//easy
		//medium
		//hard
		//random
	}
	void Game::debug()
	{
		if(Debug == true)
		{
			Debug= false;
		}
		else
		{
			Debug = true;
		}
	}
	void Game::quit(){}
	string Game::GetName()
	{
		return GameName;
	}

	void Game::setDifficulty(int diff){
		difficulty = diff;
	}

	int Game::getDifficulty(){
		return difficulty;
	}
	void Game::GetTestGame()
	{
		m_finished = false;
		GameName = "TestGame";
			Debug = false;
		difficulty = 0;
		player1_pieces = 0;
		player2_pieces = 0;
		MaxPlays = 10;
		CurrentTurn = 0;
		CurrentPlayer = 0;
		GameBoard.SetSize(5,5);
		GameBoard.GameBoard[3][1].setPlayer(0);
		player1_pieces++;
		GameBoard.GameBoard[2][1].setPlayer(0);
		player1_pieces++;
		
		GameBoard.GameBoard[3][1].setMoves(1,1,1,1);
		GameBoard.GameBoard[2][1].setMoves(1,1,1,1);
		GameBoard.GameBoard[1][1].setPlayer(1);
		player2_pieces++;
		GameBoard.GameBoard[1][1].setMoves(1,1,1,1);
		GameBoard.GenerateBoard();
		history.push_back(GameBoard);
		
	
	}
	void Game::checkFinished()
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

		}
	}
	

