

class Solution {
private:
    vector<int> ans;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        ans.resize(n);
        for (auto edge: edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        dfs(graph, labels, 0, -1);
        return ans;
    }

    vector<int> dfs(vector<vector<int>>& graph, string& labels, int id, int prev) {
        vector<int> count(26, 0);
        
        for (int v = 0; v < (int)graph[id].size(); v++) {
            if (graph[id][v] != prev) {
                vector<int> res = dfs(graph, labels, graph[id][v], id);

                for (int i = 0; i < 26; i++) {
                    count[i] += res[i];
                }
            }
        }
        count[labels[id] - 'a'] += 1;
        ans[id] = count[labels[id] - 'a'];
        return count;
    }
};