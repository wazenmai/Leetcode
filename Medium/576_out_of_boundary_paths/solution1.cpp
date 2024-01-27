/**
 * Title:  Out of Boundary Paths (Leetcode Medium 576)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Janurary, 2024
 * Method: Use grid to record the number of paths to the boundary. Use cnt to record the number of paths to the current place.
 * Result: Time complexity O(maxMove * m * n), Space complexity O(m * n)
 */

class Solution {
private:
    int mod = 1e9 + 7;
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            grid[i][0]++;
            grid[i][n - 1]++;
        }
        for (int j = 0; j < n; j++) {
            grid[0][j]++;
            grid[m - 1][j]++;
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << grid[i][j] << ", ";
        //     }
        //     cout << "\n";
        // }
        long long ans = 0;
        vector<vector<int>> cnt(m, vector<int>(n, 0));
        queue<pair<int, int>> q; // record the place in cnt
        if (maxMove > 0) {
            cnt[startRow][startColumn] = 1;
            ans += grid[startRow][startColumn];
            q.push(make_pair(startRow, startColumn));
        }
        for (int move = 1; move < maxMove; move++) {
            // update cnt and add grid to ans
            int s = q.size();
            // cout << move << ": " << s << "\n";
            vector<vector<int>> new_cnt(m, vector<int>(n, 0));
            while (s--) {
                auto now = q.front();
                q.pop();
                int t = cnt[now.first][now.second];
                cnt[now.first][now.second] = 0;
                for (int i = 0; i < 4; i++) {
                    int ny = now.first + dy[i];
                    int nx = now.second + dx[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (new_cnt[ny][nx] == 0)
                        q.push(make_pair(ny, nx));
                    new_cnt[ny][nx] += t;
                    new_cnt[ny][nx] %= mod;
                    ans += grid[ny][nx] * t;
                    ans %= mod;
                }
            }
            cnt = new_cnt;
        }
        
        return (int)(ans % mod);
    }
};
