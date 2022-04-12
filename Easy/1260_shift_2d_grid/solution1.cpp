/**
 * Title:  Shift 2D Grid (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, April, 2022
 */

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = (int)grid.size() - 1;
        int m = (int)grid[0].size() - 1;
        // Rotate the grid for k times
        for (int rot = 0; rot < k; rot ++){
            int temp = grid[n][m];
            for (int i = n; i >= 0; i--){
                for (int j = m; j >= 0; j--){
                    if (i == 0 && j == 0) break;
                    grid[i][j] = (j == 0) ? grid[i - 1][m] : grid[i][j - 1];
                }
            }
            grid[0][0] = tmpLast;
        }
        return grid;
    }
};
