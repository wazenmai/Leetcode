/**
 * Title:  Contiguous Array (Leetcode Medium 525)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, March, 2024
 * Method: Tidy code.
 * Result: Time complexity O(n), Space complexity O(n).
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int s = 0;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            s += (nums[i] == 1) ? 1 : -1;
            if (s == 0) {
                ans = max(ans, i + 1);
            } else if (m.find(s) != m.end()) {
                ans = max(ans, i - m[s]);
            } else {
                m[s] = i;
            }
        }
        return ans;
    }
};
