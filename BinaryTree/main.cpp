#include "BinaryTree.h"

int main()
{
	BinaryTree<int> binTree;
	for (int i = 1; i < 16; ++i)
		binTree.addNode(i);
	
	cout << "preOrderTraversal:" << endl;
	binTree.preOrderTraversal();
	cout << "inOrderTraversal:" << endl;
	binTree.inOrderTraversal();
	cout << "postOrderTraversal:" << endl;
	binTree.postOrderTraversal();
	cout << "levelOrderTraversal:" << endl;
	binTree.levelOrderTraversal();
	cout << "height:" << endl;
	cout << binTree.getHeight() << endl;
	cout << "nodeCount:" << endl;
	cout << binTree.size() << endl;
	
	return 0;
}
