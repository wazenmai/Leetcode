/**
 * Title:  Edit Distance (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, September, 2023
 * Method: Memory optimization: Space complexity O(m).
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (word1 == word2)
            return 0;
        if (n == 0 || m == 0)
            return max(n, m);
        vector<int> dp(m + 1, 0), last_dp(m + 1, 0);
        for (int j = 1; j <= m; j++) {
            last_dp[j] = j;
        }
        for (int i = 1; i <= n; i++) {
            dp[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = last_dp[j - 1];
                } else {
                    dp[j] = min(last_dp[j - 1], min(dp[j - 1], last_dp[j])) + 1;
                }
                // cout << dp[j] << " "; 
            }
            // cout << "\n";
            last_dp = dp;
        }
        return dp[m];
    }
};

// dp[i][j] = minDistance of word1(0 - i) & word2(0 - j)
// dp[0][0] = 1, not same then replace = 1, same = 0
// dp[0][1] = 2, not same + 1 = 2, same = 1
// dp[0][2] = 3

// dp[1][0] = 2 (h->r, -o)
// dp[1][1] = 1 (o == o, h->r)
// dp[1][2] = 2 (o == o, h ->r, + s)

// dp[2][0] = 2 (r == r, -h -o)
// dp[2][1] = 2 (o == o, h->r, -r)
// dp[2][2] = 2 (o == o, h->r, r -> s)

// dp[3][0] = 3 (r == r, -h -o -s)
// dp[3][1] = 3 (o == o, h->r, -r, -s)
// dp[3][2] = 2 (o == o, s == s, h->r -r)

// dp[4][0] = 4 (r == r, -h -o -s -e)
// dp[4][1] = 4 (o == o, h->r, -r -s -e)
// dp[4][2] = 3 (h->r o == o, -r, s == s, -e)