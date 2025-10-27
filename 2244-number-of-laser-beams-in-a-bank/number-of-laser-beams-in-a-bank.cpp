class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count=0;
        vector<int>v(bank.size());
        for(int i=0;i<bank.size();i++)
        {
            int one=0;
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1') one++;
            }
            v[i]=one;
        }
        int i=0;
        while(i<v.size())
        {
            if(v[i]==0){
                i++;
                continue;
            }
            int temp=i+1;
            while(temp<bank.size() && v[temp]==0)
            {
                temp++;
            }
            if(temp<bank.size())
            count+=v[i]*v[temp];
            i=temp;
        }
        return count;
    }
};