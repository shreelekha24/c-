class Solution {
public:
int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>v;
        int temp=n;
        while(temp)
        {
            int x=31-__builtin_clz(temp);
            v.push_back(1ll<<x);
            temp-=1ll<<x;
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            long long pro=1;
            for(int j=queries[i][0];j<=queries[i][1];j++)
            {
                pro=(pro*v[j])%mod;
            }
            ans.push_back(pro);
        }
        return ans;

    }
};