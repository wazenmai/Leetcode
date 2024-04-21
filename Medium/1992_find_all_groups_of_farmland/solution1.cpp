/**
 * Title:  Find All Groups of Farmland Medium 1992)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, April, 2024
 */

class Solution {
private:
    int di[2] = {1, 0};
    int dj[2] = {0, 1};
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j] || land[i][j] == 0) continue;
                vector<int> temp{i, j};
                int br_i = -1, br_j = -1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visit[i][j] = true;
                while (!q.empty()) {
                    auto cur = q.front();
                    if (cur.first > br_i || cur.second > br_j) {
                        br_i = cur.first;
                        br_j = cur.second;
                    }
                    q.pop();
                    for (int d = 0; d < 2; d++) {
                        int ni = cur.first + di[d];
                        int nj = cur.second + dj[d];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                        if (visit[ni][nj] || land[ni][nj] == 0) continue;
                        q.push(make_pair(ni, nj));
                        visit[ni][nj] = true;
                    }
                }
                temp.emplace_back(br_i);
                temp.emplace_back(br_j);
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};
