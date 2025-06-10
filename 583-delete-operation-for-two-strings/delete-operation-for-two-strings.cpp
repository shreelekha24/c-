class Solution {
public:
int solve(string word1,string word2,int i,int j,vector<vector<int>>&dp){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i-1]==word2[j-1]) return 1+solve(word1,word2,i-1,j-1,dp);
    return dp[i][j]=max(solve(word1,word2,i-1,j,dp),solve(word1,word2,i,j-1,dp));
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return word1.size()+word2.size()-2*solve(word1,word2,word1.size(),word2.size(),dp);
    }
};