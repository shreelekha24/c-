class Solution {
public:
int solve(vector<int>&nums,int i,int target,vector<vector<int>>&dp,int total)
{
    if(i==0)
    {
        if(target-nums[i]==0 && target+nums[i]==0) return 2;
        if(target-nums[i]==0) return 1;
        if(target+nums[i]==0) return 1;
        return 0;
    }
    if (target + total < 0 || target + total >= dp[0].size()) return 0;
    if (dp[i][target + total] != -1) return dp[i][target + total];
    int take=0;
    take+=solve(nums,i-1,target-nums[i],dp,total);
    take+=solve(nums,i-1,target+nums[i],dp,total);
    return dp[i][target+total]=take;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=accumulate(nums.begin(),nums.end(),0);
       // vector<vector<int>>dp(nums.size(),vector<int>(2*total+1,0));
        if (abs(target) > total) return 0;
        //int cont=solve(nums,nums.size()-1,target,dp,total);
        vector<int>dp(2*total+1,0);
        if(nums[0]==0)
        dp[total]=2;
        else{ 
        dp[total-nums[0]]=1;
        dp[nums[0]+total]=1;
        }
        for(int i=1;i<nums.size();i++)
        {
            vector<int>temp(2*total+1);
            for(int j=-total;j<=abs(total);j++)
            {
                int take=0;
                if(j-nums[i]+total>=0 && j-nums[i]+total<2*total+1)
                take+=dp[j-nums[i]+total];
                if(j+nums[i]+total>=0 && j+nums[i]+total<2*total+1)
                take+=dp[j+nums[i]+total];
                temp[j+total]=take;
            }
            dp=temp;
        }
        return dp[target+total];
    }
};