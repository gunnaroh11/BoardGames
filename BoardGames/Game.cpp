#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
using namespace std;
class Game
{
public:
	
	Game()
	{
	}
	void legal()
	{
		//foreach piece on board get leagal moves

	}
	virtual void start()
	{

	}
	void make(int FromX,int FromY,int ToX,int ToY)
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
	void go()
	{

	}
	void retract()
	{
		if(CurrentTurn != 0)
		{
		CurrentTurn-=1;
		GameBoard.Revert(history[CurrentTurn]);
		}
	}
	virtual void display(int height,int with)
	{
		for(int i = 0;i<height;i++)
		{
			for(int j = 0;j<with;j++)
			{
				
				
				
			}
			std::cout<<std::endl;
		}
	}
	void evaluate()
		{
			//to be implemented;
		}
	void level(std::string difficulty)
	{
		//easy
		//medium
		//hard
		//random
	}
	bool debug()
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
	void quit(){}
	string GetName()
	{
		return GameName;
	}

protected:
	string GameName;
	bool Debug;
	int difficulty;
	Board GameBoard;
	vector<Board> history;
	int MaxPlays;
	int CurrentTurn;
	int CurrentPlayer;

};