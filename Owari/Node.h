#pragma once
#include "Board.h"

class Node
{
private:
	int depth;
	int alpha;
	int beta;
	int aray[6] = {0, 0, 0, 0, 0, 0};

	Board board;

	Node* child1;
	Node* child2;
	Node* child3;
	Node* child4;
	Node* child5;
	Node* child6;
	Node* prev_child;

public:
	// Node(): Initilizes a node to default values
	Node();
	// Node(int, Board): Initilize a node with a depth and a board
	Node(int depth, Board board);

	// getDepth(): Return the depth of a node
	int getDepth();
	// getAlpha(): Return the alpha value of a node
	int getAlpha();
	// getBeta(): Return the Beta value of a node
	int getBeta();
	// getBoard(): Returns the board in a current node
	Board getBoard();
	// getNode(int): Returns the child node if specified 1-6, or the previous node if a number 
	//				 other than 1-6 is given
	Node* getNode(int num);

	// setDepth(int): Sets depth of a node to mDepth
	void setDepth(int mDepth);
	// setAlpha(int): Sets alpha value of a node to mAlpha
	void setAlpha(int mAlpha);
	// setBeta(int): Sets beta value of a node to mBeta
	void setBeta(int mBeta);
	// setNode(int, Node*): Sets child node 1-6 (or previous if not 1-6) to the node given by 
	//						Node*
	void setNode(int num, Node* node);

	// setBoard(Board board): Sets current nodes board to board
	void setBoard(Board board);

	int getArry();

	void setArry(int temp)
};