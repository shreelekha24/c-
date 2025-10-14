class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        set<int>v;
        for(int i=0;i<=nums.size()-k;i++)
        {
            int p=nums[i];
            bool yes=true;
            for(int j=i+1;j<i+k;j++)
            {
                if(nums[j]>p)
                {
                    p=nums[j];
                }
                else{
                    yes=false;
                    break;
                }
            }
            if(yes) {
                v.insert(i);
            }
        }
        for(auto it:v)
        {
            if(v.find(it+k)!=v.end()) return true;
        }
        return false;
    }
};