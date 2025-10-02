class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int i=0;
        int temp=n;
        vector<int>v;
        while(temp)
        {
            int p=temp%10;
            if(p!=0)
            v.push_back(p*pow(10,i));
            i++;
            temp/=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};