/**
 * Title:  The Number of Beautiful Subsets (Leetcode Medium 2597)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, May, 2024
 * Method: Brute Force. Generate all subsets and check if it is beautiful.
 * Result: Time complexity is O(2^n). Space complexity is O(2^n).
 */

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<vector<int>> subsets(1);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int m = subsets.size();
            for (int j = 0; j < m; j++) {
                subsets.emplace_back(subsets[j]);
                subsets[j].emplace_back(nums[i]);
            }
        }
        int ans = 0;
        for (auto& subset: subsets) {
            if (subset.size() == 1) {
                ans++;
            } else {
                int m = subset.size();
                bool flag = true;
                for (int i = 0; i < m; i++) {
                    for (int j = i + 1; j < m; j++) {
                        if (abs(subset[i] - subset[j]) == k) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag) ans++;
            }
        }
        ans = max(0, ans - 1);
        return ans;
    }
};
