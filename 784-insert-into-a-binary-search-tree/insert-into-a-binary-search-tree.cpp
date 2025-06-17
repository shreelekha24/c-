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
void solve(TreeNode* root,int val)
{
    if(root->val>val){
        if(root->left!=NULL){
          solve(root->left,val);
        }
        else{
            TreeNode* t=new TreeNode(val);
            TreeNode* p=root->left;
            root->left=t;
            root->left->left=p;
            return;
        }
    }
    else{
        if(root->right!=NULL){
            solve(root->right,val);
        }
        else{
            TreeNode* t=new TreeNode(val);
            TreeNode* p=root->right;
            root->right=t;
            root->right->right=p;
            return;
        }
    }
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* t=new TreeNode(val);
            root=t;
            return root;
        }
        solve(root,val);
        return root;
    }
};