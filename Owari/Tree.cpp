#include "Tree.h"
#include <vector>
#include <iostream>
using namespace std;

Tree::Tree()
{
	depth = 6;
}

Tree::Tree(int depth1,Board board)
{
	if(depth < 0 || depth > 6)
	{
		cout << "Depth is being set to 6." << endl;
		depth = 6;
	}
	else
		depth = depth1;

	root->setBoard(board);
	root->setDepth(0);
}

void Tree::populateTree()
{
	vector<Node*> v;
	Node* temp = root;
	v.push_back(temp);
	while(true)
	{
		Node* temp1 = v[0];
		for(int i = 1; i <= 6; ++i)
		{
			Board tempBoard = temp->getBoard();
			bool turn = tempBoard.getTurn();
			if(turn && (temp->getDepth() < depth))
			{
				tempBoard.move((i+6));
				temp->getNode(i)->setBoard(tempBoard);
				temp->getNode(i)->setNode(0, temp);
				temp->getNode(i)->setDepth(temp->getDepth() + 1);
				temp->getNode(i)->getBoard().setTurn();
				v.push_back(temp->getNode(i));
			}
			else if(!turn && (temp->getDepth() < depth))
			{
				tempBoard.move(i);
				temp->getNode(i)->setBoard(tempBoard);
				temp->getNode(i)->setNode(0, temp);
				temp->getNode(i)->setDepth(temp->getDepth() + 1);
				temp->getNode(i)->getBoard().setTurn();
				v.push_back(temp->getNode(i));
			}

		}

		v.erase(v.begin());
		if(v.size() == 0)
			break;
	}
}