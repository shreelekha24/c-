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
TreeNode* solve(TreeNode* root,int data){
    if(root==NULL) return NULL;
    if(root->val==data) return root;
    TreeNode* give;
    if(root->val>data){
    give = solve(root->left,data);
    }
    else
    give = solve(root->right,data);
    return give;
}
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
        
    }
};