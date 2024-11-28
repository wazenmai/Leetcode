/**
 * Title:  Shortest Distance After Road Addition Queries I (Leetcode Medium 3243)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, November, 2024
 * Method: Use dijkstra algorithm to find shortest path for each query.
 * Result: Time complexity O(m * nlog(n)), where m is the number of queries, n is the number of nodes. Space complexity O(n + m).
 */

class Solution {
public:
    int dijkstra(vector<vector<int>>& graph, vector<int>& dist, int st, int ed) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, st));
        vector<bool> visit(ed + 1, false);
        visit[st] = true;
        bool find = false;
        while (!pq.empty()) {
            auto [dis, u] = pq.top();
            pq.pop();
            // cout << u << ", " << dis << ": ";
            for (auto& v: graph[u]) {
                if (visit[v]) continue;
                if (v == ed) {
                    if (dis + 1 < dist[v]) {
                        // cout << "(" << v << "," << dist[v] << "->" << dis + 1 << ") ";
                        dist[v] = dis + 1;
                    }
                    find = true;
                    break;
                }
                if (dis + 1 <= dist[v]) {
                    // cout << "(" << v << "," << dist[v] << "->" << dis + 1 << ") ";
                    dist[v] = dis + 1;
                    visit[v] = true;
                    pq.push(make_pair(dist[v], v));
                }
            }
            // cout << "\n";
            if (find) break;
        }
        return dist[ed];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        vector<int> dist(n, 0);
        for (int i = 0; i < n - 1; i++) {
            graph[i].emplace_back(i + 1);
            dist[i] = i;
        }
        dist[n - 1] = n - 1;
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            auto q = queries[i];
            // cout << "query " << q[0] << "," << q[1] << "\n";
            graph[q[0]].emplace_back(q[1]);
            if (dist[n - 1] == 1)
                ans[i] = 1;
            else
                ans[i] = dijkstra(graph, dist, 0, n - 1);
        }
        return ans;
    }
};
