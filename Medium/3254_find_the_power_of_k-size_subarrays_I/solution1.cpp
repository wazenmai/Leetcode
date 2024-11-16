/**
 * Title:  Find the Power of K-Size Subarrays I (Leetcode Medium 3254)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, November, 2024
 * Result: Time complexity O(nk).
 */

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        for (int i = 0; i < n - k + 1; i++) {
            bool flag = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    flag = false;
                    break;
                }
            }
            ans[i] = (flag) ? nums[i + k - 1] : -1;
        }
        return ans;
    }
};
