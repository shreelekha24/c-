class Solution {
public:
int solve(vector<vector<int>>&matrix,int i,int j, int n,vector<vector<int>>&dp)
{
    if(j==n || j==-1)
    return 1e9;
    if(i==n-1)
    return matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int one=matrix[i][j]+solve(matrix,i+1,j,n,dp);
    int three=matrix[i][j]+solve(matrix,i+1,j-1,n,dp);
    int two=matrix[i][j]+solve(matrix,i+1,j+1,n,dp);
    return dp[i][j]=min({one,two,three});
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int sum=INT_MAX;
        vector<int>dp(n);
       /* for(int i=0;i<matrix.size();i++)
        {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int count=solve(matrix,0,i,n,dp);
        sum=min(sum,count);
        }*/
        dp=matrix[0];
        for(int i=1;i<n;i++)
        {
            vector<int>temp(n);
            for(int j=0;j<n;j++)
            {
                int one=INT_MAX,two=INT_MAX,three=INT_MAX;
                if(j>0)
                one=matrix[i][j]+dp[j-1];
                if(j<n-1)
                two=matrix[i][j]+dp[j+1];
                three=matrix[i][j]+dp[j];
                temp[j]=min({one,two,three});
            }
            dp=temp;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        ans=min(ans,dp[i]);
        return ans;
    }
};