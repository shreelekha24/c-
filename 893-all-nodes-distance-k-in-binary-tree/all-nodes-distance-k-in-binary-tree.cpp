/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void solve(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        for(int i=0;i<s;i++)
        {
            TreeNode* current=q.front();
            q.pop();
            if(current->left)
            {
                q.push(current->left);
                parent[current->left]=current;
            }
            if(current->right)
            {
                q.push(current->right);
                parent[current->right]=current;
            }
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        solve(root,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty())
        {
            int s=q.size();
            if(level==k)
            break;
            level++;
            for(int i=0;i<s;i++)
            {
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent[current] && !visited[parent[current]])
                {
                    q.push(parent[current]);
                    visited[parent[current]]=true;
                }
            }
        }
        vector<int>v;
        while(!q.empty())
        {
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
    }
};