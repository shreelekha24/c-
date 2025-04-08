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
void pre0(TreeNode* root,vector<int>&pre)
{
   if(root==NULL)
   return;
   pre.push_back(root->val);
   pre0(root->left,pre);
   pre0(root->right,pre);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pre;
        pre0(root,pre);
        return pre;
    }
};