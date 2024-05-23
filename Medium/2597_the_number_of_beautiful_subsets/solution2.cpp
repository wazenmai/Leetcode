/**
 * Title:  The Number of Beautiful Subsets (Leetcode Medium 2597)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, May, 2024
 * Method: Use a map to store the frequency of each number. For each number, we can either take it or not. And we can check map[num-k] and map[num+k] to see if we can take it.
 * Result: Time complexity is O(2^n). Space complexity is O(n).
 */

class Solution {
private:
    int n;
public:
    int dfs(vector<int>& nums, unordered_map<int, int>& m, int k, int id) {
        if (id == n) return 1;

        int taken = 0;

        // take nums[id]
        if (m[nums[id] + k] == 0 && m[nums[id] - k] == 0) {
            m[nums[id]] += 1;
            taken = dfs(nums, m, k, id + 1);
            m[nums[id]] -= 1;
        }
        // not take nums[id]
        int notTaken = dfs(nums, m, k, id + 1);
        return taken + notTaken;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        unordered_map<int, int> m;
        int ans = dfs(nums, m, k, 0);
        return ans - 1; // exclude empty set
    }
};
