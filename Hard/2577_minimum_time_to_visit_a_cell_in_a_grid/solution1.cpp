/**
 * Title:  Minimum Time to Visit a Cell In a Grid (Leetcode Hard 2577)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, November, 2024
 * Method: Dijkstra algorithm. If the required step > cur-step + 1, calculate the needed step. If difference is odd, then the step is the grid value, otherwise the step is grid value + 1.
 * Result: Time complexity O(n * m * log(n * m)), where n is the number of rows, m is the number of columns. Space complexity O(n * m).
 */

class Solution {
private:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 1e6));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push(vector<int>{0, 0, 0});
        visit[0][0] = 0;
        int step = 0;
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            int step = u[0], i = u[1], j = u[2];
            // cout << step << ", (" << i << ", " << j << ") visit=" << visit[i][j] << "\n";
            if (step > visit[i][j]) continue;
            if (i == n - 1 && j == m - 1) return step;
            for (int d = 0; d < 4; d++) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if (visit[ni][nj] <= step + 1) continue;
                if (grid[ni][nj] > step + 1) {
                    if (i == 0 && j == 0) {
                        if (d == 1 && grid[0][1] > 1) continue; // down, check right
                        if (d == 3 && grid[1][0] > 1) continue; // right, check down
                    }
                    int diff = grid[ni][nj] - step;
                    if (diff & 1) {
                        if (grid[ni][nj] < visit[ni][nj]) {
                            visit[ni][nj] = grid[ni][nj];
                            // cout << "push " << grid[ni][nj] << " " << ni << " " << nj << "\n";
                            pq.push(vector<int>{grid[ni][nj], ni, nj});
                        }
                    } else {
                        if (grid[ni][nj] + 1 < visit[ni][nj]) {
                            visit[ni][nj] = grid[ni][nj] + 1;
                            // cout << "push " << grid[ni][nj] + 1 << " " << ni << " " << nj << "\n";
                            pq.push(vector<int>{grid[ni][nj] + 1, ni, nj});
                        }
                    }
                } else {
                    visit[ni][nj] = step + 1;
                    // cout << "push " << step + 1 << " " << ni << " " << nj << "\n";
                    pq.push(vector<int>{step + 1, ni, nj});
                }
            }
        }
        return -1;
    }
};
