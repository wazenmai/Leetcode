/**
 * Title:  Number of Ways to Stay In The Same Place After Some Steps (Leetcode Hard 1269)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, October, 2023
 * Method: Top-down DP. Since the maximum of step is 500, we can adjust the array size if the array size is larger than steps.
           The state is (step, i), where step is the remaining steps and i is the current index.           
 * Result: Time complexity O(steps * n). Space complexity O(steps * n).
 */

class Solution {
private:
    int n;
    int mod = 1e9 + 7;
public:
    int walk(int step, int i, vector<vector<int>>& dp) {
        if (step == 0) {
            if (i == 0)
                return 1;
            return 0;
        }
        if (dp[step][i] != -1)
            return dp[step][i];
        // stay
        long long stay = walk(step - 1, i, dp);
        // right
        long long right = (i + 1 < n) ? walk(step - 1, i + 1, dp) : 0;
        // left
        long long left = (i - 1 >= 0) ? walk(step - 1, i - 1, dp) : 0;
        long long temp = (stay + right + left) % mod;
        return dp[step][i] = (int)temp;
    }
    int numWays(int steps, int arrLen) {
        if (arrLen > steps)
            n = steps / 2 + 1;
        else
            n = arrLen;
        vector<vector<int>> dp(steps + 1, vector<int>(n, -1));
        return walk(steps, 0, dp);
    }
};
// r l
// s s

// r l s
// s s s
// s r l
// r s l

// r l s s
// s r l s
// r s l s
// s s s s

// r r l l
// r l r l
// s r s l
// r s s l
