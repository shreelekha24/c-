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
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        int count=0;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            count+=s;
            for(int i=0;i<s;i++)
            {
                TreeNode* current=q.front();
                q.pop();
                if(current->left)
                q.push(current->left);
                if(current->right)
                q.push(current->right);
            }
        }
        return count;
    }
};