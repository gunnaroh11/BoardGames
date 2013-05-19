<h1>HLUTBUNDIN FORRITUN</h1> 
<center>
	<h2>- VOR 2013</h2>	 						
<h3>- Assignment 2</h3>
<h1>Boardgames</h1>
</center>
</br>
<center>
<p>	
	Gunnar Orn Haraldsson
</p>
<p>
	Kristofer Kristofersson
</p>
</center>
<hr/>

<h2>Report</h2>

<p>
We began to brake down the assignment and the general description 
of turn based boardgames for 2 players. 
</p>
<p>
Soon we decited to let each "part/class" take care of it self and 
related behavior and properties. Also one of the requirments was to 
be able to retract moves so we used vector off boards that stores each
state of the game.
</p>
<p>
We decited to brake the games project down to a "GameEngine" as main program to 
run the created games and following classes:
</p>
<ul>
	<li><p> Game is the main game class with virtual functions to be overwritten
		for each new derived and implemented game. Game class has instance 
		of Board. Game also implements how and where Piece 's can move based
		considering current situation.</p></li>
	<li>
		<p>
		Board is a double vector class for gameboard grid, that holds pieces and controls
		the setup of board and basic functions.
		</p>
	</li>
	<li>
	<p>
		Piece is a class that is implemented for each type of pieces fx. Pawn, this
		class contains functions and logic so it "knows" it position on the gameboard
		and what are possible cords that it can move to and provides Game class with this
		information.
	</p>
	</li>
	<li>
	<p>
		Pawn is a derived class from Piece and has been implemented for the games in this project.
	</p>
	</li>
</ul>

<p>And the following structs:</p>
<ul>
	<li>Point is a simple cord struct with simple functionality, but as some comparision implemented and assignment. 
	</li>
	<li>MoveDir is part of Piece and holds indicates how pieces can move that is how far each direction</li>
	<li>PlayedGames simple struct to handle moves and score</li>
</ul>

<hr/>
The GameEngin holds and runs the games selected and passes input commands to each Game class. The game class and its
derived classes implement and run the games according to each game rules etc. And takes care of moving Piece ´s on the table
and holds the game logic. The Game class is responsible for putting every thing to gether like gameboard, pieces, scores etc.
