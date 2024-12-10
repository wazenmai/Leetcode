/**
 * Title:  Domino and Tromino Tiling (Leetcode Medium 970)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, December, 2024
 * Method: dp[i] = dp[i - 1] * 2 + dp[i - 3]. Please refer to the explanation below.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        int mod = 1e9 + 7;
        for (int i = 4; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % mod;
        }
        return (int)dp[n];
    }
};

// dp[i] = # of ways to put in tiling of 2 x i


/* Explanation of why dp[i] = 2 * dp[i - 1] + dp[i - 3] 
- When transforming dp[i - 1] to dp[i], we consider domino case and trimino case.
- Two case for domino: one straight domino or two horizontal dominoes. -> dp[i - 1] + dp[i - 2]
- For trimino, there are two shapes, if we consider to add domino to the left, one is with L shape and one is with |- shape.
    - it may have two trimino to constrct 2 x 3 rectangle: dp[i - 3]
    - it may have two trimino + 1 horizontal dominos to construct 2x4 rectangle: dp[i - 4]
    - it may have two trimino + 2 horizontal dominos to construct 2x5 rectangle: dp[i - 5]
    - ...
    - dp[i - 3] + dp[i - 4] + dp[i - 5] + ...
    - And because there are two shapes to consider, so 2 * (dp[i - 3] + dp[i - 4] + dp[i - 5] + ...)
- so dp[i] = dp[i - 1] + dp[i - 2] (domino case) + 2 * (dp[i - 3] + dp[i - 4] + dp[i - 5] + ...) (trimino case)
           = 2 * (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + ...) - dp[i - 1] - dp[i - 2]
- Also we know dp[i - 1] = dp[i - 2] + d[i - 3] + 2 * (dp[i - 4] + dp[i - 5] + ...)
- If we view dp[i] = 2 * dp[i - 1] + (dp[i - 2] + 2 * (dp[i - 3] + dp[i - 4] + ...) - dp[i - 1]), 
- then the second term  is equals to dp[i - 2] + 2 * (dp[i - 3] + dp[i - 4] + ...) - dp[i - 2] + d[i - 3] + 2 * (dp[i - 4] + dp[i - 5] + .. = dp[i - 3].
- So dp[i] = 2 * dp[i - 1] + dp[i - 3]
*/

