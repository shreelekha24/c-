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
TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int start,int end,unordered_map<int,int>& m,int& post)
{
    if(start>end)
    return NULL;
    int rootVal=postorder[post++];
    TreeNode* root=new TreeNode(rootVal);
    int e=m[rootVal];
    root->right=solve(inorder,postorder,e+1,end,m,post);
    root->left=solve(inorder,postorder,start,e-1,m,post);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        int post=0;
        reverse(postorder.begin(),postorder.end());
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        return solve(inorder,postorder,0,inorder.size()-1,m,post);
    }
};