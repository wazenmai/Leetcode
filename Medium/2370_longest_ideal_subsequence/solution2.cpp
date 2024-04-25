/**
 * Title:  Longest Ideal Subsequence (Leetcode Medium 2370)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, April, 2024
 * Method: Use dp with size 26 to record each character's longest ideal string length.
 * Result: Time complexity is O(nk), space complexity is O(26).
 */

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for (char c: s) {
            int mx = 0;
            int c_num = c - 'a';
            for (int i = max(0, c_num - k); i <= min(25, c_num + k); ++i) {
                mx = max(dp[i], mx);
            }
            dp[c_num] = max(dp[c_num], mx + 1);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
