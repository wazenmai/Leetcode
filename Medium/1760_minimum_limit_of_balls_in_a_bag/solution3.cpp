/**
 * Title:  Minimum Limit of Balls in a Bag (Leetcode Medium 1760)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, December, 2024
 * Method: Optimization. add const, reduce branching, use inline function.
 * Result: Time complexity is O(nlogm), space complexity is O(1). n is the size of nums, m is the maximum number in nums.
 */

class Solution {
public:
    inline bool check(const vector<int>& nums, const int maxOperations, const int mid) {
        int op = 0;
        for (auto num: nums) {
            op += ((num - 1) / mid);
            if (op > maxOperations) break;
        }
        return op <= maxOperations;
    }
    int minimumSize(const vector<int>& nums, const int maxOperations) {
        int n = nums.size();
        int l = 1, r = 1e9 + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, maxOperations, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

// 100 -> 33
// 33 67
// 33 33 34
// 11 -> 3
// 3 8
// 3 3 5 -> 3 3 3 2
// 12
// 8 -> 2 (3)
// 2 6, 2
// 9->2