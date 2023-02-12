/**
 * Title:  Minimum Fuel Cost to Report to the Capital (Leetcode Medium 2477)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Feburary, 2023
 * Method: BFS from leaf node to 0
 */

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (auto road: roads) {
            graph[road[0]].emplace_back(road[1]);
            graph[road[1]].emplace_back(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }

        long long ans = 0;
        queue<int> q;
        vector<int> representatives(n, 1); // the representitives on the node

        for (int i = 1; i < n; i++) {
            if (degree[i] == 1) { // leaf node
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            
            ans += ceil((double)representatives[now] / seats);
            // one neighbor
            for (auto node: graph[now]) {
                degree[node]--;
                representatives[node] += representatives[now];
                if (degree[node] == 1 && node != 0)
                    q.push(node);
            }
        }

        return ans;
    }
};
