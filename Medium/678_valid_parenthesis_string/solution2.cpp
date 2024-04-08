/**
 * Title:  Valid Parenthesis String (Leetcode Medium 678)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, April, 2024
 * Method: Bottom-Up DP-Tabulation. We iterate from last character to first one and the inner loop we iterate the number of '('.
 * Result: Time complexity is O(n^2), space complexity is O(n^2).
 */

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        // base case: empty string with 0 opening brackets
        dp[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= n; j++) {
                bool isValid = false;
                if (s[i] == '*') {
                    isValid |= dp[i + 1][j + 1]; // '('
                    if (j > 0) {
                        isValid |= dp[i + 1][j - 1]; // ')'
                    }
                    isValid |= dp[i + 1][j]; // empty
                } else if (s[i] == '(') {
                    isValid |= dp[i + 1][j + 1];
                } else if (j > 0) { // ')'
                    isValid |= dp[i + 1][j - 1];
                }
                dp[i][j] = isValid;
            }
        }

        return dp[0][0];
    }
};
// Top-Down DP-Memorization T-O(n^2). S-O(n^2)
// dp[i][j] = at end of i-th character contain j '('
// dp[i][j] = 1 if contain, 0 if doesn't contain

// Bottom-Up DP-Tabulation T-O(n^2). S-O(n^2)
// dp[i][j] = whether str(i ~ n - 1) with j '(' is valid