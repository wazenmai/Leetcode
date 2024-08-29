/**
 * Title:  Count Sub Islands (Leetcode Medium 1905)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, August, 2024
 * Method: BFS. First construct a map from grid1 index to island group, then construct a list of islands in the second grid. Finally, iterate the list of islands in the second grid to check if it is a sub island inside same grid1 island group.
 * Result: Time complexity is O(3 * n * m), space complexity is O(6 * n * m).
 */

class Solution {
private:
    int dj[4] = {0, 0, -1, 1};
    int di[4] = {-1, 1, 0, 0};
    int n;
    int m;
public:
    unordered_map<int, int> assign_island_group(vector<vector<int>>& grid) {
        unordered_map<int, int> grid_to_island;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int islands = 0;
        // iterate grid to assign island group
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j] || grid[i][j] == 0) continue;
                q.push(make_pair(i, j));
                visit[i][j] = true;
                grid_to_island[i * m + j] = ++islands;
                while (!q.empty()) {
                    auto u = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int ni = u.first + di[d];
                        int nj = u.second + dj[d];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                        if (visit[ni][nj] || grid[ni][nj] == 0) continue;
                        grid_to_island[ni * m + nj] = islands;
                        visit[ni][nj] = true;
                        q.push(make_pair(ni, nj));
                    }
                }
            }
        }
        return grid_to_island;
    }
    vector<vector<pair<int, int>>> assign_island_list(vector<vector<int>>& grid) {
        vector<vector<pair<int, int>>> res;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        // iterate grid to assign island group
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j] || grid[i][j] == 0) continue;
                vector<pair<int, int>> v;
                q.push(make_pair(i, j));
                visit[i][j] = true;
                while (!q.empty()) {
                    auto u = q.front();
                    q.pop();
                    v.emplace_back(make_pair(u.first, u.second));
                    for (int d = 0; d < 4; d++) {
                        int ni = u.first + di[d];
                        int nj = u.second + dj[d];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                        if (visit[ni][nj] || grid[ni][nj] == 0) continue;
                        visit[ni][nj] = true;
                        q.push(make_pair(ni, nj));
                    }
                }
                res.emplace_back(v);
            }
        }
        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        unordered_map<int, int> first_grid = assign_island_group(grid1);
        vector<vector<pair<int, int>>> second_grid_list = assign_island_list(grid2);
        int ans = 0;
        for (auto& island: second_grid_list) {
            int total = island.size();
            int id = first_grid[island[0].first * m + island[0].second];
            if (id == 0) continue;
            bool check = true;
            for (int i = 1; i < total; i++) {
                if (first_grid[island[i].first * m + island[i].second] != id) {
                    check = false;
                    break;
                }
            }
            if (check) ans++;
        }
        return ans;
    }
};
