class Solution {
public:
int mod=1e9+7;
int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp)
{
    if(i==0)
    {
        if(amount%coins[i]==0) return 1;
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int take=0;
    if(coins[i]<=amount)
    take+=solve(coins,amount-coins[i],i,dp);
    take+=solve(coins,amount,i-1,dp);
    return dp[i][amount]=take;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
    //    int count=solve(coins,amount,coins.size()-1,dp);
        for (int i = 0; i < coins.size(); i++) dp[i][0] = 1;
        for(int i=1;i<=amount;i++)
        {
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                long long take = 0, notTake = dp[i - 1][j];
            if (coins[i] <= j)
                take = dp[i][j - coins[i]];
            dp[i][j] = static_cast<int>(take + notTake);
            }
        }
        return dp[coins.size()-1][amount];
    }
};