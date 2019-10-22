#include "Node.h"
#include "Tree.h"
#include "Board.h"

class Tree
{
private:
	int depth;
	Node* root;

public:
	// Tree(): Initilizes depth to 6
	Tree();
	// Tree(int, Board): Initilizes depth to int depth or to 6 if it doesn't fit parameters,
	//					 Initilizes nodes board to Board board
	Tree(int depth, Board board);

	void populateTree();
}