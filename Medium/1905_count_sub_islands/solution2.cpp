/**
 * Title:  Count Sub Islands (Leetcode Medium 1905)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, August, 2024
 * Method: BFS. call `isSubIsland` when meet land cell in grid2, then BFS to check if the island is a sub-island in grid1.
 * Result: Time complexity is O(n * m), space complexity is O(2 * n * m).
 */

class Solution {
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n;
    int m;
public:
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visit) {
        // whether the island of `grid2` containing cell at position (x,y) is a sub-island in `grid` or not.
        int isSubIsland = true;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visit[x][y] = true;
        while (!q.empty()) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            if (grid1[curX][curY] == 0) isSubIsland = false;

            for (int d = 0; d < 4; d++) {
                int nx = curX + dx[d];
                int ny = curY + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (visit[nx][ny] || grid2[nx][ny] == 0) continue;
                q.push(make_pair(nx, ny));
                visit[nx][ny] = true;
            }
        }
        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        int ans = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (visit[x][y] || grid2[x][y] == 0) continue;
                if (isSubIsland(x, y, grid1, grid2, visit)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
