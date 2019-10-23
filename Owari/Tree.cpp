#include "Tree.h"
#include <vector>
#include <iostream>
using namespace std;

Tree::Tree()
{
	root = new Node();
	depth = 6;
}

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
				tempBoard.move(i-1);
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
int Tree::evaluateTree()
{ 
	//sets up base varibles that are used in the function

	Node* temp = root;
	int favoriteChild = 0;
	int rootArray[6] = root->getArray();
	while (rootArray[5] == 0)
	{
		// recurring varialbes that are in the loop
		int value = 0;
		bool evalueatedMove = false;
		int tArray[6] = temp->getArray();
		int tAlpha = temp->getAlpha();
		int tBeta = temp->getBeta();
		int tDepth = temp->getDepth();
		// if beta is larger than alpha and not infinte stop evaluating on this node
		if (tBeta >= tAlpha)
		{
			tArray = [1, 1, 1, 1, 1, 1];
		}
		//checks the depth to see if max depth reached
		if (tDepth == 6)
		{
			Board x = temp->getBoard();
			value = evaluateBoard(x);
			evalueatedMove = true;
			temp = temp->getNode(0);
		}
		//moves to next child node
		else if (tArray[0] == 0)
		{
			temp = temp->getNode(1);
		}
		
		else if (tArray[1] == 0)
		{
			temp = temp->getNode(2);
		}
		else if (tArray[2] == 0)
		{
			temp = temp->getNode(3);
		}
		else if (tArray[3] == 0)
		{
			temp = temp->getNode(4);
		}
		else if (tArray[4] == 0)
		{
			temp = temp->getNode(5);
		}
		else if (tArray[5] == 0)
		{
			temp = temp->getNode(6);
		}
		//all children evaluated returning the alpha / beta result
		else
		{
			if (tDepth % 2 == 0)
			{
				value = tAlpha;
			}
			else
			{
				value = tBeta;
			}
			temp = temp->getNode(0);
			evalueatedMove = true;
		}
		// changes the alpha beta based on the current depth
		if (evalueatedMove)
		{
			tDepth = temp->getDepth();
			if (tDepth % 2 = 0)
			{
				tAlpha = temp->getAlpha();
				if (value > tAlpha)
				{
					temp->setAlpha(value);
				}
			}
			else
			{
				tBeta = temp->getBeta();
				if (value < tBeta)
				{
					temp->setBeta(value);
				}
			}
			temp->flipBit();
		}
		//check if the current node is the head, if so it does special actions.
		if (temp == root)
		{
			tArray = temp->getArray();
			tAlpha = temp->getAlpha();
			if (tAlpha > favoriteChild)
			{
				favoriteChild = tAlpha;
			}
			rootArray = tArray;
		}
		
	}
	return favoriteChild;
}
int Tree::evaluateBoard(Board x)
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