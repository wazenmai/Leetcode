/**
 * Title:  Shortest Subarray with Sum at Least K (Leetcode Hard 862)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, November, 2024
 * Method: Use a priority queue to maintain the smallest prefix sum (so prefix_sum[cur] - its top will be the largest sum). When the current sum - its top >= k, we can calculate the length and pop the top.
 * Result: Time complexity O(nlogn). Space complexity O(n).
 */

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push(make_pair(0, -1));
        long long s = 0;
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            pq.push(make_pair(s, i));
            while (!pq.empty() && s - pq.top().first >= k) {
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
        }
        return (ans == n + 1) ? -1 : ans;
    }
};