class Solution {
public:
int solve(string word1,string word2,int i,int j,vector<vector<int>>&dp)
{
    if(i==word1.size())
    return word2.size()-j;
    if(j==word2.size())
    return word1.size()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i]==word2[j])
    {
         return dp[i][j]=solve(word1,word2,i+1,j+1,dp);
    }
       return dp[i][j]=min({1+solve(word1,word2,i+1,j+1,dp),1+solve(word1,word2,i,j+1,dp),1+solve(word1,word2,i+1,j,dp)});
}
    int minDistance(string word1, string word2) {
       // vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
       vector<int>dp(word2.size()+1,0);
        for(int i=0;i<=word2.size();i++)
        {
            dp[i]=i;
        }
        for(int i=1;i<=word1.size();i++)
        {
            vector<int>temp(word2.size()+1);
            temp[0]=i;
            for(int j=1;j<=word2.size();j++)
            { 
                if(word1[i-1]==word2[j-1])
                 temp[j]=dp[j-1];
                else
                temp[j]=min({1+dp[j-1],1+temp[j-1],1+dp[j]});
           }
           dp=temp;
        }
        return dp[word2.size()];
    }
};