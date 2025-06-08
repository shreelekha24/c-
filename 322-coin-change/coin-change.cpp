class Solution {
public:
int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp)
{
    if(i==coins.size()-1)
    {
        if(amount%coins[i]==0) return amount/coins[0];
        else return INT_MAX;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int one=INT_MAX;
    if(coins[i]<=amount)
    {
       one= 1+solve(coins,amount-coins[i],i,dp);
    }
    int two=solve(coins,amount,i+1,dp);
    return dp[i][amount]=min(one,two);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        int n=coins.size();
      //  int count=solve(coins,amount,0,dp);
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[n-1]==0) dp[n-1][i]=i/coins[n-1];
            else dp[n-1][i]=INT_MAX;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=1;j<=amount;j++)
            {
               int one=INT_MAX;
               if(coins[i]<=j && dp[i][j-coins[i]]!=INT_MAX)
               {
                one=dp[i][j-coins[i]]+1;
                }
                int two=dp[i+1][j];
                dp[i][j]=min(one,two);

            }
        }
        return dp[0][amount]==INT_MAX?-1:dp[0][amount];
    }
};