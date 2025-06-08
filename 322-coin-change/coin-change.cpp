class Solution {
public:
int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp)
{
    if(amount==0) return 0;
    if(i==coins.size())
    {
        if(amount==0) return 0;
        else return INT_MAX;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int one=INT_MAX;
    if(coins[i]<=amount)
    {
        int res=solve(coins,amount-coins[i],i,dp);
        if(res!=INT_MAX) one=res+1;
    }
    int two=solve(coins,amount,i+1,dp);
    return dp[i][amount]=min(one,two);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int count=solve(coins,amount,0,dp);
        //dp[0][0]=1;
        /*for(int i=1;i<coins.size();i++)
        {
            for(int j=1;j<)
        }*/
        return count==INT_MAX?-1:count;
    }
};