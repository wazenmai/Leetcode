/**
 * Title:  Path with Maximum Gold (Leetcode Medium 1219)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, May, 2024
 * Method: Dfs start from each cell with gold, and update the maximum gold
 * Result: Time complexity O(nm*4^nm), Space complexity O(nm). n is the number of rows, m is the number of columns. There are nm cells, and each cell has 4 directions to go, so the time complexity is O(nm*4^nm)
 */

class Solution {
private:
    int n;
    int m;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
public:
    int findGold(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r, int c, int gold) {
        int ans = gold;
        visit[r][c] = true;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (visit[nr][nc]) continue;
            if (grid[nr][nc] == 0) continue;
            ans = max(ans, findGold(grid, visit, nr, nc, gold + grid[nr][nc]));
            visit[nr][nc] = false;
        }
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    vector<vector<bool>> visit(n, vector<bool>(m, false));
                    ans = max(findGold(grid, visit, i, j, grid[i][j]), ans);
                }
            }
        }
        return ans;
    }
};
