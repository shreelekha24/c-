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
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>temp.back())
            temp.push_back(nums[i]);
            else{
                auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
                *it=nums[i];
            }
        }
        return temp.size();
    }
};