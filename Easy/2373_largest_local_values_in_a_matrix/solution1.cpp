/**
 * Title:  Largest Local Values in a Matrix (Leetcode Easy 2373)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, May, 2024
 */

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                // small 3x3
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        ans[i][j] = max(ans[i][j], grid[i + k][j + l]);
                    }
                }

            }
        }
        return ans;
    }
};
