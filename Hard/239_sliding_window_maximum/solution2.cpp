/**
 * Title:  Sliding Window Maximum (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, August, 2023
 * Method: Use Monotonic Queue (Deque) to store the index of the largest element at front. Time complexity: O(n), Space complexity: O(k)
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // two-direction queue, here set front is largest
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.emplace_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++) {
            if (dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            ans.emplace_back(nums[dq.front()]);
        }
        return ans;
    }
};

// Time complexity: O(n), since each element can only be added in dq once, pop once
// Sapce complexity: O(k)