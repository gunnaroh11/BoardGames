#include "Game.cpp"
#include "TestGame.h"
#include <iostream>
#include <string>

using namespace std;

void list(vector<Game> G)
{
	for(int i = 0;i< (int)G.size();i++)
	{
		cout << i << ". " << G[i].GetName();
	}
};

Game game(int n,vector<Game> G)
{
	return G[n];
}

int inGameMode(Game &playGame){
	string gameWord;
	int from_col, from_row, to_col, to_row;
	
	while(!playGame.m_finished)
	{
		if(gameWord == "make")
		{			
			cin >> from_col;
			cin >> from_row;
			cin >> to_col;
			cin >> to_row;
			// TODO make move
		}

		if(gameWord == "retract")
		{
			// TODO - Retract last move
		}

		if(gameWord == "display")
		{
			// TODO - Display board
		}
	}

	return 0; // � a� skila gildi fyrir winner e�a draw
}

int main()
{
vector<Game> Games;
string word;
int nr = -1;

//Games.push_back(new Game()); // � a� vera new test game... e�a e-�

cout << "type list to get a list of all supported games" << endl;
cout << "type game to pick game to play" << endl;

	while(true)
	{

		cin >> word;	

		if(word == "list")
		{				
			if(!Games.empty())
				list(Games);
			else
				cout << "No games avalible" << endl;
		}

		if(word == "game")
		{
			cout << "pick the number of the game you want to play"<<endl;
			
			cin>>nr;			
		}

		if(word == "start")
		{
			Game ChosenGame = game(nr,Games);
			ChosenGame.start();
			nr = -1;

			inGameMode(ChosenGame);
			
		}

		


		cout << "type list to get a list of all supported games" << endl;
		cout << "type game to pick game to play" << endl;
}
}