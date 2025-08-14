class Solution {
public:
    string largestGoodInteger(string num) {
        string s="";
        int maxi=INT_MIN;
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i]==num[i+1] && num[i+1]==num[i+2])
            {
                maxi=max(maxi,num[i+1]-'0');
            }
        }
        if(maxi==INT_MIN) return s;
        for(int i=0;i<3;i++)
        {
            s+=(maxi+'0');
        }
        return s;
    }
};