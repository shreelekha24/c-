class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>v;
        map<int,int>m;
        for(int i=0;i<friends.size();i++)
        {
            m[friends[i]]++;
        }
        for(int i=0;i<order.size();i++)
        {
            if(m.find(order[i])!=m.end())
            v.push_back(order[i]);
        }
        return v;
    }
};