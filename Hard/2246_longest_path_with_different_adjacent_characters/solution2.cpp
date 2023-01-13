/**
 * Title:  Longest Path With Different Adjancent Characters (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Janurary, 2023
 * Result: Improve speed 66% -> 94%, memory 27% -> 78%
 */

class Solution {
private:
    int ans;
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[parent[i]].emplace_back(i);
        }
        ans = max(dfs(0, graph, s), ans);
        return ans;
    }

    int dfs(int id, vector<vector<int>>& graph, string& s) {
        if (graph[id].empty())
            return 1;
        int child_path1, child_path2;
        child_path1 = child_path2 = 1;
        for (auto v : graph[id]) {
            if (s[id] == s[v]) { // can't connect through parent
                ans = max(ans, dfs(v, graph, s));
            } else {
                if (child_path1 <= child_path2)
                    child_path1 = max(child_path1, dfs(v, graph, s) + 1);
                else
                    child_path2 = max(child_path2, dfs(v, graph, s) + 1);
            }
        }
        ans = max(ans, child_path2 + child_path1 - 1); // count the path through parent
        return max(child_path1, child_path2); // return only longest path
    }
};
