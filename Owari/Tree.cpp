#include "Tree.h"

using namespace std;

Tree::Tree()
{
	depth = 6;
}

Tree::Tree(int depth,Board board)
{
	if(depth < 0 || depth > 6)
		cout << "Depth is being set to 6." << endl;
		depth = 6;
	else
		this.depth = depth;

	root->setBoard(board);
}

void Tree::populateTree()
{
	
}