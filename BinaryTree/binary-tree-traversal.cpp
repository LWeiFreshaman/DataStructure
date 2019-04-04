/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
		if (!root)
			return result;

		stack<TreeNode*> s;
		auto tmp = root;
	
		while (!s.empty() || tmp)
		{
			while (tmp->left)
			{
				s.push(tmp->left);
				tmp = tmp->left;
			}

			tmp = s.top();
			result.push_back(tmp->val);
			s.pop();
			tmp = tmp->right;
		}
		
		return result;
    }
};




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
			return {};
		
		stack<TreeNode*> st;
		vector<int> result;
		TreeNode* tmp = root, *last = root;
		st.push(tmp);
		
		while (!st.empty())
		{
			tmp = st.top();
			if ((tmp->left == nullptr && tmp->right == nullptr) || (tmp->right == nullptr && tmp->left == last) || tmp->right == last)
			{				
                result.push_back(tmp->val);
				st.pop();
				last = tmp; 
			}
            else 
            {
			    if (tmp->right)
                {
                    st.push(tmp->right);
                }
			    if (tmp->left)
                {
			    	st.push(tmp->left);
                }
            }
		}
		
		return result;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		if (root == nullptr)
			return vector<int>{};
		
		stack<TreeNode*> st;
		vector<int> result;
		st.push(root);
		
		while (!st.empty())
		{
			TreeNode* tmp = st.top();
			result.push_back(tmp->val);
			st.pop();
			
			if (tmp->right)
				st.push(tmp->right);
			if (tmp->left)
				st.push(tmp->left);
		}
		
		return result;
    }
};