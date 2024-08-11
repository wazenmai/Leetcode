/**
 * Title:  Minimum Number of Days to Disconnect Island (Leetcode Hard 1568)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, August, 2024
 * Method: Observation -> The answer can only be 0, 1, and 2. If the number of islands is not 1, the answer is 0. If the number of islands is 1, we can try removing each land cell to see whether the answer can be 1. If not, the answer is 2.
 * Result: Time complexity O((mn)^2), Space complexity O(mn).
 */

class Solution {
private:
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m;
    int n;
public:
    void exploreIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        visited[row][col] = true;
        for (const auto& dir: DIRECTIONS) {
            int nr = row + dir[0];
            int nc = col + dir[1];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (grid[nr][nc] == 0) continue;
            if (!visited[nr][nc]) exploreIsland(grid, visited, nr, nc);
        }
    }
    int countIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!visited[r][c] && grid[r][c] == 1) {
                    exploreIsland(grid, visited, r, c);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int numIslands = countIslands(grid);
        if (numIslands != 1) return 0;

        // Try removing each land cell to see whether answer can be 1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                grid[i][j] = 0;
                int newNum = countIslands(grid);
                if (newNum != 1) return 1;
                grid[i][j] = 1;
            }
        }
        return 2;
    }
};
