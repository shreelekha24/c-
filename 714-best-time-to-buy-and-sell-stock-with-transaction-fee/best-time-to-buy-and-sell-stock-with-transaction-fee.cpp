class Solution {
public:
int solve(vector<int>& prices, int fee,int i,int buy,vector<vector<int>>&dp){
    if(i==prices.size()) return 0;
    int profit=0;
    if(dp[i][buy]!=-1)
    return dp[i][buy];
    if(buy){
       dp[i][buy]=max(-prices[i]+solve(prices,fee,i+1,0,dp),solve(prices,fee,i+1,1,dp));
    }
    else{
        dp[i][buy]=max(prices[i]-fee+solve(prices,fee,i+1,1,dp),solve(prices,fee,i+1,0,dp));
    }
    return dp[i][buy];
}
    int maxProfit(vector<int>& prices, int fee) {
       vector<int>dp(2,0),temp(2,0);
        for(int i=prices.size()-1;i>=0;i--){
            temp[1]=max(-prices[i]+dp[0],dp[1]);
            temp[0]=max(prices[i]-fee+dp[1],dp[0]);
            dp=temp;
        }
        return temp[1];
    }
};