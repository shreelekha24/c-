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
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=nums.size()-1;i>=0;i--){
            for(int count=i;count>=-1;count--){
                int one=0,two=0;
                two=dp[i+1][count+1];
               if (count==-1||nums[count]<nums[i]){ 
               two=max(two,1+dp[i+1][i+1]);
               } 
               dp[i][count+1]=two;
            }
        }
        return dp[0][0];
    }
};