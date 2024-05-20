/**
 * Title:  Sum of All Subset XOR Totals (Leetcode Easy 1863)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, May, 2024
 * Method: Record current result and count of elements in the subset, so we can eliminate the subset vector.
 * Result: Time complexity is O(n*2^n). Space complexity is O(1).
 */

class Solution {
private:
    int n;
public:
    int recur(vector<int>& nums, int id, int len, int res, int cnt) {
        if (cnt == len) return res;
        if (id == n) return 0;
        int s = 0;
        for (int i = id; i < n; i++) {
            res ^= nums[i];
            s += recur(nums, i + 1, len, res, cnt + 1);
            res ^= nums[i];
        }
        return s;
    }

    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        int ans = 0;
        for (int len = 1; len <= n; len++) {
            // cout << "length: " << len << "\n";
            ans += recur(nums, 0, len, 0, 0);
        }
        return ans;
    }
};
