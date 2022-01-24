/**
 * Title:  Is Graph Bipartite? (Leetcode Medium 785)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, Mar, 2021
 */

// greedy
class Solution {
private:
    vector<int> color(105, 0);
    bool dfs(vector<vector<int>>& G, int u, int c) {
        for(int v: G[u]) {
            if (color[v] == c)
                return false;
            if (color[v] == 0){
                color[v] = 3 - v;
                dfs(G, v, color[v]);
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       color[0] = 1;
       bool ans = true;
       for(int i = 0; i < n; i++) {
           ans = ans & (dfs(graph, i, 1));
       }
       return ans;
    }
};
