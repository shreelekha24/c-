class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2)
        {
           string t="";
           for(int i=0;i<s.size()-1;i++)
           {
               char c=(((s[i]-'0')+(s[i+1]-'0'))%10)+'0';
               t+=c;
           }
           s=t;
        }
        if(s[0]==s[1]) return true;
        return false;
    }
};