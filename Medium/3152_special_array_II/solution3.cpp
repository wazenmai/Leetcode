/**
 * Title:  Special Array II (Leetcode Medium 3152)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, December, 2024
 * Method: Sliding window to record the maximum valid range for each start point.
 * Result: Time complexity is O(n + m), space complexity is O(n).
 */


class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> maxReach(n, 0);
        int end = 0;
        for (int start = 0; start < n; start++) {
            end = max(end, start);
            while (end < n - 1 && ((nums[end] ^ nums[end + 1]) & 1)) {
                end++;
            }
            maxReach[start] = end;
        }
        vector<bool> ans;
        for (auto& q: queries) {
            ans.emplace_back(maxReach[q[0]] >= q[1]);
        }
        return ans;
    }
};
