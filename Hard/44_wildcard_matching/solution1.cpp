/**
 * Title:  Wildcard Matching (Leetcode Hard 44)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, December, 2024
 * Method: Recursion with memorization. If the current character is '*', we can either match zero characters or match one or more characters. If the current character is not '*', we need to match the current character and move to the next character.
 * Result: Time complexity O(n*m), Space complexity O(n*m).
 */

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        if (n == 0 && m != 0) {
            for (auto& c: p) {
                if (c != '*') return false;
            }
            return true;
        }

        function<bool(int, int)> dfs = [&](int i, int j) {
            // cout << "dfs(" << i << "," << j << ") ";
            if (j >= m) {
                if (i >= n) return true;
                return false;
            }
            if (i >= n) {
                for (int k = j; k < m; k++) {
                    if (p[k] != '*') return false;
                }
                return true;
            }
            if (dp[i][j] != -1) return (dp[i][j] == 1);
            bool first_match = (s[i] == p[j] || p[j] == '?');
            // cout << "first: " << first_match << ", ";
            if (p[j] == '*') {
                bool any_match = dfs(i, j + 1); // zero match
                // cout << "zero: " << any_match << ", ";
                for (int k = i + 1; k <= n; k++) {
                    any_match |= (dfs(k, j) || dfs(k, j + 1)); // cont. or next
                    // cout << k << ": " << any_match << ", ";
                    if (any_match) {
                        dp[i][j] = 1;
                        return true;
                    }
                }
                // cout << "\n";
                dp[i][j] = 0;
                return false;
            } else {
                // cout << "\n";
                dp[i][j] = (first_match && dfs(i + 1, j + 1)) ? 1 : 0;
                return (dp[i][j] == 1);
            }
        };
        return dfs(0, 0);
    }
};

// 01234567890
// abcabczzzde

// 0123456789
// *abc???de*
