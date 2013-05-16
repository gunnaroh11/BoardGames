#include "Game.h"
#include "TestGame.cpp"
#include <iostream>
#include <string>

using namespace std;

const string DIFF_EASY = "easy";
const string DIFF_MID = "medium";
const string DIFF_HARD = "hard";

void printGameEngineCommands()
{
	cout << "\n - Command \"list\" : Prints out avalible games"; 
	cout << "\n - Command \"game\" <number> : Write fx \"game 1\" to select game no 1"; 
	cout << "\n - Command \"start\" : To start selected game"; 
	cout << "\n - Command \"debug\" : Toggle debug mode on and off"; 
	cout << "\n - Command \"quit\" : Exit program\n\n"; 	
}

void printGameCommands()
{
	system("cls");
	cout << "\n - Command \"make\" <number> <number> <number> <number> : make from_col from_row to_col to_row"; 
	cout << "\n - Command \"retract\" : Retracts last move played"; 
	cout << "\n - Command \"display\" : Display the current game state\n";
		cout << "\t \".\" = Empty\n" ; 
		cout << "\t \"*\" = Not legal\n" ;
		cout << "\t \"P\" = Player 1\n" ;
		cout << "\t \"p\" = Player 2\n" ;
	cout << "\n - Command \"evaluate\" : Display the evaluation value of the current board state, depending on difficulty level."; 
	cout << "\n - Command \"go\" : The computer plays for the side to move and outputs the move it makes"; 
	cout << "\n - Command \"level\" [ random | easy | medium | hard ] : Play level"; 
	cout << "\n - Command \"debug\" : Toggle debug mode on and off"; 
	cout << "\n - Command \"quit\" : Exit program\n\n"; 	
}


void list(vector<Game> G)
{
	for(int i = 0;i< (int)G.size();i++)
	{
		cout << i << ". " << G[i].GetName() << endl;
	}
};

Game game(int n,vector<Game> G)
{
	return G[n];
}

int inGameMode(Game &playGame){
	string gameWord;
	
	int from_col, from_row, to_col, to_row;	
	printGameCommands();
	while(!playGame.m_finished)
	{
		
	cin>> gameWord;
		if(gameWord == "make")
		{	
			cout<< "type the possition of the piece you want to move and where you want to move it" << endl;
			cin >> from_col;
			cin >> from_row;
			cin >> to_col;
			cin >> to_row;
			// TODO make move
			playGame.make(from_col,from_row,to_col,to_row);
		}

		if(gameWord == "retract")
		{
			playGame.retract();
			// TODO - Retract last move
		}

		if(gameWord == "display")
		{
			int height = playGame.GameBoard.getHeight();
			int width = playGame.GameBoard.getWidth();
			playGame.display(height,width);
			/*
			for(int i = 0; i < height; i++)
			{
				for(int j = 0; j < width; j++)
				{
					playGame.GameBoard.GameBoard[i][j].print();
				}
			}
			*/
		
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

		if(gameWord == "debug")
		{
			playGame.debug();
		}

		if(gameWord == "quit")
		{
			exit(0);
		}


	}

	return 0; // � a� skila gildi fyrir winner e�a draw
}

int main()
{
vector<Game> Games;
string word;
int nr = -1;
bool debug = false;

Game t;
t.GetTestGame();
Games.push_back(t); // � a� vera new test game... e�a e-�

cout << "type list to get a list of all supported games" << endl;
cout << "type game to pick game to play" << endl;

	while(true)
	{		
		printGameEngineCommands();
		cin >> word;	
		system("cls");
		if(word == "list")
		{				
			if(!Games.empty())
				list(Games);
			else
				cout << "No games avalible" << endl;
		}

		if(word == "game")
		{
			bool check = true;
			while(check)
			{
				cout << "pick the number of the game you want to play" << endl;
				cin>>nr;

				if(nr < 0 || nr > (int)Games.size()-1)
				{
					system("cls");
					cout << "Game not avalible. Please try again, select avalible game number.\n";										
				}
				else
				{
					check = false;
				}
			}
		}

		if(word == "start")
		{
			Game ChosenGame = game(nr,Games);			
			//	ChosenGame.Debug = debug;

			ChosenGame.start();
			nr = -1;

			inGameMode(ChosenGame);
			
		}

		if(word == "debug")
		{
			if(debug == true)
				debug = false;
			if(debug == false)
				debug = true;
		}

		if(word == "quit")
		{
			exit(0);
		}

		


		cout << "type list to get a list of all supported games" << endl;
		cout << "type game to pick game to play" << endl;
}
}