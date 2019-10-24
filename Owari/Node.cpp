#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
	depth = -1;
	alpha = -100001;
	beta = 100001;
}

Node::Node(int depth1, Board board1)
{
	depth = depth1;
	alpha = -100001;
	beta = 100001;
	board = board1;
}

int Node::getDepth()
{
	return depth;
}

int Node::getAlpha()
{
	return alpha;
}

int Node::getBeta()
{
	return beta;
}

Board Node::getBoard()
{
	return board;
}

Node* Node::getPrev()
{
	return prev_child;
}

Node* Node::getNext(int i)
{
	switch (i)
	{
	case(1):
		return child1;
		break;
	case(2):
		return child2;
		break;
	case(3):
		return child3;
		break;
	case(4):
		return child4;
		break;
	case(5):
		return child5;
		break;
	case(6):
		return child6;
		break;
	}
}

void Node::setDepth(int mDepth)
{
	depth = mDepth;
}

void Node::setAlpha(int mAlpha)
{
	alpha = mAlpha;
}

void Node::setBeta(int mBeta)
{
	beta = mBeta;
}

void Node::setPrev(Node* prev)
{
	prev_child = prev;
}

void Node::setNext(int i, Node* next)
{
	switch (i)
	{
	case(1):
		child1 = next;
		break;
	case(2):
		child2 = next;
		break;
	case(3):
		child3 = next;
		break;
	case(4):
		child4 = next;
		break;
	case(5):
		child5 = next;
		break;
	case(6):
		child6 = next;
		break;
	}
}

void Node::setBoard(Board board1)
{
	board = board1;
}

int* Node::getArry()
{
	return aray;
}


void Node::flipBit()
{
	if (aray[0] == 0)
	{
		aray[0] = 1;
	}
	else if (aray[1] == 0)
	{
		aray[1] = 1;
	}
	else if (aray[2] == 0)
	{
		aray[2] = 1;
	}
	else if (aray[3] == 0)
	{
		aray[3] = 1;
	}
	else if (aray[4] == 0)
	{
		aray[4] = 1;
	}
	else if (aray[5] == 0)
	{
		aray[5] = 1;
	}
}
int Node::getArayValue(int location)
{
	return aray[location];
}

