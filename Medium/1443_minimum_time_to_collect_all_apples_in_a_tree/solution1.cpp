/**
 * Title:  Minimum Time to Collect All Apples in a Tree (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, Janurary, 2023
 * Method: View tree as graph, and calculate child steps by dfs and return
 */

class Solution {
private:
    vector<bool> visit;
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        visit = vector<bool>(n, false);
        for (auto edge: edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        return dfs(graph, hasApple, 0, 0); // node, cost
    }

    int dfs(vector<vector<int>>& graph, vector<bool>& hasApple, int node, int cost) {
        if (visit[node])
            return 0;
        visit[node] = true;
        int child_cost = 0;
        for (int v: graph[node]) {
            child_cost += dfs(graph, hasApple, v, 2);
        }
        if (child_cost == 0 && !hasApple[node])
            return 0;
        return child_cost + cost;
    }
};
