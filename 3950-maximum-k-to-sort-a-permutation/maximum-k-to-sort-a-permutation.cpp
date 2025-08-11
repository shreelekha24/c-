class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        long long ans=INT_MAX;
        int one=0;
        int maxi = INT_MAX;
    vector<bool> visited(nums.size(), false);

    for(auto it : m) {
        if(visited[it.first]) continue;
        if(it.first == it.second) continue;
        int cur = it.first;
        int x=cur;
        while(!visited[cur]) {
            visited[cur] = true;
            int next = m[cur];
            x=x&next;
            cur = next;
        }
        maxi=min(maxi,x);
         if(one==0)
        {
            ans=maxi;
            one++;
        }
        else
        ans=ans&maxi;
    }
    return ans==INT_MAX?0:ans;
    }
};