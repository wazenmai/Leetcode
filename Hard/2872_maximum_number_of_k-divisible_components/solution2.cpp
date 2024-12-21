/**
 * Title:  Maximum Number of K-Divisible Components (Leetcode Hard 2872)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, December, 2024
 * Method: Topological sort. Start by the leaf nodes and propagate the value to the parent node. If the value is divisible by k, increment the answer.
 * Result: Time complexity O(n + m), Space complexity O(n). m is the number of edges.
 */

class Solution {
public:
    int maxKDivisibleComponents(int n, const vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n < 2) return 1;
        vector<vector<int>> graph(n);
        vector<int> in_degree(n, 0);
        int ans = 0;
        for (const auto& e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
            in_degree[e[0]]++;
            in_degree[e[1]]++;
        }

        vector<long long> sum(values.begin(), values.end());
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_degree[u]--;

            long long s = 0;
            // Check if current node is divisible by k
            if (sum[u] % k == 0) {
                ans++;
            } else {
                s = sum[u];
            }

            // Propagate the value to the neighbor
            for (const int v: graph[u]) {
                if (in_degree[v] == 0) continue;
                in_degree[v]--;
                sum[v] += s;
                if (in_degree[v] == 1) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
