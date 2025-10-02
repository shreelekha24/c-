class Solution {
public:
    long long splitArray(vector<int>& nums) {
        vector<int>increase,decrease;
        increase.push_back(0);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1]){
                increase.push_back(i);
            }
            else break;
        }
        decrease.push_back(nums.size()-1);
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1]) decrease.push_back(i);
            else break;
        }
        reverse(decrease.begin(),decrease.end());
        if(increase[increase.size()-1]!=decrease[0]){
            if(increase[increase.size()-1]==decrease[0]-1){ 
                long long left=0,right=0;
            for(int i=0;i<increase.size();i++) left+=nums[increase[i]];
        for(int i=0;i<decrease.size();i++) right+=nums[decrease[i]];
        return abs(right-left);}
        return -1;

        }
        if(decrease[0]==0)
        {
            long long left=nums[0],right=0;
            for(int i=1;i<decrease.size();i++) right+=nums[i];
            return abs(left-right);
        }
        if(increase[increase.size()-1]==nums.size()-1)
        {
            long long left=0,right=nums[nums.size()-1];
            for(int i=0;i<nums.size()-1;i++)
            {
                left+=nums[i];
            }
            return abs(left-right);
        }
        long long left=0,right=0;
        for(int i=0;i<increase.size();i++) left+=nums[increase[i]];
        for(int i=0;i<decrease.size();i++) right+=nums[decrease[i]];
        long long one=left-nums[increase[increase.size()-1]];
        long long two=right-nums[decrease[0]];
        return min(abs(one-right),abs(left-two));
    }
};