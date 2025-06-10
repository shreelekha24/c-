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
      //  vector<vector<double>>dp(s.size()+1,vector<double>(t.size()+1,0));
      vector<double>dp(t.size()+1,0),temp(t.size()+1);
            dp[0]=1,temp[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                double one=0,two=0;
                if(s[i-1]==t[j-1])
                one=dp[j-1];
                two=dp[j];
                temp[j]=(one+two);
            }
            dp=temp;
        }
        return (int)dp[t.size()];
    }
};