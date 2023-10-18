/**
 * Title:  Parallel Courses III (Leetcode Hard 2050)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, October, 2023
 * Method: DFS from the end node, and update the cost of each node. The answer is the max of all start node cost.
 * Result: Time complexity O(E + V), Space complexity O(V + E)
 */

class Solution {
public:
    void printvec(vector<vector<int>>& v, int n) {
        for (int i = 1; i <= n; i++) {
            cout << i << ": ";
            for (auto& e: v[i])
                cout << e << " ";
            cout << "\n";
        }
    }
    void printdegree(vector<int>& v) {
        for (auto& e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
    void dfs(int i, int t, vector<int>& cost, vector<vector<int>>& graph, vector<int>& time) {
        if (graph[i].empty()) {
            cost[i] = max(cost[i], t + time[i - 1]);
            // cout << "cost of " << i << ": " << cost[i] << "\n";
        }
        for (auto& v: graph[i]) {
            if (cost[v] < t + time[i - 1] + time[v - 1]) {
                cost[v] = t + time[i - 1] + time[v - 1];
                dfs(v, t + time[i - 1], cost, graph, time);
            }
        }
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // vector<vector<int>> graph(n + 1);
        vector<vector<int>> parent(n + 1);
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        vector<int> cost(n + 1, 0);
        for (auto& relation: relations) {
            // graph[relation[0]].emplace_back(relation[1]);
            parent[relation[1]].emplace_back(relation[0]);
            indegree[relation[1]]++;
            outdegree[relation[0]]++;
        }
        // printvec(parent, n);
        // cout << "indegree: ";
        // printdegree(indegree);
        // cout << "outdegree: ";
        // printdegree(outdegree);

        for (int i = 1; i <= n; i++) {
            if (outdegree[i] == 0) {
                // cout << "dfs " << i << "\n";
                dfs(i, 0, cost, parent, time);
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0)
                ans = max(ans, cost[i]);
        }
        return ans;
    }
};
