/**
 * Title:  Shortest Subarray with Sum at Least K (Leetcode Hard 862)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, November, 2024
 * Method: First calculate prefix sum. Then maintain the deque, if sum(dq.front() ~ i) >= k, calculate ans length and pop the front element.
 *         Then iterate from the back of deque, if prefix[dq.back()] >= prefix[i], means that sum(dq.back() ~ i) <= 0, which will not help us to find the shorter subarray that sum >= k, so we pop it.
 *         Finally, push the current index to the back of deque.
 * Result: Time complexity O(n). Space complexity O(n).
 */

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        deque<int> dq;
        int ans = n + 1;
        for (int i = 0; i <= n; i++) { // because prefix sum 1 ~ n means element 0 ~ n - 1
            // 1. Remove candidates from front of deque where target meet
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            // 2. Maintain monotonicy by removing indices with larger prefix sums
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            // 3. Add curent index to dq
            dq.push_back(i);
        }
        return (ans == n + 1) ? -1 : ans;
    }
};
