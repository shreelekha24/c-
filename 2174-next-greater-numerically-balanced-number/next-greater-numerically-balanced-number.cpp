class Solution {
public:
bool check(vector<int>&count)
{
    for(int i=1;i<=7;i++)
    {
        if(count[i]!=0 && count[i]!=i) return false;
    }
    return true;
}
void solve(vector<int>&v,vector<int>&total,int sum)
{
   if(sum>0 && check(total)) v.push_back(sum);
   if(sum>1224444) return ;
   for(int i=1;i<=7;i++)
   {
      if(total[i]<i)
      {
          total[i]++;
          solve(v,total,sum*10+i);
          total[i]--;
      }
   }
}
int nextBeautifulNumber(int n){ 
        vector<int>v;
        vector<int>total(10,0);
        solve(v,total,0);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>n) return v[i];
        }
        return -1;
    }
};