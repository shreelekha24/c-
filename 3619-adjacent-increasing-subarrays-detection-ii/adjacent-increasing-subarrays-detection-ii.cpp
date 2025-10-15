class Solution {
public:
   int maxIncreasingSubarrays(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    int start = 0, count = 0;

    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            continue;
        } else {
            int len = i - start;
            if (count == 0)
                maxi = max(maxi, len / 2);
            else
                maxi = max({maxi, min(len, count), len / 2});
            count = len;
            start = i;
        }
    }

    // Handle the last increasing segment
    int len = n - start;
    if (count == 0)
        maxi = max(maxi, len / 2);
    else
        maxi = max({maxi, min(len, count), len / 2});

    return maxi;
}

};