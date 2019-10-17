#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	Board newBoard;

	cout << newBoard.getTurn();
	for(int i = 0; i < 14; i++)
	{
		cout << "Pit: " << i;
		cout << " has " << newBoard.getPitCount(i);
		cout << " stones.\n";
	}
	return 0;
}