class Solution {
public:
int solve(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
    if(i==prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit=0;
    if(buy){
        dp[i][buy]=max(-prices[i]+solve(prices,i+1,0,dp),solve(prices,i+1,1,dp));
    }
    else{
        dp[i][buy]=max(prices[i]+solve(prices,i+1,1,dp),solve(prices,i+1,0,dp));
    }
    return dp[i][buy];
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};