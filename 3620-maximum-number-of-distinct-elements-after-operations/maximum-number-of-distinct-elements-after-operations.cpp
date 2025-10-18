class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0,prev=-1e9;
        for(int i=0;i<nums.size();i++)
        {
            int low=nums[i]-k;
            int high=nums[i]+k;
            int x=prev+1;
            if(x<low) x=low;
            if(x<=high) {
                count++;
                prev=x;
            }
        }
        return count;
    }
};