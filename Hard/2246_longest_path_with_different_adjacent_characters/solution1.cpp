/**
 * Title:  Longest Path With Different Adjancent Characters (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Janurary, 2023
 */

class Solution {
private:
    int ans;
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[i].emplace_back(parent[i]);
            graph[parent[i]].emplace_back(i);
        }
        ans = 1;
        ans = max(dfs(-1, 0, graph, s), ans);
        return ans;
    }

    int dfs(int prev, int id, vector<vector<int>>& graph, string& s) {
        int zero_path, child_path1, child_path2;
        zero_path = child_path1 = child_path2 = 0;
        for (auto v : graph[id]) {
            if (v != prev) {
                if (s[id] == s[v]) {
                    zero_path = max(zero_path, dfs(id, v, graph, s));
                } else {
                    if (child_path1 == 0) {
                        child_path1 = dfs(id, v, graph, s) + 1;
                    } else if (child_path2 == 0) {
                        child_path2 = dfs(id, v, graph, s) + 1;
                    } else {
                        if (child_path1 < child_path2) {
                            child_path1 = max(child_path1, dfs(id, v, graph, s) + 1);
                        } else {
                            child_path2 = max(child_path2, dfs(id, v, graph, s) + 1);
                        }
                    }
                }
                // cout << id << "->" << v << ": " << zero_path << ", " << child_path1 << ", " << child_path2 << "\n";
            }
        }
        ans = max(ans, zero_path);

        int max_path = max(child_path1, 1);
        if (child_path2 != 0) {
            ans = max(ans, child_path1 + child_path2 - 1);
            max_path = max(max_path, child_path2);
        }
        // cout << id << " " << s[id] << " " << max_path << "\n";
        return max_path;
    }
};
