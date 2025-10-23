class Solution {
public:
    string countAndSay(int n) {
        string s="";
        string temp="";
        temp+='1';
        if(n==1) return temp;
        for(int i=2;i<=n;i++)
        {
            s=temp;
            temp.clear();
            char c=s[0];
            int count=1;
            for(int j=1;j<s.size();j++)
            {
                if(s[j]==c)
                {
                    count++;
                }
                else{
                    temp+=(count+'0');
                    temp+=c;
                    count=1;
                    c=s[j];
                }
            }
            temp+=(count+'0');
            temp+=c;
        }
        s=temp;
        return s;
    }
};