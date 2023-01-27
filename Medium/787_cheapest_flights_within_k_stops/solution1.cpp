/**
 * Title:  Cheapest Flights Within K Stops (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Janurary, 2023
 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        queue<vector<int>> q; // node, price, step
        vector<int> cost(n, INT_MAX);
        int ans = INT_MAX;
        for(auto& flight: flights) {
            graph[flight[0]].emplace_back(make_pair(flight[1], flight[2]));
        }
        q.push({src, 0, 0});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            // cout << node[0] << ", price: " << node[1] << ", step: " << node[2] << "\n";
            cost[node[0]] = min(cost[node[0]], node[1]);
            if (node[0] == dst)
                ans = min(ans, node[1]);
            if (node[2] == k + 1) {
                continue;
            }
            for (auto& neighbor: graph[node[0]]) {
                if (node[2] < k + 1 && node[1] + neighbor.second <= cost[neighbor.first]) {
                   q.push({neighbor.first, node[1] + neighbor.second, node[2] + 1});
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
