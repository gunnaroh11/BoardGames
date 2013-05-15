#include "Game.cpp"
#include <iostream>
#include <string>
using namespace std;

void list(vector<Game> G)
{
	for(int i = 0;i<G.size();i++)
	{
	//cout lists
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
while(	cin>>word)
	if(word == "list")
	{
		list(Games);
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