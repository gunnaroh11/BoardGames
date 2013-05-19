#include "Game.h"
using namespace std;

	Game::Game()
	{
	}
	void Game::legal(vector<Point> &legalMoves, Piece &piece)
	{
		//foreach piece on board get leagal moves
	vector<Point> moves;
	Point currentPoint = piece.getPostion();
	piece.getMoves(moves, GameBoard.getHeight());
	legalMoves.clear();

	for(Point P : moves)
	{
		legalMoves.push_back(P);
	}

	}
	void Game::start()
	{

		cout << "blarg start is not possible"<< endl;
	
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
				if(Debug)
				{
					cout << "canMake(Piece *piece, Point p) => returns true" << endl
						<< "player can make this move" << endl;
				}
				return true;
			}

			if(Debug)
				{
					cout << "canMake(Piece *piece, Point p) => getMoves() can not make move to \n (" 
						<< points[i].m_x << "," << points[i].m_y << ")" << endl;
				}
		}
		if(Debug)
		{
			cout << "canMake(Piece *piece, Point p) => returns false" << endl
				<< "player can NOT make this move" << endl;
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
		display();
		//check if the piece at fromX,fromY belongs to current player
		//evaluate if move is leagal
		//if(evaluate(fromX,fromY,toX,toY){
		//exchange GameBoard[FromX,FromY] with GameBoard[ToX,ToY]
				//else{cout<<"illegal Move"<<end;}
	}
	 PlayedGames Game::go(Board B,int player,int deapth)
	{
		

		//if difficulty 
		int Maxdeapth = 1;
		int nextPlayer;
		vector<PlayedGames> Moves;
		if(player == 0)
		{
			nextPlayer = 1;
		}
		else if(player == 1)
		{
			nextPlayer = 0;
		}
		Moves.clear();
		PlayerLegal(Moves,player);
		PlayedGames bestGame(Moves[0].From,Moves[0].To,Moves[0].score);
		if(deapth != Maxdeapth)
		{
			for(PlayedGames PG : Moves)
			{
				PlayedGames testMove =	go(GameBoard,nextPlayer,deapth+1);
				if(testMove.score > bestGame.score)
				{
					bestGame.From = testMove.From;
					bestGame.To = testMove.To;
					bestGame.score = testMove.score;
				}
			}
		}
		else
		{
			for(PlayedGames PG : Moves)
			{
				
				if(PG.score > bestGame.score)
				{
					bestGame.From = PG.From;
					bestGame.To = PG.To;
					bestGame.score = PG.score;
				}
			}
		}
		
	}
	
	void Game::PlayerLegal(vector<PlayedGames> &Moves,int player)
	{
		for(int i = 0;i< GameBoard.getHeight();i++)
		{
			for(int j = 0;j< GameBoard.getHeight();j++)
				{
					vector<Point> vect;
					vect.clear();
	
					if(GameBoard.GameBoard[i][j].getPlayer() == player)
					{
						legal(vect,GameBoard.GameBoard[i][j]);
						for(Point M : vect)
						{
							make(i,j,M.m_x,M.m_y);
							int score = evaluate(GameBoard,player);
							Moves.push_back(PlayedGames(Point(i,j),Point(M.m_x,M.m_y),score));
							retract();
						}
					}
					
				}
		}
	}

	void Game::retract()
	{
		if(CurrentTurn != 0)
		{
		CurrentTurn-=1;
		GameBoard = history[CurrentTurn];
		//GameBoard.Revert(history[CurrentTurn]);
		display();
		}
		else
		{
			cout << " this is the begining state you can not retract past the begining state"<< endl;
		}
	}
	void Game::display()
	{
		cout << "current player is "<< CurrentPlayer << " and turn is " << CurrentTurn << "off "<<MaxPlays <<" turns "<< endl;
		GameBoard.GenerateBoard();
		cout << "player 0 has " << player1_pieces << " left and player 1 has " <<player2_pieces << " pieces left" <<endl;
	}
	int Game::evaluate(Board B ,int player)
		{
			if(player == 0)
			{
				return player2_pieces;
			}
			else
			{
				return player1_pieces;
			}
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
		
		GameBoard.GameBoard[0][2].setMoves(1,1,1,1);
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
	

