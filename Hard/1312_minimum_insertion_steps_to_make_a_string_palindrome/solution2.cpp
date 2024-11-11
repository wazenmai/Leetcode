/**
 * Title:  Minimum Insertion Steps to Make a String Palindrome (Leetcode Hard 1312)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, November, 2024
 * Method: Optimization. dp[i] = minimum steps to make string(i ~ n - 1) palindrome. We iterate from bottom of the string to compute the steps needed to convert it to palindrome.
 * Result: Time complexity O(n^2), Space complexity O(n).
 */

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        int max_len = 0;
        for (int i = n - 2; i >= 0; i--) {
            int prev = 0;
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = prev; // same word, no need perform step
                } else {
                    dp[j] = min(dp[j], dp[j - 1]) + 1; // need to perform one step
                }
                prev = temp;
            }
        }
        return dp[n - 1];
    }
};

// dp[i] = minimum steps to make string(i ~ n - 1) palindrome
