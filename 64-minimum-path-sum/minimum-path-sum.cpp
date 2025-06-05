class Solution {
public:
int solve(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&dp)
{
    if(i==m-1 && j==n-1)
    {
        return grid[i][j];
    }
    if(i==m || j==n)
    return 1000000000;
    if(dp[i][j]!=-1) return dp[i][j];
    int down=grid[i][j]+solve(grid,i+1,j,m,n,dp);
    int right=grid[i][j]+solve(grid,i,j+1,m,n,dp);
    return dp[i][j]=min(down,right);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
     //   int count=solve(grid,0,0,m,n,dp);
        dp[0][0]=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                  if(i==0 && j==0)
                  dp[0][0]=grid[0][0];
                  else{
                    int down=INT_MAX,left=INT_MAX;
                    if(i>0)
                    down=grid[i][j]+dp[i-1][j];
                    if(j>0)  left=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(down,left);
                  }
            }
        }
        return dp[m-1][n-1];
    }
};