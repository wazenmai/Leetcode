/**
 * Title:  Minimum Increment to Make Array Unique (Leetcode Easy 3110)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, June, 2024
 * Result: Worst case Time complexity O(n^2), Space complexity O(2e6).
 */

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> cnt(200001, 0);
        int ans = 0;
        for (int& num: nums) {
            if (cnt[num] > 0) {
                int i = 0;
                while (num + i < 200000 && cnt[num + i] > 0) {
                    ans++;
                    i++;
                }
                cnt[num + i] = 1;
            } else {
                cnt[num] = 1;
            }
        }
        return ans;
    }
};
