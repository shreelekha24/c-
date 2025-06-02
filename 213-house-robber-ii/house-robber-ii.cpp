class Solution {
public:
int solve(vector<int>&nums,int n,int i,vector<int>&dp)
{
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int money=nums[i]+solve(nums,n,i+2,dp);   
    int skip=solve(nums,n,i+1,dp);
    return dp[i]=max(money,skip);
}
int rob(vector<int>& nums) {
    if(nums.size()==1)
    return nums[0];
        int n=nums.size();
        vector<int>dp(n,-1);
        int count=solve(nums,n-1,0,dp);
        vector<int>dp1(n,-1);
        int count1=solve(nums,n,1,dp1);
        return max(count,count1);
    }
};