class Solution {
public:
vector<int>solve(vector<int>&nums,int prev,int i,vector<vector<int>>&dp)
{
    if(i==nums.size()) return {};
   // if(dp[i][prev+1]!=-1) return dp[i][prev];
    vector<int>d;
    if(prev==-1 || nums[i]%nums[prev]==0){
        d=solve(nums,i,i+1,dp);
        d.insert(d.begin(),nums[i]);
    }
    vector<int>e=solve(nums,prev,i+1,dp);
    return d.size()>e.size()?d:e;
} 
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //vector<vector<int>>dp(nums.begin()+1,vector<int>(nums.begin()+1,-1));
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size()+1,1);
        vector<int>hash(nums.size()+1);
        int last=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
               if(nums[i]%nums[j]==0 && dp[i]<1+dp[j])
               {
                dp[i]=1+dp[j];
                hash[i]=j;
               }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[last]);
        while(hash[last]!=last) // if(barabar ho jaye toh 0 pahunch gaya hai)
        {
            last=hash[last];
            temp.push_back(nums[last]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};