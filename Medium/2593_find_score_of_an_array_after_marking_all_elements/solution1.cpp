/**
 * Title:  Find Score of an Array After Marking All Elements (Leetcode Medium 2593)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, December, 2024
 * Method: Use an array to mark and use min-heap to get the smallest element in the array.
 * Result: Time complexity is O(nlogn), space complexity is O(n). n is the number of elements in the array.
 */

class Solution {
public:
    long long findScore(vector<int>& nums) {
        size_t n = nums.size();
        vector<bool> marked(n, false);
        long long score = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (size_t i = 0; i < n; i++) {
            pq.push(make_pair(nums[i], i));
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (marked[cur.second]) continue;
            score += cur.first;
            marked[cur.second] = true;
            if (cur.second < n - 1)
                marked[cur.second + 1] = true;
            if (cur.second > 0)
                marked[cur.second - 1] = true;
        }
        return score;
    }
};
