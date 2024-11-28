/**
 * Title:  Minimum Obstacle Removal to Reach Corner (Leetcode Hard 2290)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, November, 2024
 * Method: View the grid as a graph, each cell is a node, if the destination is wall, then edge weight = 1, otherwise 0. Then use dijkstra to find the shortest path from (0, 0) to (n-1, m-1).
 * Result: Time complexity O(n*m*log(n*m)) since pq can contain up to O(mn) elements. Space complexity O(n*m).
 */

class Solution {
private:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> graph(n*m); // node: <node, dist>
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                    graph[i * m + j].emplace_back(make_pair(ni * m + nj, grid[ni][nj]));
                }
            }
        }
        vector<int> dist(n*m, 1e6);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (dist with 0, node id)
        pq.push(make_pair(0, 0));
        dist[0] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            for (auto& v: graph[u]) {
                if (v.first == n * m - 1) {
                    if (dist[v.first] > dist[u] + v.second) {
                        dist[v.first] = dist[u] + v.second;
                        return dist[v.first];
                    }
                }
                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
        }
        return -1;
    }
};
