/**
 * Title:  Modify Graph Edge Weights (Leetcode Hard 2699)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, August, 2024
 * Method: Dijkstra. First calculate shortest path with -1 edges, if it's less than target, return empty vector. If it's equal to target, mark -1 edges to inf.
 *         Then check whether shortest path with -1 -> 1 edges is smaller than target, if new distance <= target, modify edge to 1 + target - newd. The rest of -1 edge should be inf.
 * Result: Time compleixty is O((V + E)logE) for Dijkstra, so the total time complexity is O(E(V + E)logE). Space compleixty is O(V^2) for graph, O(V + E) for Dijkstra.
 */

class Solution {
public:
    int dijkstra(int n, vector<vector<int>>& graph, int source, int destination) {
        vector<int> visit(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            if (visit[u.second]) continue;
            if (u.second == destination) return u.first;
            visit[u.second] = true;
            for (int i = 0; i < n; i++) {
                if (graph[u.second][i] == 0 || graph[u.second][i] == -1) continue;
                if (visit[i]) continue;
                pq.push(make_pair(u.first + graph[u.second][i], i));
            }
        }
        return 2e9;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (auto& e: edges) {
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
        }
        // 1. Check whether distance of path without (-1) from source to destination is less than or equal to target
        int initial_dist = dijkstra(n, graph, source, destination);
        // 1.1 No matter how we modify edges, it's not shortest path
        if (initial_dist < target) return vector<vector<int>>{};
        // 1.2 It already find correct path, mark -1 edges to inf (as they not exist)
        if (initial_dist == target) {
            for (auto& edge: edges) {
                if (edge[2] == -1) edge[2] = 2e9;
            }
            return edges;
        }

        // 2. Check whether distance of path (-1 -> 1) from source to destination is larger than target
        bool meetTarget = false;
        for (auto& edge: edges) {
            if (edge[2] > 0) continue;
            edge[2] = meetTarget ? 2e9 : 1;
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
            if (!meetTarget) {
                int newd = dijkstra(n, graph, source, destination);
                if (newd <= target) {
                    meetTarget = true;
                    edge[2] += target - newd;
                }
            }
        }
        return (meetTarget) ? edges : vector<vector<int>>{};
    }
};
