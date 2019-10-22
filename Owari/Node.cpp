#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
public:
	int depth = 0;
	int alpha = 0;
	int beta = 0;
	
	node* child1;
	node* child2;
	node* child3;
	node* child4;
	node* child5;
	node* child6;
}

Node::Node(int depth)
{
public:
	int depth = depth;
	int alpha = 0;
	int beta = 0;
	node* child1;
	node* child2;
	node* child3;
	node* child4;
	node* child5;
	node* child6;
}

int Node::getDepth()
{
	return depth;
}