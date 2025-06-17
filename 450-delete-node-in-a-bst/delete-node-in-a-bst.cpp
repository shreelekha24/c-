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
void solve(TreeNode* root,int key)
{
    if(root==NULL) return;
    if(root->left && root->left->val==key)
    {
        if(root->left->right)
                {
                    TreeNode* t=root->left->right;
                    TreeNode* temp=t;
                    while(temp->left) temp=temp->left;
                    temp->left=root->left->left;
                    root->left=t;
                }
                else{
                    TreeNode* t=root->left->left;
                    root->left=t;
                }
        return;
    }
    if(root->right && root->right->val==key) { 
                if(root->right->right){ 
               TreeNode *t=root->right->right;
               TreeNode* temp=t;
               while(temp->left) temp=temp->left;
               temp->left=root->right->left;
               root->right=t;
                }
                else{
                    TreeNode* t=root->right->left;
                    root->right=t;
                }
            return;
}
    if(root->val>key) solve(root->left,key);
    else solve(root->right,key);
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) {
            if(root->right){
                TreeNode* t=root->right;
                TreeNode* temp=t;
                while(temp->left)temp=temp->left;
                temp->left=root->left;
                return t;
            }
            else
            {
                TreeNode* t=root->left;
                return t;
            }
        }
      solve(root,key);
      return root;
    }
};