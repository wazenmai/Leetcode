/**
 * Title:  01 Matrix (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, August, 2023
 * Method: BFS from 0.
 */

class Solution {
private:
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {-1, 1, 0, 0};
public:
    void printMat(vector<vector<int>>& mat) {
        for (auto row: mat) {
            for (int num: row) {
                cout << num << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        queue<pair<int, int>> q; // i, j (y, x)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push(make_pair(i, j));
                    visit[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ny = node.first + dy[d];
                int nx = node.second + dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                if (!visit[ny][nx]) {
                    ans[ny][nx] = ans[node.first][node.second] + 1;
                    visit[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
        // printMat(ans);
        return ans;
    }
};
