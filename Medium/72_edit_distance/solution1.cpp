/**
 * Title:  Edit Distance (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, September, 2023
 * Method: Bottom-Up DP. dp[i][j] = minDistance of word1(0 ~ i - 1), word2(0 ~ j - 1). 
 *         If the char is same, then transfered (i - 1, j - 1), other wise is min(lu, u, l) + 1.
 *         Time complexity O(nm), Space complexity O(nm).
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
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[n][m];
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