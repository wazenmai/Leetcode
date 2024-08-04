/**
 * Title:  Range Sum of Sorted Subarray Sums (Leetcode Medium 1508)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, August, 2024
 * Method: Use min-heap to store the sum of subarray and its end index, we can start to accumulate the top after `left - 1` times pop until `right` times pop.
    *      In the beginning, we push all one-sized subarray sum into heap.
    *      Every time we pop, we increase the end index by 1 and push the new sum into the heap.
 * Result: Time complexity O(n^2logn), Space complexity O(n). // Push and pop are both O(logn), and there are only n elements in heap.
 */

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(nums[i], i));
        }
        for (int i = 1; i < left; i++) {
            auto u = pq.top();
            pq.pop();
            if (u.second != n - 1)
                pq.push(make_pair(u.first + nums[u.second + 1], u.second + 1));
        }
        int ans = 0;
        for (int i = left; i <= right; i++) {
            auto u = pq.top();
            pq.pop();
            ans = (ans + u.first) % mod;
            if (u.second != n - 1)
                pq.push(make_pair(u.first + nums[u.second + 1], u.second + 1));
        }
        return ans;
    }
};
