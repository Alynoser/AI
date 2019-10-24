#include "Tree.h"
#include <vector>
#include <iostream>
using namespace std;

Tree::Tree()
{
	root = new Node();
	depth = 6;
}

Tree::Tree(int depth1, Board board)
{
	root = new Node();
	if (depth < 0 || depth > 7)
	{
		cout << "Depth is being set to 6." << endl;
		depth = 7;
	}
	else
		depth = depth1;

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
	while (true)
	{
		//gets first item on the queue
		Node* firstVecNode = v[0];
		//goes through the 6 children of the current node creating them
		for (int i = 1; i <= 6; i++)
		{
			//gets the current board
			Board tempBoard = firstVecNode->getBoard();
			//gets whos turn it should be
			bool hTurn = tempBoard.getTurn();
			//checks for if computer or human turn, and current depth
			//if depth is at max depth, nothing happens
			if (hTurn && (firstVecNode->getDepth() < depth))
			{
				// Sets the current
				tempBoard.move(i + 6);
			}
			//same as everything above
			else if (!hTurn && (firstVecNode->getDepth() < depth))
			{
				tempBoard.move(i - 1);
			}
			else if (firstVecNode->getDepth() >= depth)
			{
				break;
			}
			Node* newNode = new Node((firstVecNode->getDepth() + 1), tempBoard);
			newNode->setPrev(firstVecNode);
			Node* currPrev = firstVecNode;
			currPrev->setNext(i, newNode);
			v.push_back(newNode);
		}

		//removes the item at the begining of the queue, starts again.
		v.erase(v.begin());
		if (v.size() == 0)
			break;
	}
}

int Tree::evaluateTree(int prevMove)
{
	//sets up base varibles that are used in the function

	Node* temp = root;
	int move = -1;
	int favoriteChild = 0;
	int rootVisit = 0;

	while (true)
	{
		// recurring varialbes that are in the loop
		int value = 0;
		bool evalueatedMove = false;
		int tArray[6];
		int tDepth = temp->getDepth();
		for (int i = 0; i < 6; i++)
		{
			tArray[i] = temp->getArayValue(i);
		}
		int tAlpha = temp->getAlpha();
		int tBeta = temp->getBeta();

		// if beta is larger than alpha and not infinte stop evaluating on this node
		if ((tBeta >= tAlpha) && (tAlpha != -100001) && (tBeta != 100001))
		{
			for (int i = 0; i < 6; i++)
			{
				tArray[i] = 1;
			}
		}
		//checks the depth to see if max depth reached
		if (tDepth == depth)
		{
			Board x = temp->getBoard();
			value = evaluateBoard(x);
			evalueatedMove = true;
			temp = temp->getPrev();
		}
		//moves to next child node
		else if (tArray[0] == 0)
		{
			temp = temp->getNext(1);
			temp->setAlpha(tAlpha);
			temp->setBeta(tBeta);
		}

		else if (tArray[1] == 0)
		{
			temp = temp->getNext(2);
			temp->setAlpha(tAlpha);
			temp->setBeta(tBeta);
		}
		else if (tArray[2] == 0)
		{
			temp = temp->getNext(3);
			temp->setAlpha(tAlpha);
			temp->setBeta(tBeta);
		}
		else if (tArray[3] == 0)
		{
			temp = temp->getNext(4);
			temp->setAlpha(tAlpha);
			temp->setBeta(tBeta);
		}
		else if (tArray[4] == 0)
		{
			temp = temp->getNext(5);
			temp->setAlpha(tAlpha);
			temp->setBeta(tBeta);
		}
		else if (tArray[5] == 0)
		{
			temp = temp->getNext(6);
			temp->setAlpha(tAlpha);
			temp->setBeta(tBeta);
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
			temp = temp->getPrev();
			evalueatedMove = true;
		}
		// changes the alpha beta based on the current depth
		if (evalueatedMove)
		{
			tDepth = temp->getDepth();
			if (tDepth % 2 == 0)
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
			Board b = root->getBoard();
			for (int i = 0; i < 6; i++)
			{
				tArray[i] = temp->getArayValue(i);
			}
			tAlpha = temp->getAlpha();
			if (tAlpha > favoriteChild)
			{

				if ((tArray[0] == 0) && b.getPitCount(0) != 0)
				{
					move = 0;
					favoriteChild = tAlpha;
				}
				else if ((tArray[1] == 0) && b.getPitCount(1) != 0)
				{
					move = 1;
					favoriteChild = tAlpha;
				}
				else if ((tArray[2] == 0) && b.getPitCount(2) != 0)
				{
					move = 2;
					favoriteChild = tAlpha;
				}
				else if ((tArray[3] == 0) && b.getPitCount(3) != 0)
				{
					move = 3;
					favoriteChild = tAlpha;
				}
				else if ((tArray[4] == 0) && b.getPitCount(4) != 0)
				{
					move = 4;
					favoriteChild = tAlpha;
				}
				else if ((tArray[5] == 0) && b.getPitCount(5) != 0)
				{
					move = 5;
					favoriteChild = tAlpha;
				}
			}
			rootVisit++;
			if (rootVisit == 6)
			{
				break;
			}

		}

	}

	return move;
}
int Tree::evaluateBoard(Board x)
{
	int evaluatePoints = 0;
	evaluatePoints = evaluatePoints + x.getMyPoints() - x.getPlayerPoints();
	for (int i = 0; i < 6; i++)
	{
		if (x.canCapture(i))
		{
			evaluatePoints = evaluatePoints + x.captureSize(i);
		}
	}
	for (int i = 7; i < 13; i++)
	{
		if (x.canCapture(i))
		{
			evaluatePoints = evaluatePoints - x.captureSize(i);
		}
	}
	if (x.isFucked(0))
	{
		evaluatePoints = evaluatePoints - 10;
	}
	if (x.isFucked(7))
	{
		evaluatePoints = evaluatePoints + 10;
	}

	return evaluatePoints;
}