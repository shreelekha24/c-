class Solution {
public:
int solve(string s,string t,int i ,int j,vector<vector<int>>&dp)
{
    if(i==0 || j==0)
    return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i-1]==t[j-1])
    return dp[i][j]=1+solve(s,t,i-1,j-1,dp);
    return dp[j][j]=max({solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp)});
}
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
      //  vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
      vector<int>dp(s.size()+1,0);
        for(int i=1;i<=s.size();i++){
            vector<int>temp(s.size()+1);
            for(int j=1;j<=s.size();j++){
                if(s[i-1]==t[j-1])
                temp[j]=1+dp[j-1];
                else
                temp[j]=max(dp[j],temp[j-1]);
            }
            dp=temp;
        }
        return s.size()-dp[s.size()];
    }
};