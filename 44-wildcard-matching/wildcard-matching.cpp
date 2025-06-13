class Solution {
public:
bool solve(string s, string p,int i,int j,vector<vector<int>>&dp)
{
    if(j==0 && i==0) return true;
    if(j==0 && i>0)
    return false;
    if(i==0 && j>0){
        for(int k=1;k<=j;k++)
        {
            if(p[k-1]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i-1]==p[j-1] || p[j-1]=='?'){
        return dp[i][j]=solve(s,p,i-1,j-1,dp);
    }
    else if(p[j-1]=='*')
    {
        return dp[i][j]=solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp) ;
    }
    return dp[i][j]=false;
}
    bool isMatch(string s, string p) {
      //  vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1,false));
      vector<bool>dp(p.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=p.size();i++){
            bool flag=true;
            for(int k=1;k<=i;k++)
        {
            if(p[k-1]!='*'){
                flag=false;
                break;
            }
        }
        dp[i]=flag;
        }
        for(int i=1;i<=s.size();i++){
            vector<bool>temp(p.size()+1);
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                temp[j]=dp[j-1];
                }
                else if(p[j-1]=='*')
                {
                temp[j]=dp[j] || temp[j-1] ;
                }
                else
                temp[j]=false;
            }
            dp=temp;
        }
        return dp[p.size()];
    }
};