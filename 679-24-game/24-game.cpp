class Solution {
public:

    // Recursively try every way to pick two numbers, combine them,
    // and solve on the reduced list of numbers.
    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        // Pick any ordered pair (i, j)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<double> rest;
                // Collect the unused numbers
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        rest.push_back(nums[k]);
                    }
                }

                // Generate all possible results of nums[i] ∘ nums[j]
                vector<double> candidates;
                candidates.push_back(nums[i] + nums[j]);
                candidates.push_back(nums[i] - nums[j]);
                candidates.push_back(nums[j] - nums[i]);
                candidates.push_back(nums[i] * nums[j]);
                if (fabs(nums[j]) > 1e-6) candidates.push_back(nums[i] / nums[j]);
                if (fabs(nums[i]) > 1e-6) candidates.push_back(nums[j] / nums[i]);

                // Recurse on each new list
                for (double c : candidates) {
                    rest.push_back(c);
                    if (solve(rest)) return true;
                    rest.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
