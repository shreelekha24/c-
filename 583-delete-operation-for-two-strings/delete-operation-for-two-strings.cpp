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
       // vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
       vector<int>dp(word2.size()+1,0);
        for(int i=1;i<=word1.size();i++){
            vector<int>temp(word2.size()+1);
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1]) temp[j]=1+dp[j-1];
                else temp[j]=max(dp[j],temp[j-1]);
            }
            dp=temp;
        }
        return word1.size()+word2.size()-2*dp[word2.size()];
    }
};