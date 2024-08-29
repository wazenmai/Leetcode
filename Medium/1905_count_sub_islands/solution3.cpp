/**
 * Title:  Count Sub Islands (Leetcode Medium 1905)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, August, 2024
 * Method: UnionFind. First merge land in grid2, then check whether land in grid2 is also in grid1.
 * Result: Time complexity is O(3 * n * m), space complexity is O(2 * n * m).
 */

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
private:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        UnionFind uf = UnionFind(m * n);
        // Traverse `grid2` to merge land
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 0) continue;
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                    if (grid2[ni][nj] == 0) continue;
                    uf.merge(i * m + j, ni * m + nj);
                }
            }
        }
        // check whether land in grid2 is also in grid1
        vector<bool> isSubIsland(n * m, true);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid1[i][j] == 0 && grid2[i][j] == 1) {
                    int root = uf.find(i * m + j);
                    isSubIsland[root] = false;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    int root = uf.find(i * m + j);
                    if (isSubIsland[root]) {
                        ans++;
                        isSubIsland[root] = false;
                    }
                }
            }
        }
        return ans;
    }
};
