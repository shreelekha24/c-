class Solution {
public:
string shortestCommonSupersequence(string str1, string str2) {
    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0)); //shifting of index by 1
        for(int i=1;i<=str1.size();i++){
        for(int j=1;j<=str2.size();j++){
            int one=INT_MIN,two=INT_MIN;
          if(str1[i-1]==str2[j-1])
          one=1+dp[i-1][j-1];
          else
          two=max(dp[i-1][j],dp[i][j-1]);
          dp[i][j]=max(one,two);
        }
    }
    int i=str1.size(),j=str2.size();
    string t="";
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            t+=str1[i-1];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            t+=str1[i-1];
            i--;
        }
        else{
            t+=str2[j-1];
            j--;
        }
    }
        while(i>0){
            t+=str1[i-1];
            i--;
        }

        while(j>0){
            t+=str2[j-1];
            j--;
        }
    reverse(t.begin(),t.end());
    return t;
    }
};