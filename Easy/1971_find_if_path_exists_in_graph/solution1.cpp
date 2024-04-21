/**
 * Title:  Find if Path Exists in Graph (Leetcode Easy 1971)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, April, 2024
 */

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        vector<vector<int>> graph(n);
        for (auto& e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        queue<int> q;
        vector<int> visit(n, false);
        q.push(source);
        visit[source] = true;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int v: graph[cur]) {
                if (v == destination) return true;
                if (visit[v]) continue;
                q.push(v);
                visit[v] = true;
            }
        }
        return false;
    }
};
