/**
 * Title:  Count the Number of Fair Pairs (Leetcode Medium 2563)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, November, 2024
 * Method: Use binary search to directly find the number of pairs.
 * Result: Time complexity O(nlogn + 2logn) = O(nlogn), space complexity O(1).
 */

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        function<long long(int)> countPairs = [&](int v) {
            int l = 0, r = n - 1;
            long long res = 0;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < v) {
                    res += (r - l); // for l, all r ~ l + 1 is valid
                    l++;
                } else {
                    r--;
                }
            }
            return res;
        };

        return countPairs(upper + 1) - countPairs(lower);
    }
};

// all pairs (< upper + 1) - all pairs (< lower)
