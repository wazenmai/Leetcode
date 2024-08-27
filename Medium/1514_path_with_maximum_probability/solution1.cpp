/**
 * Title:  Path with Maximum Probability (Leetcode Medium 1514)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, August, 2024
 * Method: Dijkstra.
 * Result: Time complexity is O(m + nlogn) when using Fibonacci heap or O(n + mlogn) when using Binary heap, space complexity is O(n + m).
 */

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n); // (node, edge)
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(make_pair(edges[i][1], succProb[i]));
            graph[edges[i][1]].emplace_back(make_pair(edges[i][0], succProb[i]));
        }
        priority_queue<pair<double, int>> pq;
        vector<bool> visit(n, false);
        pq.push(make_pair(1, start_node));
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            if (visit[u.second]) continue;
            // cout << u.second << ": " << u.first << "\n";
            if (u.second == end_node) {
                return u.first;
            }
            visit[u.second] = true;
            for (auto& v: graph[u.second]) {
                if (visit[v.first]) continue;
                pq.push(make_pair(v.second * u.first, v.first));
            }
        }
        return 0;
    }
};
