class Solution {
public:
int solve(string s,string t,int i,int j,vector<vector<int>>&dp){
    if(j==0) return 1;
    if(i==0){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int one=0;
    if(s[i-1]==t[j-1])
    one+=solve(s,t,i-1,j-1,dp);
    one+=solve(s,t,i-1,j,dp);
    return dp[i][j]=one;
}
    int numDistinct(string s, string t) {
        vector<vector<double>>dp(s.size()+1,vector<double>(t.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                double one=0,two=0;
                if(s[i-1]==t[j-1])
                one=dp[i-1][j-1];
                two=dp[i-1][j];
                dp[i][j]=(one+two);
            }
        }
        return (int)dp[s.size()][t.size()];
    }
};