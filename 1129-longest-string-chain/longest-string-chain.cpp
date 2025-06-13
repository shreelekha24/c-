class Solution {
public:
int solve(vector<string>&words,int prev,int i,vector<vector<int>>&dp)
{
    if(i==words.size())
        return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int two = solve(words, prev, i + 1,dp);
    int one =0;
    if(prev == -1 || words[prev].size() < words[i].size())
    {
        bool yes = true;
        if(prev > -1)
        { 
            string s = words[i];
            yes = false;
            for(int j = 0; j < words[i].size(); j++)
            {
                string temp = s;
                temp.erase(j, 1); // FIX HERE
                if(temp == words[prev])
                {
                    yes = true;
                    break;
                }
            }
        }
        if(yes)
            one = 1 + solve(words, i, i + 1,dp);
    }
    return dp[i][prev+1]=max(one,two);
}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
});
    vector<vector<int>>dp(words.size()+1,vector<int>(words.size()+1,0));
        for(int i=words.size()-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int one=0,two=0;
                two=dp[i+1][prev+1];
               if(prev == -1 || words[prev].size() < words[i].size())
               {
                  bool yes = true;
                  if(prev > -1)
                  { 
                   string s = words[i];
                   yes = false;
                   for(int j = 0; j < words[i].size(); j++)
                    {
                     string temp = s;
                       temp.erase(j, 1); // FIX HERE
                       if(temp == words[prev])
                       {
                        yes = true;
                        break;
                       }
                    }
                }
                if(yes)
                 one =  1 + dp[i+1][i + 1];
               }
               dp[i][prev+1]=max(one,two);
            }
        }
        return dp[0][0];
}
};