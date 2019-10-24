#include <iostream>
#include "Board.h"
#include <stdlib.h>
#include "Node.h"
#include "Tree.h"

using namespace std;



void runGame(Board newBoard)
{
	int pitnum = 0;
	int prevMove = -1;
	newBoard.whoMovesFirst();
	while (!newBoard.endOfGame())
	{
		system("clear");
		newBoard.printBoard();
		//humans turn
		if (newBoard.getTurn())
		{
			cout << "Please enter pit num to move" << endl;
			cin >> pitnum;
			if (pitnum != 7 && pitnum != 8 && pitnum != 9 && pitnum != 10 && pitnum != 11 && pitnum != 12)
			{
				while (pitnum != 7 && pitnum != 8 && pitnum != 9 && pitnum != 10 && pitnum != 11 && pitnum != 12)
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
			Tree temp(6, newBoard);
			temp.populateTree();
			pitnum = temp.evaluateTree();
			newBoard.move(pitnum);
			prevMove = pitnum;
			newBoard.setTurn();
		}
	}

}

int main()
{
	Board newBoard;
	runGame(newBoard);

	int x;
	cin >> x;
	return 0;
}