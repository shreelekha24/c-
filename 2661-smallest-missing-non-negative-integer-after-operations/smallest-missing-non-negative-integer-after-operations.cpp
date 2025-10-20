class Solution {
public:
	int findSmallestInteger(vector<int>& nums, int v) {
        map<int,int>m;
		for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                int p=abs(nums[i])/v;
                nums[i]+=(p+1)*v;
            }
            nums[i]=nums[i]%v;
            m[nums[i]]++;
        }
        int i=0;
        while(true)
        {
            int p=i%v;
            if(m[p]==0)break;
            m[p]--;
            i++;
        }
        return i;
	}
};