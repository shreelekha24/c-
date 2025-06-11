class Solution {
public:
int solve(string word1,string word2,int i,int j,vector<vector<int>>&dp)
{
    if(i==word1.size())
    return word2.size()-j;
    if(j==word2.size())
    return word1.size()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    int one=0,two=0,three=0,four=0;
    if(word1[i]==word2[j])
    {
         return dp[i][j]=solve(word1,word2,i+1,j+1,dp);
    }
       return dp[i][j]=min({1+solve(word1,word2,i+1,j+1,dp),1+solve(word1,word2,i,j+1,dp),1+solve(word1,word2,i+1,j,dp)});
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};