class Solution {
public:
int solve(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy){
        dp[i][buy]=max(-prices[i]+solve(prices,i+1,0,dp),solve(prices,i+1,1,dp));
    }else{
        dp[i][buy]=max(prices[i]+solve(prices,i+2,1,dp),solve(prices,i+1,0,dp));
    }
    return dp[i][buy];
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][buy]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};