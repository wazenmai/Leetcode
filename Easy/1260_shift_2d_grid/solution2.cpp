/**
 * Title:  Shift 2D Grid (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, April, 2022
 */

class Solution {
public:
    void shiftRow(vector<vector<int>>& grid, int k) {
        int add_row = (int)grid.size() - k;
        for (int i = 0; i < add_row; i++)
            grid.emplace_back(grid[i]);
        for (int i = 0; i < add_row; i++)
            grid.erase(grid.begin());
    }
    
    void shiftColumn(vector<vector<int>>& grid, int k) {
        int n = (int)grid.size() - 1, m = (int)grid[0].size() - 1;
        for (int r = 0; r < k; r++) {
            int temp = grid[n][m];
            for (int i = n; i >= 0; i--) {
                for (int j = m; j >= 0; j--) {
                    if (i == 0 && j == 0) break;
                    grid[i][j] = (j == 0) ? grid[i - 1][m] : grid[i][j - 1];
                }
            }
            grid[0][0] = temp;
        }
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        int line = (k / m) % n;
        int shift = k % m;
        shiftRow(grid, line);
        shiftColumn(grid, shift);
        return grid;
    }
};
