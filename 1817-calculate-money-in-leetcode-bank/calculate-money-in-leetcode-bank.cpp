class Solution {
public:
    int totalMoney(int n) {
        int q=n/7;
        int p=n%7;
        long long sum=0;
        int week=7;
        for(int i=1;i<=q;i++)
        {
            sum+=(week)*(week+1)/2;
            sum-=(i)*(i-1)/2;
            week++;
        }
        int t=1+q;
        for(int i=1;i<=p;i++)
        {
            sum+=t;
            t++;
        }
        return sum;
    }
};