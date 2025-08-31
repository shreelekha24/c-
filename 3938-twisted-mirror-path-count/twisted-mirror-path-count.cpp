class Solution {
public:
int mod = 1e9+7;

int solve(int i,int j,vector<vector<int>>&grid,int m,int n,vector<vector<int>>&dp)
{
    if(i>=m || j>=n) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int down=0, right=0;

    { 
        int row=i+1, col=j;
        int dir=0;
        while(row<m && col<n && grid[row][col]==1)
        {
            if(dir==0) col++, dir=1;
            else row++, dir=0;
        }
        if(row<m && col<n)
            down=(down+solve(row,col,grid,m,n,dp))%mod;
    }

    { 
        int row=i, col=j+1;
        int dir=0;
        while(row<m && col<n && grid[row][col]==1)
        {
            if(dir==0) row++, dir=1;
            else col++, dir=0;
        }
        if(row<m && col<n)
            right=(right+solve(row,col,grid,m,n,dp))%mod;  
    }

    return dp[i][j]=(down+right)%mod;
}

int uniquePaths(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(0,0,grid,m,n,dp);
}

};