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
	void Game::make(int FromX,int FromY,int ToX,int ToY)
	{
		if(GameBoard.GameBoard[FromX][FromY].getPlayer() == CurrentPlayer)
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
			display(5,5);
		}
		else
		{
			cout<< "that piece does not belong to the current player "<< endl;
		}
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
		GameBoard.Revert(history[CurrentTurn]);
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
		MaxPlays = 10;
		CurrentTurn = 0;
		CurrentPlayer = 1;
		GameBoard.SetSize(5,5);
		GameBoard.GameBoard[3][1].setPlayer(0);
		GameBoard.GameBoard[3][1].setMoves(1,1,1,1);
		GameBoard.GameBoard[1][1].setPlayer(1);
		GameBoard.GameBoard[1][1].setMoves(1,1,1,1);
		GameBoard.GenerateBoard();
		
	
	}
	

