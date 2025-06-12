class Solution {
public:
int solve(vector<int>& prices,int count,int i,int k,vector<vector<int>>&dp){
    if(i==prices.size() || count==2*k) return 0;
    if(dp[i][count]!=-1) return dp[i][count];
    if(count%2==0){
        dp[i][count]=max({-prices[i]+solve(prices,count+1,i+1,k,dp),solve(prices,count,i+1,k,dp)});
    }
    else
    {
        dp[i][count]=max({prices[i]+solve(prices,count+1,i+1,k,dp),solve(prices,count,i+1,k,dp)});
    }
    return dp[i][count];
}
    int maxProfit(int k, vector<int>& prices) {
       // vector<vector<int>>dp(prices.size()+1,vector<int>(2*k+1,0));
       vector<int>dp(2*k+1,0);
        for(int i=prices.size()-1;i>=0;i--){
            vector<int>temp(2*k+1,0);
            for(int count=2*k-1;count>=0;count--){
                if(count%2==0){
                temp[count]=max({-prices[i]+dp[count+1],dp[count]});
                }
                else
                {
                temp[count]=max({prices[i]+dp[count+1],dp[count]});
                }
            }
            dp=temp;
        }
        return dp[0];
    }
};