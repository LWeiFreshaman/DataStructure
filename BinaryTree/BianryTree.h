#ifndef _BINARYTREE_
#define _BINARYTREE_

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
struct TreeNode
{
	TreeNode() : data(0), left(nullptr), right(nullptr) { }
	TreeNode(T d) : data(d), left(nullptr), right(nullptr) { }
	TreeNode<T> *left, *right;
	T data;
};

template <typename T> 
class BinaryTree 
{
public:
	BinaryTree();
	void releaseTreeNode(TreeNode<T> *node);
	~BinaryTree();
	bool isEmpty();
	void addNode(T data);
	void preOrderTraversal(TreeNode<T> *node);
	void preOrderTraversal();
	void inOrderTraversal(TreeNode<T> *node);
	void inOrderTraversal();
	void postOrderTraversal(TreeNode<T> *node);
	void postOrderTraversal();
	void levelOrderTraversal();
	int getHeight(TreeNode<T>* node);
	int getHeight();
	size_t size();
private:
	TreeNode<T> *root;
	size_t nodeCount;
};

/*********************************************Definition**************************************/

template<typename T>
BinaryTree<T>::BinaryTree() : root(nullptr), nodeCount(0)
{
	
}

template<typename T>
void BinaryTree<T>::releaseTreeNode(TreeNode<T> *node)
{	
	if (!node)
		return;
	releaseTreeNode(node->left);
	releaseTreeNode(node->right);
	delete node;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	releaseTreeNode(root);
}

template<typename T>
bool BinaryTree<T>::isEmpty()
{
	return !nodeCount;
}


template<typename T>
void BinaryTree<T>::addNode(T data)
{
	TreeNode<T>* tmp = new TreeNode<T>(data);

	if (!nodeCount)
	{	
		root = tmp;
		++nodeCount;
		return;
	}
	
	stack<size_t> st;
	
	int place = nodeCount + 1;
	while (place)
	{
		st.push(place % 2);
		place /= 2;
	}
	
	st.pop();
	int l_or_r = 0;
	TreeNode<T> *addPlace = root;
	while (1)
	{
		l_or_r = st.top();
		st.pop();
		if (st.empty())
			break;
		if (l_or_r)
			addPlace = addPlace->right;
		else
			addPlace = addPlace->left;
	}
	if (l_or_r)
		addPlace->right = tmp;
	else
		addPlace->left = tmp;
	++nodeCount;
}

template<typename T>
void BinaryTree<T>::preOrderTraversal(TreeNode<T> *node)
{
	if (!node)
		return;
	cout << node->data << " ";
	preOrderTraversal(node->left);
	preOrderTraversal(node->right);
}

template<typename T>
void BinaryTree<T>::preOrderTraversal()
{
	preOrderTraversal(root);
	cout << endl;
}

template<typename T>
void BinaryTree<T>::inOrderTraversal(TreeNode<T> *node)
{
	if (!node)
		return;
	inOrderTraversal(node->left);
	cout << node->data << " ";
	inOrderTraversal(node->right);
}

template<typename T>
void BinaryTree<T>::inOrderTraversal()
{
	inOrderTraversal(root);
	cout << endl;
}

template<typename T>
void BinaryTree<T>::postOrderTraversal(TreeNode<T> *node)
{
	if (!node)
		return;
	postOrderTraversal(node->left);
	postOrderTraversal(node->right);
	cout << node->data << " ";
}

template<typename T>
void BinaryTree<T>::postOrderTraversal()
{
	postOrderTraversal(root);
	cout << endl;
}

template<typename T>
void BinaryTree<T>::levelOrderTraversal()
{
	if (!nodeCount)
		return;
	queue<TreeNode<T>*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode<T>* tmp = q.front();
		q.pop();
		cout << tmp->data << " ";
		if (tmp->left)
			q.push(tmp->left);
		if (tmp->right)
			q.push(tmp->right);
	}
	cout << endl;
}

template<typename T>
int BinaryTree<T>::getHeight(TreeNode<T>* node)
{
	if (!node)
		return 0;
	int lHeight = getHeight(node->left);
	int rHeight = getHeight(node->right);
	
	return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

template<typename T>
int BinaryTree<T>::getHeight()
{
	return getHeight(root);
}

template<typename T>
size_t BinaryTree<T>::size()
{
	return nodeCount;
}

#endif
