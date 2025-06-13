class Solution {
public:
int solve(vector<int>&nums,int count,int i,vector<vector<int>>&dp)
{
    if(i==nums.size()) return 0;
    if(dp[i][count+1]!=-1) return dp[i][count+1];
    int one=0,two=0;
    two=solve(nums,count,i+1,dp);
    if (count==-1||nums[count]<nums[i]){ 
     count=i;
     two=max(two,1+solve(nums,count,i+1,dp));
    } 
    return dp[i][count+1]=two;
}
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[j]<nums[i])
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        ans=max(ans,dp[i]);
        return ans;
    }
};