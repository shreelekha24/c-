/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
        return v;
        stack<TreeNode*>st1;
        st1.push(root);
        stack<int>st2;
        while(!st1.empty())
        {
            TreeNode* node=st1.top();
            st1.pop();
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL)st1.push(node->right);
            st2.push(node->val);
        }
        while(!st2.empty()){
            v.push_back(st2.top());
            st2.pop();
        }
        return v;
    }
};