#include "TrieTree.h"

TreeNode* TreeNode::addChild(int nodeIndex, int nodeVal)
{
    TreeNode* child = nullptr;
    for (auto i : m_children)
    {
        if (i->m_index == nodeIndex)            //不重复添加
        {
            child = i;
            break;
        }
    }

    if (child == nullptr)
    {
        child = new TreeNode(nodeIndex, nodeVal, this);
        if (nodeIndex == 10)
        {
            m_children.push_back(child);        //通配符插到最后

            hasX = true;
        }
        else
        {
            m_children.push_front(child);       //其他插在头部
        }
        
    }

    return child;                               //返回插入位置
}

void TrieTree::addPath(const string& path, int value)
{
    auto tmp = root;
    for (auto c : path)
    {
        int index = c == 'x' ? 10 : c - '0';
        tmp = tmp->addChild(index, 0);
    }
    tmp->m_val = value;
}


/***********************************************************************/
//简单参考AC自动机，加入失败指针。
//失败指针指向可能匹配指向的通配符。
//其中root节点指向自身。
/***********************************************************************/
void TrieTree::setFailedPtr()
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        for (auto i : tmp->m_children)
        {
            /*
            if (i->m_index == 10)           //通配符失败指针直接指向root
            {
                i->failedPtr = root;
                q.push(i);
                continue;
            }
            */
            if (tmp->hasX && i->m_index != 10)          //兄弟中有通配符且自己不是通配符
            {
                i->failedPtr = tmp->m_children.back();  //失败指针指向通配符
            }
            else 
            {
                //父节点失败指针指向root或者父节点失败指针指向的节点没有通配符
                if (i->m_parent->failedPtr == root || i->m_parent->failedPtr->hasX == false)    
                {
                    i->failedPtr = root;
                }
                else 
                {
                    i->failedPtr = i->m_parent->failedPtr->m_children.back();
                }
            }
            q.push(i);
        }
    }  
}

void TrieTree::traversal()
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    while (!(q.size() == 1 && q.front() == nullptr))
    {
        auto tmp = q.front();
        if (tmp == nullptr)
        {
            cout << endl;
            q.push(nullptr);
        }
        else 
        {
            cout << tmp << "-" << tmp->m_index << "-" << tmp->m_val << "-" << tmp->hasX << "-" << tmp->failedPtr << " ";
            for (auto iter : tmp->m_children)
            {
                q.push(iter);
            }
        }
        q.pop();
    }
}

TreeNode* TrieTree::findIndex(TreeNode* node, int index, int& result, bool firstCall)
{
    if (node == root && !firstCall)
        return root;

    bool hasFind = false;
    for (auto i : node->m_children)
    {
        if (i->m_index == index || i->m_index == 10)        //找到值或通配符
        {
            auto tmp = i;
            result = tmp->m_val == 0 ? result : tmp->m_val;

            return tmp;
        }
    }
    
    if (hasFind == false)                            //未找到
    {
        auto tmp = node->failedPtr;
        return findIndex(tmp, index, result, false);        //换成失败指针，继续找，直到找到root，说明查找结束。
    }
}
int TrieTree::findPath(const string& str)
{
    auto tmp = root;
    int result = -1;
    for (auto i = str.cbegin(); i != str.cend(); ++i)
    {
        int index = *i - '0';
        tmp = findIndex(tmp, index, result, i == str.cbegin());

        if (tmp == root)
            return result;
    }
    return result;
}




    /*
    int findPath(const string& str)
    {
        auto tmp = root;
        int i = 0;
        int result = -1;                        //-1表示未找到

        while ()
        {
            int index = str[i] - '0';
            bool hasFind = false;
            for (auto i : tmp->m_children)
            {
                if (i->m_index == index)        //找到对应精确值
                {
                    result = tmp->m_val;
                    tmp = i;
                    hasFind = true;
                    break;
                }
                else                            //未找到精确值
                {
                    while (tmp->failedPtr != root)      //使用失败指针,直到失败指针指向root
                    {
                        tmp = tmp->failedPtr;
                        bool hasFind = false;
                        for (auto i : tmp->m_children)
                        {
                            if (i->m_index == index)
                            {
                                hasFind = true;
                                tmp = i;
                            }
                        }
                        if (hasFind == false)   //
                    }
                }
            }


        }
    }
    */
