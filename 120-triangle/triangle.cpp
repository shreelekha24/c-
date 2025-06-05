class Solution {
public:
int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp)
{
    if(i==triangle.size() || j==triangle[i].size()){
       return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int one=triangle[i][j]+solve(triangle,i+1,j,dp);
    int two=triangle[i][j]+solve(triangle,i+1,j+1,dp);
    return dp[i][j]=min(one,two);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle.size()+1,-1));
       int count=solve(triangle,0,0,dp);
       return count; 
    }
};