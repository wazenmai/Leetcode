/**
 * Title:  Sliding Window Maximum (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, August, 2023
 * Method: Use heap to find the max value in the window. Time complexity: O(nlogn). Space complexity: O(n)
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1)
            return nums;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>> h; // max heap
        for (int i = 0; i < k; i++) {
            h.push(make_pair(nums[i], i));
        }
        ans.emplace_back(h.top().first);
        for (int i = k; i < nums.size(); i++) {
            h.push(make_pair(nums[i], i));
            while (h.top().second < i - k + 1) {
                h.pop();
            }
            ans.emplace_back(h.top().first);
        }
        return ans;
    }
};

