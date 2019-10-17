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
// Returns true if it is the human players (north) turn and false if it is the AI's (south) turn
bool Board::getTurn()
{
	return humansTurn;
}

// setTurn()
// Will switch the turns depending on what it is.
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
	if(pitCount >= 0)
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

	while(prompt)
	{
		cout << "Would you like to move first? (y/n)";
		cin >> i;

		if(tolower(i) == 'y' || tolower(i) == 'n')
			propt = false;
	}

	if (tolower(i) == 'y')
		humansTurn = true;
	else // (tolower(i) == 'n')
		humansTurn = false;
}

// given a position on the board, will move the beads until it runs out
void Board::move(int pitNumber)
{
	int pitCount = getPitCount(pitNumber);
	setPitCount(pitNumber, 0);
	pitNumber = getNextPitNum(pitNumber);
	while(pitCount != 0)
	{
		if(getTurn() && pitNumber == 7)
		{
			pitNumber = getNextPitNum(pitNumber);
		}
		else if(!getTurn() && pitNumber == 13)
		{
			pitNumber = getNextPitNum(pitNumber);
		}
		setPitCount(pitNumber, (getPitCount(pitNumber) + 1));
		pitCount--;
		if (pitCount != 0)
		{
			pitNumber = getNextPitNum(pitNumber);
		}
	}
	capture(pitNumber);
}

// checks and sees if the last move makes a captures
void Board::capture(int pitNumber)
{
	//spots 7 - 12
	if (getTurn())
	{
		if (pitNumber >= 7 && pitNumber <= 12)
		{
			if (getPitCount(pitNumber) == 1)
			{
				switch(pitNumber)
				{
					case 7:
						setPitCount(13, (getPitCount(13) + getPitCount(5)));
						setPitCount(5, 0);
						break;
					case 8:
						setPitCount(13, (getPitCount(13) + getPitCount(4)));
						setPitCount(4, 0);
						break;
					case 9:
						setPitCount(13, (getPitCount(13) + getPitCount(3)));
						setPitCount(3, 0);
						break;
					case 10:
						setPitCount(13, (getPitCount(13) + getPitCount(2)));
						setPitCount(2, 0);
						break;
					case 11:
						setPitCount(13, (getPitCount(13) + getPitCount(1)));
						setPitCount(1, 0);
						break;
					case 12:
						setPitCount(13, (getPitCount(13) + getPitCount(0)));
						setPitCount(0, 0);
						break;
				}
			}
		}
	}
	//spots 0 - 5
	else
	{
		if (pitNumber >= 0 && pitNumber <= 5)
		{
			if (getPitCount(pitNumber) == 1)
			{
				switch(pitNumber)
				{
					case 0:
						setPitCount(6, (getPitCount(6) + getPitCount(12)));
						setPitCount(12, 0);
						break;
					case 1:
						setPitCount(6, (getPitCount(6) + getPitCount(11)));
						setPitCount(11, 0);
						break;
					case 2:
						setPitCount(6, (getPitCount(6) + getPitCount(10)));
						setPitCount(10, 0);
						break;
					case 3:
						setPitCount(6, (getPitCount(6) + getPitCount(9)));
						setPitCount(9, 0);
						break;
					case 4:
						setPitCount(6, (getPitCount(6) + getPitCount(8)));
						setPitCount(8, 0);
						break;
					case 5:
						setPitCount(6, (getPitCount(6) + getPitCount(7)));
						setPitCount(7, 0);
						break;
				}
			}
		}
	}
}

// gets the next move on the board
int Board::getNextPitNum(int pitNumber)
{
	switch(pitNumber)
	{
		case 0:
			return 1;
		case 1:
			return 2;
		case 2:
			return 3;
		case 3:
			return 4;
		case 4:
			return 5;
		case 5:
			return 6;
		case 6:
			return 7;
		case 7:
			return 8;
		case 8:
			return 9;
		case 9:
			return 10;
		case 10:
			return 11;
		case 11:
			return 12;
		case 12:
			return 13;
		case 13:
			return 0;
		default:
			cout << "Invalid pitNumber. Program terminating.\n" << endl;
			exit(0);
	}
}


// getHumanPlayerMove()
// Asks the user to enter which pit they would like to move (1-6, player must assume they
// 		are on the correct side of the board) and makes a call to move on that position.
void getHumanPlayerMove()
{
	bool prompt = true;
	int pit;
	while(prompt)
	{
		cout << "Please enter a pit to move from (1-6).\n";
		cin >> pit;
		if(pit >= 1 || pit <= 6)
			prompt = false;
	}

	switch(pit)
	{
		case 1:
			pit = 7;
			break;
		case 2:
			pit = 8;
			break;
		case 3:
			pit = 9;
			break;
		case 4:
			pit = 10;
			break;
		case 5:
			pit = 11;
			break;
		case 6:
			pit = 12;
			break;
	}
	move(pit);
}
