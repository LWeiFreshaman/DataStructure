#ifndef TRIETREE_H__
#define TRIETREE_H__

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>

using namespace std;

class TreeNode
{
public:
    TreeNode(int index, int val, TreeNode* parent)
    : m_index(index), m_val(val), m_parent(parent), hasX(false), failedPtr(nullptr)
    {
        
    }

    TreeNode* addChild(int nodeIndex, int nodeVal);

    int m_val;    //value
    int m_index;
    list<TreeNode*> m_children;
    TreeNode* m_parent;
    TreeNode* failedPtr;
    bool hasX;
};

class TrieTree
{
private:
    TreeNode *root;
    
    TreeNode* findIndex(TreeNode* node, int index, int& result, bool firstCall);

public:
    TrieTree()
    {
        root = new TreeNode(0, 0, nullptr);
        root->failedPtr = root;
    }
    void addPath(const string& path, int value);
    void setFailedPtr();
    void traversal();
    int findPath(const string& str);
};

#endif
