class Solution {
public:
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
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int count=solve(coins,amount,coins.size()-1,dp);
        return count;
    }
};