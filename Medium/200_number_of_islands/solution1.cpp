/**
 * Title:  Number of Islands (Leetcode Medium 200)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:  19, April, 2024
 * Result: Time complexity O(n*m), Space complexity O(n*m).
 */

class Solution {
private:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j] || grid[i][j] == '0') continue;
                // cout << "first " << i << "," << j << "\n";
                q.push(make_pair(i, j));
                visit[i][j] = true;
                while (!q.empty()) {
                    auto cur = q.front();
                    // cout << "(" << cur.first << "," << cur.second << ") ";
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int ni = cur.first + di[d];
                        int nj = cur.second + dj[d];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                        if (visit[ni][nj]) continue;
                        if (grid[ni][nj] == '1') {
                            q.push(make_pair(ni, nj));
                            visit[ni][nj] = true;
                        }
                    }
                }
                // cout << "\n";
                ans++;
            }
        }
        return ans;
    }
};
