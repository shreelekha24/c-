class Solution {
public:
int solve(vector<vector<int>>&grid,int i,int j,int m,int n,int last,vector<vector<vector<int>>>&dp)
{
    if(j>=n || j<0 || last>=n || last<0)
    return 0;
    if(i==m-1){ 
        if(j==last)
    return grid[i][j];
    else
    return grid[i][j]+grid[i][last];
    }
    if(dp[i][j][last]!=-1) return dp[i][j][last];
    int ld1=0,ld2=0,ld3=0,one1=0,one2=0,one3=0,rd1=0,rd2=0,rd3=0;
    if(j==last)
    {
    ld1=grid[i][j]+solve(grid,i+1,j-1,m,n,last-1,dp);
    ld2=grid[i][j]+solve(grid,i+1,j-1,m,n,last,dp);
    ld3=grid[i][j]+solve(grid,i+1,j-1,m,n,last+1,dp);
    one1=grid[i][j]+solve(grid,i+1,j,m,n,last-1,dp);
    one2=grid[i][j]+solve(grid,i+1,j,m,n,last,dp);
    one3=grid[i][j]+solve(grid,i+1,j,m,n,last+1,dp);
    rd1=grid[i][j]+solve(grid,i+1,j+1,m,n,last-1,dp);
    rd2=grid[i][j]+solve(grid,i+1,j+1,m,n,last,dp);
    rd3=grid[i][j]+solve(grid,i+1,j+1,m,n,last+1,dp);
    }else{ 
    ld1=grid[i][j]+grid[i][last]+solve(grid,i+1,j-1,m,n,last-1,dp);
    ld2=grid[i][j]+grid[i][last]+solve(grid,i+1,j-1,m,n,last,dp);
    ld3=grid[i][j]+grid[i][last]+solve(grid,i+1,j-1,m,n,last+1,dp);
    one1=grid[i][j]+grid[i][last]+solve(grid,i+1,j,m,n,last-1,dp);
    one2=grid[i][j]+grid[i][last]+solve(grid,i+1,j,m,n,last,dp);
    one3=grid[i][j]+grid[i][last]+solve(grid,i+1,j,m,n,last+1,dp);
    rd1=grid[i][j]+grid[i][last]+solve(grid,i+1,j+1,m,n,last-1,dp);
    rd2=grid[i][j]+grid[i][last]+solve(grid,i+1,j+1,m,n,last,dp);
    rd3=grid[i][j]+grid[i][last]+solve(grid,i+1,j+1,m,n,last+1,dp);
    }
    int ld=max({ld1,ld2,ld3});
    int one=max({one1,one2,one3});
    int rd=max({rd1,rd2,rd3});
    return dp[i][j][last]=max({ld,one,rd});
}
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        int count=solve(grid,0,0,m,n,n-1,dp);
        return count;
    }
};