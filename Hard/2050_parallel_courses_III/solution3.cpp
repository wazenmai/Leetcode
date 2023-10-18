/**
 * Title:  Parallel Courses III (Leetcode Hard 2050)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, October, 2023
 * Method: DFS every node and update the cost of each node, the answer is the maximum of all node cost.
 * Result: Time complexity O(E + V), Space complexity O(V + E)
 */

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> memo;
public:
    int dfs(int node, vector<int>& time) {
        if (memo[node] != -1) return memo[node];
        if (graph[node].size() == 0) return memo[node] = time[node - 1];

        int ans = 0;
        for (int neighbor: graph[node]) {
            ans = max(ans, dfs(neighbor, time));
        }
        return memo[node] = time[node - 1] + ans;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        graph.resize(n + 1);

        for (auto& relation: relations) {
            graph[relation[0]].emplace_back(relation[1]);
        }
        memo = vector(n + 1, -1);
        int ans = 0;
        for (int node = 1; node <= n; node++) {
            ans = max(ans, dfs(node, time));
        }
        return ans;
    }
};
