// Chris Borg, Elysha Menefee, & Ryan Richter
// Date: Oct 24, 2019
// board.h
// Purpose: A header file for board.cpp

class Board
{
private:
	bool humansTurn;
	int pit[14];
public:
	// Board(): Initilizes player pits to 3 & Sets humansTurn to true
	Board();
	
	// getTurn(): Returns true if it is the humans turn, false if its the AI's turn
	bool getTurn();

	// setTurn(): Switches the current players turn
	void setTurn();

	// getPitCount(int): Takes an index(pit), returns the amount of 'stones' in said pit 
	int getPitCount(int pitIndex);

	// setPitCount(int, int): Takes 2 parameters, the first is the index(pit), the second 
	//						  is the number of stones to be distributed to that pit
	void setPitCount(int pitIndex, int pitCount);

	// move(): Stay Posted
	void move(int pitNumber);

	// decides if it does a captures
	void capture(int pitNumber);

	// gets the next move in the board
	int getNextPitNum(int pitNumber);

	// whoMovesFirst(): An interactive function that asks the user to input 'y' or 'n', 
	//					depending on if they want to move first. Checks case sensitivity
	//					and reprompts until a valid argument is entered
	void whoMovesFirst();

	// getHumanPlayerMove(): Asks the player to enter which pit they would like to move
	//						 (1-6) on their side. Player must assume that they are on the
	// 						 correct side of the board.
	void getHumanPlayerMove();

	// endOfGame(): Checks to see if the game has ended by checking the North and South 
	//				pits. If any one direction is empty, the function returns true,
	//				otherwise it returns false.
	bool endOfGame();

	// printBoard(): Prints a board that users can visually see
	void printBoard();

	//copyBoard(): takes a board object, and returns a copy of that object
	Board copyBoard(Board newBoard);

	// sees if a pit can capture another pit
	bool canCapture(int pitNumber);
	
	//finds the value of the captureable pit
	int captureSize(int pitNumber);

	//checks to see if the player is in a bad situation
	bool isFucked(int startPit);

	//gets the computers points
	int getMyPoints();

	//gets the players points
	int getPlayerPoints();
};