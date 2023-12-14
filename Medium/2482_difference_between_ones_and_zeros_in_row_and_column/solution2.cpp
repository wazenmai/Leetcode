/**
 * Title:  Difference Between Ones and Zeros in Row and Column (Leetcode Medium 2482)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, December, 2023
 * Method: Memory optimization by first compute the ones and zeros by row then by column.
 * Result: Time complexity O(mn), Space complexity O(1)
 */

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            int d = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    d += 1;
                } else {
                    d -= 1;
                }
            }
            for (int j = 0; j < m; j++)
                ans[i][j] += d;
        }
        for (int j = 0; j < m; j++) {
            int d = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    d += 1;
                } else {
                    d -= 1;
                }
            }
            for (int i = 0; i < n; i++)
                ans[i][j] += d;
        }
        return ans;
    }
};
