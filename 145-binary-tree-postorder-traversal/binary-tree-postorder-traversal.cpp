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
void solve(TreeNode* root,stack<TreeNode*>&st)
{
    if(root==NULL)
    return;
    st.push(root);
    solve(root->right,st);
    solve(root->left,st);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>st;
        solve(root,st);
        while(!st.empty())
        {
            v.push_back(st.top()->val);
            st.pop();
        }
        return v;
    }
};