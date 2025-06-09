class Solution {
public:
int solve(string text1, string text2,string s, string t,int i,int j,vector<vector<int>>&dp)
{
    if(i==text1.size() || j==text2.size())
    {
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(text1[i]==text2[j])
    return 1+solve(text1,text2,s,t,i+1,j+1,dp);
    return dp[i][j]=max(solve(text1,text2,s,t,i+1,j,dp),solve(text1,text2,s,t,i,j+1,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        string s="",t="";
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0)); //shifting of index by 1
        for(int i=0;i<=text2.size();i++){
            if(text1[0]==text2[i])
            dp[0][i]=0;
        }
        for(int i=0;i<=text1.size();i++){
            if(text2[0]==text1[i])
            dp[i][0]=0;
        }
        for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            int one=INT_MIN,two=INT_MIN;
          if(text1[i-1]==text2[j-1])
          one=1+dp[i-1][j-1];
          else
          two=max(dp[i-1][j],dp[i][j-1]);
          dp[i][j]=max(one,two);
        }
      //  int count=solve(text1,text2,s,t,0,0,dp);
    }
      return dp[text1.size()][text2.size()];
    }
};