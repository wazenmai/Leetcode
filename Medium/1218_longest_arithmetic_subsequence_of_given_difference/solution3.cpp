/**
 * Title:  Longest Arithmetic Subsequence of Given Difference (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, November, 2024
 * Method: Different from previous solution, here the dp[i]'s i is the real number value, so we construct dp array with size 2e4 + 2. We move the number to positive number by adding 1e4. Then we can use dp array to store the length of longest subsequence of difference whose last element is i.
 * Result: O(n) time complexity, O(n) space complexity. Time: 65ms -> 0ms.
 */

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        const int n = 2e4 + 2;
        int dp[n] = {0};
        int ans = 1;
        for (int& num: arr) {
            int cur = num + 1e4; // move it to positive number
            int x = cur - difference; // the previous number
            if (x < 0 || x > 2e4) {
                dp[cur] = 1;
                continue;
            }
            dp[cur] = 1 + dp[x];
            ans = max(ans, dp[cur]);
        }
        return ans;
    }
};
