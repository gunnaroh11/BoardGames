#include <iostream>
#include <vector>
#include <string>
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
	void start()
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
		//board = history[CurrentTurn]
		}
	}
	virtual void display(int height,int with)
	{
		for(int i = 0;i<height;i++)
		{
			for(int j = 0;j<with;j++)
			{
				/*
				if(GameBoard[i,j].player == 1)
				{
					cout<<"P";
				}
				else if(GameBoard[i,j].player == 2)
				{
					cout<<"p";
				}
				else
				{
				cout<<"0";
				}
				*/
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
	void debug()
	{
		if(debug == true)
		{
			debug= false;
		}
		else
		{
			debug = true;
		}
	}
	void quit(){}
		

private:
	bool debug;
	int difficulty;
	//Board GameBoard
	//vector<Board*> history
	int MaxPlays;
	int CurrentTurn;
	int CurrentPlayer;

}