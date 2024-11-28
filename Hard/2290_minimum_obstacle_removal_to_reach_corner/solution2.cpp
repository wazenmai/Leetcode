/**
 * Title:  Minimum Obstacle Removal to Reach Corner (Leetcode Hard 2290)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, November, 2024
 * Method: Use a deque + BFS. Maintain a 2D vector to store the minimum obstacle to reach each cell with initial value 1e6. Start from (0, 0), if its neighbor is wall, push_back, otherwise push_front. Every iteration pop_front, and update the neighbor's obstacle value. If reach the destination, return the obstacle value.
 * Result: Time complexity O(n*m) since each cell is visited at most once. Space complexity O(n*m).
 */

class Solution {
private:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        deque<pair<int, int>> dq;
        vector<vector<int>> obstacle(n, vector<int>(m, 1e6));
        dq.push_front(make_pair(0, 0));
        obstacle[0][0] = grid[0][0];
        while (!dq.empty()) {
            auto u = dq.front();
            dq.pop_front();
            for (int d = 0; d < 4; d++) {
                int ni = u.first + di[d];
                int nj = u.second + dj[d];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if (obstacle[ni][nj] != 1e6) continue;
                obstacle[ni][nj] = obstacle[u.first][u.second] + grid[ni][nj];
                if (grid[ni][nj] == 0)
                    dq.push_front(make_pair(ni, nj));
                else
                    dq.push_back(make_pair(ni, nj));
                if (ni == n - 1 && nj == m - 1) {
                    return obstacle[ni][nj];
                }
            }
        }
        return obstacle[ni][nj];
    }
};
