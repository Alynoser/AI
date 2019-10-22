#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
	depth = -1;
	alpha = -1;
	beta = -1;
}

Node::Node(int depth, Board board)
{
	depth = depth;
	alpha = -1;
	beta = -1;
	this.board = board;
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

Node* Node::getNode(int num)
{
	if(num == 1)
		return child1;
	else if(num == 2)
		return child2;
	else if(num == 3)
		return child3;
	else if(num == 4)
		return child4;
	else if(num == 5)
		return child5;
	else if(num == 6)
		return child6;
	else
		return prev_child;
}

Board Node::getBoard()
{
	return board;
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

void Node::setNode(int num, Node* child)
{
	if(num == 1)
		child1 = child;
	else if(num == 2)
		child2 = child;
	else if(num == 3)
		child3 = child;
	else if(num == 4)
		child4 = child;
	else if(num == 5)
		child5 = child;
	else if(num == 6)
		child6 = child;
	else
		prev_child = child;
}

void Node::setBoard(Board board)
{
	this.board = board;
}