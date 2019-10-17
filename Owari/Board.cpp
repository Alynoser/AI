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
	pitNumber = 13;
	for(int i = 0; i <= pitNumber; i++)
	{
		if(i != 0 && i != 7)
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
void Board::setTurn(char whoseTurn)
{
	if(tolower(whoseTurn) == 'y')
		humansTurn = true;
	else if(tolower(whoseTurn) == 'n')
		humansTurn = false;
	else
	{
		cout << "Invalid character. Program terminating.\n";
		exit(0);
	}
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

void Board::move(int pitNumber)
{
	int pitCount = getPitCount(pitNumber);
	setPitCount(pitNumber, 0);
	pitNumber = getNextPitNum(pitNumber);
	while(pitCount != 0)
	{
		setPitCount(pitNumber, getPitCount(pitNumber) + 1);
		pitCount--;
		if (pitCount != 0)
		{
			pitNumber = getNextPitNum();
		}
	}
}


void Board::capture()
{
	
}

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