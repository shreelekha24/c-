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
        if (total % 2 != 0) return false;
        int target=total/2;
        long long sum=0;
        //vector<vector<bool>>dp(nums.size()+1,vector<bool>(target+1,false));
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int i=1;i<=nums.size();i++)
        {
            vector<bool>temp(target+1);
            for(int j=1;j<=target;j++)
            {
                bool one=false;
                if(j>=nums[i-1])
                one=dp[j-nums[i-1]];
                bool two=dp[j];
                temp[j]=one||two;
            }
            dp=temp;
        }
        return dp[target];
    }
};