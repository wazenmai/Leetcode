/**
 * Title:  Final Array State After K Multiplication Operations I (Leetcode Easy 3264)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, December, 2024
 * Result: Time complexity is O(nlogn), space complexity is O(n). n is the number of elements in the array. We use a priority queue to store the elements in the array.
 */

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(nums[i], i));
        }
        for (int i = 0; i < k; i++) {
            auto [v, id] = pq.top();
            pq.pop();
            nums[id] *= multiplier;
            pq.push(make_pair(nums[id], id));
        }
        return nums;
    }
};
