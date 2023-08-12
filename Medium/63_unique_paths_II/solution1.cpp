/**
 * Title:  Maximum Ice Cream Bars (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, August, 2023
 * Method: BFS. dp[i][j] = ways to walk to (i, j). If this block is already in queue, don't push it again.
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dx[2] = {1, 0};
        int dy[2] = {0, 1};
        vector<vector<int>> dp(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));

        // first step check
        if (obstacleGrid[0][0] == 1)
            return 0;
        if (obstacleGrid[0][0] == 0)
            dp[0][0] = 1;

        while (!q.empty()) {
            auto b = q.front();
            q.pop();
            for (int d = 0; d < 2; d++) {
                int ny = b.first + dy[d];
                int nx = b.second + dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                if (obstacleGrid[ny][nx] == 1)
                    continue;
                if (dp[ny][nx] == 0)
                    q.push(make_pair(ny, nx));
                dp[ny][nx] += dp[b.first][b.second];
            }
        }
        return dp[n-1][m-1];
    }
};
