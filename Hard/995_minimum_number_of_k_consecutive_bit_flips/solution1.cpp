/**
 * Title:  Minimum Number of K Consecutive Bit Flips (Leetcode Hard 995)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, June, 2024
 * Method: Use a queue to store the last index of the flipped window.
 * Result: Time complexity is O(n), space complexity is O(k).
 */

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        queue<int> q;
        for (int i = 0; i <= n - k; i++) {
            while (!q.empty() && q.front() < i) {
                q.pop();
            }
            if (q.size() & 1) nums[i] ^= 1;
            if (nums[i] == 0) {
                q.push(i + k - 1);
                ans++;
            }
        }
        for (int i = n - k + 1; i < n; i++) {
            while (!q.empty() && q.front() < i) {
                q.pop();
            }
            if (q.size() & 1) nums[i] ^= 1;
            if (nums[i] == 0) return -1;
        }
        return ans;
    }
};
