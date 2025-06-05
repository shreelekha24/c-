class Solution {
public:
int solve(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&dp)
{
     if(i==m-1 && j==n-1)
     {
        if(grid[i][j]!=1)
        return 1; 
        return 0; 
     }
     if(i==m || j==n || grid[i][j]==1)
     return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     int down=solve(grid,i+1,j,m,n,dp);
     int right=solve(grid,i,j+1,m,n,dp);
     return dp[i][j]=down+right;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        //int count=solve(obstacleGrid,0,0,m,n,dp);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                dp[i][j]=0;
                else if(i==0 && j==0)
                dp[i][j]=1;
                else{ 
                int up=0,left=0;
                if(i>0)
                up=dp[i-1][j];
                if(j>0)
                left=dp[i][j-1];
                dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};