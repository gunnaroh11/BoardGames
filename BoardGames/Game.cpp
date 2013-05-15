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

	}
	void Game::make(int FromX,int FromY,int ToX,int ToY)
	{

		//check if the piece at fromX,fromY belongs to current player
		//evaluate if move is leagal
		//if(evaluate(fromX,fromY,toX,toY){
		//exchange GameBoard[FromX,FromY] with GameBoard[ToX,ToY]
		if(CurrentPlayer == 1)
		{
			CurrentPlayer = 2;
		}
		else
		{
			CurrentPlayer = 1;
		}
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
		for(int i = 0;i<height;i++)
		{
			for(int j = 0;j<with;j++)
			{
				//std::cout<<GameBoard[i][j] << "
			}
			std::cout<<std::endl;
		}
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
		GameName = "TestGame";
			Debug = false;
		difficulty = 0;
		MaxPlays = 10;
		CurrentTurn = 0;
		CurrentPlayer = 1;
		GameBoard.SetSize(5,5);
		GameBoard.GameBoard[3][1].setPlayer(1);
		GameBoard.GameBoard[1][1].setPlayer(2);
		GameBoard.GenerateBoard();
	
	}
	

