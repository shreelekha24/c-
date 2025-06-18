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
bool solve(TreeNode* root,long long& prev)
{
    if(root==NULL) return true;
    bool left=solve(root->left,prev);
    if(prev<root->val)
    {
        prev=root->val;
    }
    else return false;
    bool right=solve(root->right,prev);
    return left && right;
}
    bool isValidBST(TreeNode* root) {
        long long prev=LLONG_MIN;
        return solve(root,prev);
    }
};