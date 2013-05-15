#include "Game.h"
#include "TestGame.h"
#include <iostream>
#include <string>

using namespace std;

const string DIFF_EASY = "easy";
const string DIFF_MID = "medium";
const string DIFF_HARD = "hard";


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

		if(gameWord == "evaluate")
		{
			// TODO - Display evaluation value of current board state
		}

		if(gameWord == "go")
		{
			// Computer plays using current difficulty lvl
		}

		if(gameWord == "level")
		{
			cout << "ble";
		}


	}

	return 0; // á að skila gildi fyrir winner eða draw
}

int main()
{
vector<Game> Games;
string word;
int nr = -1;

//Games.push_back(new Game()); // á að vera new test game... eða e-ð

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