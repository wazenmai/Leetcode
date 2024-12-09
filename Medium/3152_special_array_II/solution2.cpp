/**
 * Title:  Special Array II (Leetcode Medium 3152)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, December, 2024
 * Method: Use prefix to record the number of invalid pairs. If the end point and the start point has same number, then the range is valid.
 * Result: Time complexity is O(n + m), space complexity is O(n).
 */

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n ; i++) {
            if (!((nums[i] ^ nums[i - 1]) & 1)) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }
        // for (auto& e: prefix) {
        //     cout << e << " ";
        // }
        // cout << "\n";
        vector<bool> ans;
        for (auto& q: queries) {
            ans.emplace_back(prefix[q[1]] - prefix[q[0]] == 0);
        }
        return ans;
    }
};
