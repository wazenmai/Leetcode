/**
 * Title:  Sum of All Subset XOR Totals (Leetcode Easy 1863)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, May, 2024
 * Method: List all subsets with length from 1 to n, and calculate the XOR sum of each subset.
 * Result: Time complexity is O(n*(2^n+n)). Space complexity is O(n).
 */

class Solution {
private:
    int n;
public:
    int recur(vector<int>& nums, vector<int>& subset, int id, int len) {
        if (subset.size() == len) {
            int res = 0;
            for (auto& ele: subset) {
                // cout << ele << " ";
                res ^= ele;
            }
            // cout << ": " << res << "\n";
            return res;
        }
        if (id == n) return 0;
        int s = 0;
        for (int i = id; i < n; i++) {
            subset.emplace_back(nums[i]);
            s += recur(nums, subset, i + 1, len);
            subset.pop_back();
        }
        return s;
    }
    
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        int ans = 0;
        for (int len = 1; len <= n; len++) {
            vector<int> subset;
            // cout << "length: " << len << "\n";
            ans += recur(nums, subset, 0, len);
        }
        return ans;
    }
};
