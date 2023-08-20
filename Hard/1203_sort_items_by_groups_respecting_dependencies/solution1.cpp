/**
 * Title:  Sort Items by Groups Respecting Dependencies (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, August, 2023
 * Method: Topological Sort Groups -> Topological Sort Items (inside group). Time Complexity: O(n). Space Complexity: O(n).
 */

class Solution {
public:
    void printGraph(vector<vector<int>>& g, int n) {
        for (int i = 0; i < n; i++) {
            if (g[i].empty())
                continue;
            cout << i << ": ";
            for (int b: g[i]) {
                cout << b << " ";
            }
            cout << "\n";
        }
    }
    void printDegree(vector<int>& v, int n) {
        for (int i = 0; i < n; i++)
            cout << "(" << i << "," << v[i] << ") ";
        cout << "\n";
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        // Step 1. Construct new group
        vector<vector<int>> new_group(m);
        int g = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                new_group.emplace_back(vector<int>{i});
                group[i] = g;
                g++;
            } else {
                new_group[group[i]].emplace_back(i);
            }
        }
        // cout << "groups: " << g << "\n";
        // cout << "===Group===\n";
        // printGraph(new_group, g);
        
        // Step 2. Construct group topo graph
        vector<vector<int>> graph(n);
        vector<vector<int>> group_graph(g);
        vector<int> indegree(n, 0);
        vector<int> group_indegree(g, 0);
        for (int i = 0; i < n; i++) {
            for (int item: beforeItems[i]) {
                graph[item].emplace_back(i);
                indegree[i]++;
                if (group[item] != group[i]) {
                    group_graph[group[item]].emplace_back(group[i]);
                    group_indegree[group[i]]++;
                }
            }
        }
        // cout << "---Group Graph---\n";
        // printGraph(group_graph, g);
        // cout << "---Group Indegree---\n";
        // printDegree(group_indegree, g);

        vector<int> ans;
        queue<int> q; // group topo queue
        for (int i = 0; i < g; i++)
            if (group_indegree[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int gp = q.front();
            q.pop();
            // topo sort for items in group
            queue<int> iq; // item topo queue
            for (int item: new_group[gp])
                if (indegree[item] == 0)
                    iq.push(item);
            while (!iq.empty()) {
                int u = iq.front();
                iq.pop();
                ans.emplace_back(u);
                // clear indegree for item
                for (int v: graph[u]) {
                    --indegree[v];
                    if (indegree[v] == 0 && group[v] == gp)
                        iq.push(v);
                }
            }
            // clear indegree for groups
            for (int h: group_graph[gp]) {
                --group_indegree[h];
                if (group_indegree[h] == 0)
                    q.push(h);
            }
        }
        if (ans.size() != n)
            return vector<int>{};
        return ans;
    }
};
