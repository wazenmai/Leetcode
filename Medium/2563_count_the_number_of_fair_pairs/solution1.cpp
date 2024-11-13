/**
 * Title:  Count the Number of Fair Pairs (Leetcode Medium 2563)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, November, 2024
 * Method: Sort the array and use binary search to find the number of elements that satisfy the condition.
 * Result: Time complexity O(nlogn + 2nlogn) = O(nlogn), space complexity O(1).
 */

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        function<int(int, int)> bs = [&](int x, int range) {
            int l = 0, r = range;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (nums[mid] <= x) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l - 1;
        };

        long long ans = 0;
        for (int i = 1; i < n; i++) {
            int upper_id = bs(upper - nums[i], i);
            int lower_id = bs(lower - nums[i] - 1, i);
            ans += ((long long)upper_id - (long long)lower_id);
        }
        return ans;
    }
};

// 0 1 4 4 5 7,
// all (<= 6) - all (< 3)
// every number x -> binary search y <= upper - x
// every number x -> binary search x + y < lower -> y < lower - x -> y <= lower - x - 1