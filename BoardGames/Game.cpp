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
		emulate = false;
	
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
			if((GameBoard.GameBoard[ToX][ToY].getPlayer() != CurrentPlayer)&&(GameBoard.GameBoard[ToX][ToY].getPlayer() != 2))
			{
				Piece temp = Piece("0",2,Point(FromX,FromY));
				GameBoard.GameBoard[ToX][ToY]=GameBoard.GameBoard[FromX][FromY];
				GameBoard.GameBoard[FromX][FromY] = temp; 
				GameBoard.GameBoard[ToX][ToY].setPosition(Point(ToX,ToY));
				
			
				if(CurrentPlayer == 0)
				{
					GameBoard.player2_pieces--;
					if(emulate == false)
					{
					checkFinished();
					}
					CurrentPlayer = 1;
				}	
				else
				{
					GameBoard.player1_pieces--;
					CurrentPlayer = 0;
				}
				CurrentTurn++;
				history.push_back(GameBoard);
				

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
				GameBoard.GameBoard[ToX][ToY].setPosition(Point(ToX,ToY));
			
				if(CurrentPlayer == 0)
				{
					CurrentPlayer = 1;
					checkFinished();
				}	
				else
				{
					CurrentPlayer = 0;
				}
				CurrentTurn++;
				history.push_back(GameBoard);
			
				
				
			}
			
		}
		else
		{
			if(emulate == false)
			{
			cout<< "that piece does not belong to the current player "<< endl;
			}
		}
		//display();
		//check if the piece at fromX,fromY belongs to current player
		//evaluate if move is leagal
		//if(evaluate(fromX,fromY,toX,toY){
		//exchange GameBoard[FromX,FromY] with GameBoard[ToX,ToY]
				//else{cout<<"illegal Move"<<end;}
	}
	void Game::go()
	{
		cout << " the current player is " << endl;
		if((CurrentPlayer == 1)&&(m_finished == false))
		{
			emulate =true;
		PlayedGames testMove = go(GameBoard,1,0);
		emulate = false;
		make(testMove.From.m_x,testMove.From.m_y,testMove.To.m_x,testMove.To.m_y);
		checkFinished();
		}
	}
	PlayedGames Game::go(Board B,int player,int deapth)
	{
		
		
		//if difficulty 
		int Maxdeapth = 0;
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
		int random = rand() % Moves.size();
		if(getDifficulty() == 0)
		{
			return Moves[random];
		}
		else if(getDifficulty() == 1)
		{
		Maxdeapth = 0;
		}
		else if(getDifficulty() == 2)
		{
			Maxdeapth = 3;
		}
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
		return bestGame;
		
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
						Piece temp = GameBoard.GameBoard[i][j];
						legal(vect,GameBoard.GameBoard[i][j]);
						for(Point M : vect)
						{
							if((M.m_x >= 0)&&(M.m_x <= GameBoard.getHeight()))
							{
								if((M.m_y >= 0)&&(M.m_y <= GameBoard.getHeight()))
								{
									unsigned int hist = history.size();
									make(i,j,M.m_x,M.m_y);
									CurrentPlayer = player;
									int score = evaluate(GameBoard,player);
									
									if(history.size() > hist)
									{
									Moves.push_back(PlayedGames(Point(i,j),Point(M.m_x,M.m_y),score));
									retract();
									}
								}
							}
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
		history.pop_back();
		//GameBoard.Revert(history[CurrentTurn]);
		//display();
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
		cout << "player 0 has " << GameBoard.player1_pieces << " left and player 1 has " <<GameBoard.player2_pieces << " pieces left" <<endl;
	}
	int Game::evaluate(Board B ,int player)
		{
			if(player == 0)
			{
				return GameBoard.player1_pieces-GameBoard.player2_pieces;
			}
			else
			{
				return GameBoard.player2_pieces-GameBoard.player1_pieces;
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
		GameBoard.player1_pieces = 0;
		GameBoard.player2_pieces = 0;
		MaxPlays = 10;
		CurrentTurn = 0;
		CurrentPlayer = 0;
		GameBoard.SetSize(5,5);
		GameBoard.GameBoard[3][1].setPlayer(0);
		GameBoard.player1_pieces++;
		GameBoard.GameBoard[2][1].setPlayer(0);
		GameBoard.player1_pieces++;
		
		GameBoard.GameBoard[0][2].setMoves(1,1,1,1);
		GameBoard.GameBoard[2][1].setMoves(1,1,1,1);
		GameBoard.GameBoard[1][1].setPlayer(1);
		GameBoard.player2_pieces++;
		GameBoard.GameBoard[1][1].setMoves(1,1,1,1);
	//	GameBoard.GenerateBoard();
		history.push_back(GameBoard);
		
	
	}
	void Game::checkFinished()
	{
		if(GameBoard.player1_pieces == 0)
		{
			cout << "Player 0 wins he did it in "<< CurrentTurn << " turns " <<endl;
			m_finished = true;
		}
		else if(GameBoard.player2_pieces == 0)
		{
			cout << "Player 1 wins he did it in "<< CurrentTurn << " turns " <<endl;
			m_finished = true;
		}
		else
		{

		}
	}
	

