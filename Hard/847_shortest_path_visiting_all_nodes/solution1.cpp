/**
 * Title:  Shortest Path Visiting All Nodes (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Feb, 2022
 * Method: BFS, use bit manipulation to record the state
 */

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int, int>> q; // state, number
        int n = (int)graph.size();
        int q_size = 0;
        int path = 0;
        int check = 0;
        vector<vector<int>> visit(n, vector<int>(1 << n));
        
        // first node
        for (int i = 0; i < n; i++) {
            q.push(make_pair((1 << i), i));
            visit[i][1 << i] = 1;
            check |= (1 << i);
        }
        
        // cout << n << " " << (1 << n) << "\n";
        
        while (!q.empty()) {
            int q_size = (int)q.size();
            // cout << "q_size: " << q_size << "\n";
            for (int i = 0; i < q_size; i++) {
                auto top = q.front();
                q.pop();
                if (top.first == check)
                    return path;
                // cout << "take " << top.second << ", " << top.first << "\n";
                for (auto& node : graph[top.second]) {
                    int temp = top.first | (1 << node);
                    if (!visit[node][temp]) {
                        q.push(make_pair(temp, node));
                        visit[node][temp] = 1;
                    }
                }
            }
            path++;
        }
        return path;
    }
};
