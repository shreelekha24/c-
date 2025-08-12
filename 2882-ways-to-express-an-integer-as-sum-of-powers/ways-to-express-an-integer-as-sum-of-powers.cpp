class Solution {
public:
int mod=1e9+7;
long long intPow(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
int solve(long long total,int i,int p,int n,int x,vector<vector<int>>&dp)
{
    if(total==n)
    return 1;
    if(total>n || i>p) return 0;
    if(dp[i][total]!=-1) return dp[i][total];
    int one=solve(total+pow(i,x),i+1,p,n,x,dp);
    int two=solve(total,i+1,p,n,x,dp);
    return dp[i][total]=(one+two)%mod;
}
    int numberOfWays(int n, int x) {
        int p = 1;
        while (intPow(p, x) <= n) p++;
        p--;
        vector<vector<int>>dp(p+2,vector<int>(n+1,-1));
        int count=solve(0,1,p,n,x,dp);
        return count;
    }
};