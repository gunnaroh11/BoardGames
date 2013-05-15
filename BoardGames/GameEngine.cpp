#include "Game.cpp"
#include <iostream>
#include <string>

using namespace std;

void list(vector<Game> G)
{
	for(int i = 0;i< (int)G.size();i++)
	{
		cout << G[i].Name;
	}
};

Game game(int n,vector<Game> G)
{
	return G[n];
}




int main()
{
vector<Game> Games;
string word;

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
			int nr;
			cin>>nr;
			Game ChosenGame = game(nr,Games);
			ChosenGame.start();
		}
		cout << "type list to get a list of all supported games" << endl;
		cout << "type game to pick game to play" << endl;
}
}