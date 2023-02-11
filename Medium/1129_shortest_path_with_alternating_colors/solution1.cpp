/**
 * Title:  Shortest Path with Alternating Colors (Leetcode Medium 1129)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, Feburary, 2023
 * Method: BFS. O(n + e)
 */

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n);
        
        vector<int> ans(n, -1);
        ans[0] = 0;

        for (auto edge: redEdges) {
            graph[edge[0]].emplace_back(make_pair(edge[1], 0)); // red = 0
        }
        for (auto edge: blueEdges) {
            graph[edge[0]].emplace_back(make_pair(edge[1], 1)); // blue = 1
        }

        queue<vector<int>> q;

        for (int i = 1; i < n; i++) {
            // from 0 to i
            // cout << "node " << i << "\n";
            vector<vector<bool>> visit(n, vector<bool>(2, false));
            q.push({0, 0, 0}); // node, color, step
            q.push({0, 1, 0});
            while (!q.empty()) {
                auto now = q.front();
                // cout << "  " << now[0] << " " << now[1] << " " << now[2] << "\n";
                q.pop();
                visit[now[0]][now[1]] = true;
                for (auto node: graph[now[0]]){
                    if (node.second != now[1]) {
                        if (node.first == i) {
                            ans[i] = (ans[i] == -1) ? now[2] + 1 : min(now[2] + 1, ans[i]);
                        }
                        if (!visit[node.first][node.second]) {
                            visit[node.first][node.second] = true;
                            q.push({node.first, node.second, now[2] + 1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};