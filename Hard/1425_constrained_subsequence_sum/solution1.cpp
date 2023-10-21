/**
 * Title:  Constrained Subsequence Sum (Leetcode Hard 1425)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, October, 2023
 * Method: Use deque to store the index of the max value in the window.
 * Result: Time complexity O(N), space complexity O(N).
 */

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            nums[i] += !dq.empty() ? nums[dq.front()] : 0;
            while (!dq.empty() && (i - dq.front() >= k || nums[i] >= nums[dq.back()])) {
                if (nums[i] >= nums[dq.back()])
                    dq.pop_back();
                else
                    dq.pop_front();
            }
            if (nums[i] > 0) {
                dq.push_back(i);
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};

// state (i): nums0 ~ i's constrained SubsetSum
// it can come from dp state(i - 1) ~ (i - k)
