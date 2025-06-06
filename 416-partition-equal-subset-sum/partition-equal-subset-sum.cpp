class Solution {
public:
bool solve(vector<int>&nums,int i,long long sum,long long total,vector<vector<long long>>&dp)
{
    if(sum==total-sum)
    return true;
    if(i==nums.size()){
        return (sum==total-sum);
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool one=solve(nums,i+1,sum+nums[i],total,dp);
    bool two=solve(nums,i+1,sum,total,dp);
    return dp[i][sum]=one||two;
    
}
    bool canPartition(vector<int>& nums) {
        long long total=accumulate(nums.begin(),nums.end(),0);
        long long sum=0;
        vector<vector<long long>>dp(nums.size()+1,vector<long long>(total+1,-1));
        return solve(nums,0,sum,total,dp);
    }
};