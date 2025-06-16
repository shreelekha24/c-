class Solution {
public:
int solve(vector<int>&arr,int i,int k,vector<int>&dp)
{
    if(i==arr.size())
    return 0;
    if(dp[i]!=-1) return dp[i];
    int maxi=INT_MIN;
    int sum=INT_MIN;
    int count=0;
    for(int j=i;j<arr.size();j++)
    {
        maxi=max(maxi,arr[j]);
        if(j-i+1<=k)
        {
            
          count=(j-i+1)*maxi+solve(arr,j+1,k,dp);
          sum=max(sum,count);
        }
    }
    return dp[i]=sum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
        return solve(arr,0,k,dp);
    }
};