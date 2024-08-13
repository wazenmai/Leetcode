/**
 * Title:  Combination Sum II (Leetcode Medium 40)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, August, 2024
 * Method: Simplify the code. Sort candiates first, then use backtracking. Remember to jump same number.
 * Result: Time complexity is O(2^n), space complexity is O(n).
 */

class Solution {
private:
    vector<vector<int>> ans;
    int n;
public:
    void combination(vector<int>& nums, int target, int i, vector<int>& cur, int s) {
        if (s == target) {
            ans.emplace_back(cur);
            return;
        }
        if (s > target || i == n) return;
        // choose
        cur.emplace_back(nums[i]);
        s += nums[i];
        combination(nums, target, i + 1, cur, s);
        cur.pop_back();
        s -= nums[i];
        while (i + 1 < n && nums[i] == nums[i + 1]) // jump same number
            i++;
        // not choose
        combination(nums, target, i + 1, cur, s);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        vector<int> cur;
        combination(candidates, target, 0, cur, 0);
        return ans;
    }
};
