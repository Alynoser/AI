#include <iostream>
#include "Board.h"
#include <stdlib.h>
#include "Node.h"
#include "Tree.h"

using namespace std;

int Evaluate(Board x)
{
	int evaluatePoints = 0;
	evaluatePoints = evaluatePoints + x.getMyPoints() - x.getPlayerPoints();
	for (int i = 0; i < 5; i++)
	{
		if (x.canCapture(i))
		{
			if (x.captureSize(i) != 0)
			{
				evaluatePoints = evaluatePoints + 3;
			}
		}
	}
	for (int i = 7; i < 12; i++)
	{
		if (x.canCapture(i))
		{
			if (x.captureSize(i) != 0)
			{
				evaluatePoints = evaluatePoints - 3;
			}
		}
	}
	if (x.isFucked(7))
	{
		evaluatePoints = evaluatePoints + 10;
	}
	if (x.isFucked(0))
	{
		evaluatePoints = 0;
	}
	return evaluatePoints;
}

void runGame(Board newBoard)
{
	int pitnum = 0;
	newBoard.whoMovesFirst();
	while(!newBoard.endOfGame())
	{
		system("clear");
		newBoard.printBoard();
		//humans turn
		if(newBoard.getTurn())
		{	
			cout << "Please enter pit num to move" << endl;
			cin >> pitnum;
			if(pitnum != 7 && pitnum != 8 && pitnum != 9 && pitnum != 10 && pitnum != 11 && pitnum != 12)
			{
				while(pitnum != 7 && pitnum != 8 && pitnum != 9 && pitnum != 10 && pitnum != 11 && pitnum != 12)
				{
					cout << "Please enter a proper value" << endl;
					cin >> pitnum;
				}
			}
			newBoard.move(pitnum);
			newBoard.setTurn();
		}
		//computer turn
		else
		{
			//pitnum = ryans code
			newBoard.move(pitnum);
			newBoard.setTurn();
		}
	}

}
int FindMove(Board x)
{
	Tree tree(0, x);
	tree.populateTree();
	int move = tree.evaluateTree();
	return move;
}

int main()
{
	Board newBoard;
	// runGame(newBoard);
	Tree temp(2, newBoard);
	temp.populateTree();

	return 0;
}