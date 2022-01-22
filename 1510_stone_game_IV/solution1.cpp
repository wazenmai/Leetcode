/**
 * Title:  Stone Game IV (Leetcode Hard 1510)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Jan, 2022
 * Method: O(n) space, O(n) time
 */

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        return dfs(n, dp);
    }
    
    bool dfs(int stone, vector<int>& dp) {
        // cout << "dfs " << stone << "\n";
        if (dp[stone] != -1)
            return dp[stone];
        for (int i = 1; i * i <= stone; i++) {
            if (!dfs(stone - i * i, dp)) {
                dp[stone] = true;
                return true;
            }
        }
        dp[stone] = false;
        return false;
    }
};
