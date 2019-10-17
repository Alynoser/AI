// Chris Borg, Elysha Menefee, & Ryan Richter
// Date: Oct 24, 2019
// board.cpp
// Purpose: Define methods for board.h

#include <iostream>
#include "Board.h"

using namespace std;

// Board: initializer
Board::Board()
{	
	humansTurn = true;
	for(int i = 0; i <= 13; i++)
	{
		if(i != 6 && i != 13)
		{
			pit[i] = 3;
		}
		else
		{
			pit[i] = 0;
		}
	}
}

// getTurn()
// Returns true if it is the human players turn and false if it is the AI's turn
bool Board::getTurn()
{
	return humansTurn;
}

// setTurn(bool)
// Changes humansTurn depending on input. y/Y will set humansTurn to true, n/N 
// 		will set humansTurn to false
void Board::setTurn()
{
	if(humansTurn)
		humansTurn = false;
	else //(!humanTurn)
		humansTurn= true;
}

// getPitCount(int)
// Returns the count of 'stones' in a certain index of the pit array
int Board::getPitCount(int pitIndex)
{
	if(pitIndex < 0 || pitIndex > 13)
		return -1;
	else
		return pit[pitIndex];
}

// setPitCount(int, int)
// Sets an index in the pit array to the value specified by pitCount
void Board::setPitCount(int pitIndex, int pitCount)
{
	if(pitCount <= 0)
		pit[pitIndex] = pitCount;
	else
	{
		cout << "Invalid stone count. Program terminating.\n";
		exit(0);
	}
}

// whoMovesFirst()
// A function that prompts the user to enter who they want to move first.
// Sets the turn to the users choice
void Board::whoMovesFirst()
{
	char i;
	bool prompt = true;

	while(propt)
	{
		cout << "Would you like to move first? (y/n)";
		cin >> i;
		if(tolower(i) != 'y' || tolower(i) != 'n')
			propt = true;
		else
			propt = false;
	}

	if (tolower(i) == 'y')
		humansTurn = true;
	else // (tolower(i) == 'n')
		humansTurn = false;
}

void Board::move()
{
	//TODO
}