/**
 * Title:  Shortest Distance After Road Addition Queries I (Leetcode Medium 3243)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, November, 2024
 * Method: Use bfs to find shortest path from 0 to n instead of dijkstra.
 * Result: Time complexity O(m * (n + m))), where m is the number of queries, n is the number of nodes. Space complexity O(n + m).
 */

class Solution {
public:
    int bfs(vector<vector<int>>& graph, int n) {
        queue<int> q;
        q.push(0);
        vector<bool> visit(n, false);
        visit[0] = true;
        int step = 0;
        while (!q.empty()) {
            int s = q.size();
            step++;
            for (int i = 0; i < s; i++) {
                auto u = q.front();
                q.pop();
                for (auto& v: graph[u]) {
                    if (visit[v]) continue;
                    if (v == n - 1) return step;
                    q.push(v);
                    visit[v] = true;
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph[i].emplace_back(i + 1);
        }
        
        for (int j = 0; j < m; j++) {
            if (j > 0 && ans[j - 1] == 1) {
                ans[j] = 1;
                continue;
            }
            auto query = queries[j];
            graph[query[0]].emplace_back(query[1]);
            ans[j] = bfs(graph, n);
        }
        return ans;
    }
};
