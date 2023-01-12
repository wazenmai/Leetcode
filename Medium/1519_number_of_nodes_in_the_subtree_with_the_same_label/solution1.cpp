/**
 * Title:  Number of Nodes in the Sub-Tree With the Same Label (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Janurary, 2023
 * Result: TLE
 */

class Solution {
private:
    vector<int> ans;
    vector<bool> visit;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        ans = vector<int>(n, 0);
        visit = vector<bool>(n, false);
        for (auto edge: edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        vector<int> parent;
        dfs(graph, labels, 0, parent);
        return ans;
    }

    void dfs(vector<vector<int>>& graph, string labels, int id, vector<int>& parent) {
        if (visit[id])
            return;
        // cout << id << ": ";
        // for (auto p: parent) {
        //     cout << p << " ";
        // }
        // cout << "\n";
        visit[id] = true;
        parent.emplace_back(id);
        for (auto v: graph[id]) {
            dfs(graph, labels, v, parent);
        }
        for (auto p : parent) {
            if (labels[id] == labels[p]) {
                ans[p]++;
            }
        }
        parent.pop_back();
    }
};
