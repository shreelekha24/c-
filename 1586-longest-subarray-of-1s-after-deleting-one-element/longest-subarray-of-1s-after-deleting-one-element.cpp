class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    vector<int> v;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
            v.push_back(i);
    }

    if(v.size()==0) 
    {
        return nums.size()-1;
    }

    int maxi=0;

    for(int i=0;i<v.size();i++)
    {
        if(i>0)
        {
            if(i<v.size()-1)
            {
                maxi = max(maxi, v[i+1] - v[i-1] - 2);
            }
            else 
            {
                maxi = max(maxi, (int)nums.size() - v[i-1] - 2);
            }
        }
        else
        { 
            if(i<v.size()-1)
            {
                maxi = max(maxi, v[i+1]-1);
            }
            else
            {
                maxi = max(maxi, (int)nums.size()-1);
            }
        }
    }
    return maxi;
}

};