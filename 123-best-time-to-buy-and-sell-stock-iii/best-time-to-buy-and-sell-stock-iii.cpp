class Solution {
public:
int solve(vector<int>&prices,int i,int buy,int count,vector<vector<vector<int>>>&dp){
    if(i==prices.size() || count==4) return 0;
    if(dp[i][buy][count]!=-1) return dp[i][buy][count];
    if(buy){
     dp[i][buy][count]=max({-prices[i]+solve(prices,i+1,0,count+1,dp),solve(prices,i+1,1,count,dp)});
    }
    else{
        dp[i][buy][count]=max({prices[i]+solve(prices,i+1,1,count+1,dp),solve(prices,i+1,0,count,dp)});
    }
    return dp[i][buy][count];
}
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1, vector<vector<int>>(2, vector<int>(5, 0)));
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                for(int count=3;count>=0;count--){
                    if(buy){
                    int take = (count + 1 <= 4) ? -prices[i] + dp[i + 1][0][count + 1] : 0;
                    int skip = dp[i + 1][1][count];
                    dp[i][buy][count] = max(take, skip);
                    }
                else{
                   int sell = (count + 1 <= 4) ? prices[i] + dp[i + 1][1][count + 1] : 0;
                    int skip = dp[i + 1][0][count];
                    dp[i][buy][count] = max(sell, skip);
                } 
                }
            }
        }
        return dp[0][1][0];
    }
};