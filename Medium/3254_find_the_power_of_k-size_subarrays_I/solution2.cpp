/**
 * Title:  Find the Power of K-Size Subarrays I (Leetcode Medium 3254)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, November, 2024
 * Method: Use a deque to maintain current window (k), if the condition is not satisfied, clear the deque.
 * Result: Time complexity O(n).
 */

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            if (!dq.empty() && i > 0 && nums[i] != nums[i - 1] + 1)
                dq.clear();
            dq.push_back(i);
            if (i >= k - 1 && dq.size() == k) {
                ans[i - k + 1] = nums[dq.back()]; 
            }
        }
        return ans;
    }
};