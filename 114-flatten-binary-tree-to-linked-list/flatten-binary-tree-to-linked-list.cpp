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
void solve(TreeNode* root,vector<int>&v)
{
    if(root==NULL)
    return;
    v.push_back(root->val);
    solve(root->left,v);
    solve(root->right,v);
}
TreeNode* build(vector<int>&pre,int& i)
{ 
    if(i>=pre.size()) return nullptr;
    TreeNode* link=new TreeNode(pre[i++]);
    link->left=NULL;
    link->right=build(pre,i);
    return link;
}

void flatten(TreeNode* root) {
    if(root==NULL)
    return;
    vector<int>pre;
    solve(root,pre);
    int i=0;
    TreeNode* newRoot=build(pre,i);
    root->left = NULL;
    root->right = newRoot->right;
    root->val = newRoot->val;
    }
};