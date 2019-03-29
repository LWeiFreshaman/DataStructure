template <typename T> 
struct TreeNode
{
	TreeNode() {  }
	TreeNode(T v) : value(v) {} 
	TreeNode<T> *parent, *left, *right;
	T value;
	size_t highDiff;
};

template <typename T>
class AVLTree
{
public:
	AVLTree() { }
	vode addNode(T value);
	vode delNode(T value);
	TreeNode<T> findNode(T value);
private:
	TreeNode<T> *root;
	size_t nodeCount;
};

template <typename T>
TreeNode<T> findNode(T value)
{

}

template <typename T>
AVLTree::addNode(T v)
{
	TreeNode<T> *tmp = root;
	if (nodeCount == 0)
	{
		root->value = value;
		++nodeCount;
		return;
	}

}