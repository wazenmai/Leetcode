/**
 * Title:  Maximum Number of Moves in a Grid (Leetcode Medium 2684)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, October, 2024
 * Method: DP. If we can reach column[j], that means we moved j - 1 steps. So dp[i][j] = whether we can reach column[j] (0 / 1). Memory optimization.
 * Result: Time complexity O(nm). Space complexity O(n).
 */

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> cur(n, 0);
        vector<int> pre(n, 1);
        for (int j = 1; j < m; j++) {
            int temp = 0;
            for (int i = 0; i < n; i++) {
                cur[i] = 0;
                for (int k = -1; k <= 1; k++) {
                    int pi = i + k;
                    if (pi < 0 || pi >= n) continue;
                    if (pre[pi] > 0 && grid[pi][j - 1] < grid[i][j]) {
                        cur[i] = 1;
                    }
                }
                temp = max(temp, cur[i]);
            }
            if (temp == 0) return j - 1;
            pre = cur;
        }
        return m - 1;
    }
};
