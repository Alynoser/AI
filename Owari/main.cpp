#include <iostream>
#include "Board.h"
#include <stdlib.h>

using namespace std;

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

int main()
{
	Board newBoard;

	cout << newBoard.getTurn();
	runGame(newBoard);

	return 0;
}