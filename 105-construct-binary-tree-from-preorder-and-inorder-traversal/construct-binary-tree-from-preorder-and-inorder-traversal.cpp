class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int,int>& m, int& pre) {
        if (start > end)
            return nullptr;

        int rootVal = preorder[pre++];
        TreeNode* root = new TreeNode(rootVal);

        if (start == end)
            return root;

        int e = m[rootVal];
        root->left = solve(preorder, inorder, start, e - 1, m, pre);
        root->right = solve(preorder, inorder, e + 1, end, m, pre);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        int pre = 0;

        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, inorder.size() - 1, m, pre);
    }
};
