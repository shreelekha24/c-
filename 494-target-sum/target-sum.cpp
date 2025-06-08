class Solution {
public:
int solve(vector<int>&nums,int i,int target)
{
    if(i==0)
    {
        if(target-nums[i]==0 && target+nums[i]==0) return 2;
        if(target-nums[i]==0) return 1;
        if(target+nums[i]==0) return 1;
        return 0;
    }
    int take=0;
    take+=solve(nums,i-1,target-nums[i]);
    take+=solve(nums,i-1,target+nums[i]);
    return take;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int cont=solve(nums,nums.size()-1,target);
        return cont;
    }
};