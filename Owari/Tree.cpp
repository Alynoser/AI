#include "Tree.h"
#include <vector>
#include <iostream>
using namespace std;

//default creation of the tree
Tree::Tree()
{
	root = new Node();
	depth = 6;
}

//normal tree creation that takes a depth size and a board
Tree::Tree(int depth1,Board board)
{
	root = new Node();
	if(depth < 0 || depth > 6)
	{
		cout << "Depth is being set to 6." << endl;
		depth = 6;
	}
	else
		depth = depth1;
	//sets the roots board and depth and previous pointer to null
	root->setNode(0, NULL);
	root->setBoard(board);
	root->setDepth(0);
}

void Tree::populateTree()
{
	// creates a vector that should be used as a queue when populating the tree
	vector<Node*> v;
	//copies the root node
	Node* temp = root;
	v.push_back(temp);
	while(true)
	{
		//pops node off queue
		Node* temp1 = v[0];
		//goes through the 6 children of the current node creating them
		for(int i = 1; i <= 6; ++i)
		{
			//gets the current board
			Board tempBoard = temp->getBoard();
			//gets whos turn it should be
			bool turn = tempBoard.getTurn();
			//checks for if computer or human turn, and current depth
			//if depth is at max depth, nothing happens
			if(turn && (temp->getDepth() < depth))
			{
				//gets the next move avaliable
				tempBoard.move((i+6));
				//setss the board to the child
				temp->getNode(i)->setBoard(tempBoard);
				//sets the prev node of the child to the curr node
				temp->getNode(i)->setNode(0, temp);
				//sets the depth of the child to curr + 1
				temp->getNode(i)->setDepth(temp->getDepth() + 1);
				//sets the turn of the child
				temp->getNode(i)->getBoard().setTurn();
				//adds the child node to the queue vector
				v.push_back(temp->getNode(i));
			}
			//same as everything above
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
		//removes the item at the begining of the queue
		v.erase(v.begin());
		if(v.size() == 0)
			break;
	}
}