class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> ans;
    bool rev = true;

    // Total diagonals = m + n - 1
    for (int d = 0; d < m + n - 1; d++) {
        vector<int> temp;
        
        // starting row for this diagonal
        int r = (d < n ? 0 : d - n + 1);
        // starting col for this diagonal
        int c = (d < n ? d : n - 1);

        while (r < m && c >= 0) {
            temp.push_back(mat[r][c]);
            r++;
            c--;
        }
        
        if (rev) reverse(temp.begin(), temp.end());
        rev = !rev;

        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}

};