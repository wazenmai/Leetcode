/**
 * Title:  Reconstruct Itinerary (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, September, 2023
 * Method: Use adjacent list to reconstruct tickets, sort the destination by alphabecal order. Then dfs these destination.
 *         Time complexity O(NlogN) // sorting, Space O(N).
 */

class Solution {
private:
    vector<string> ans;
public:
    void dfs(string& airport, unordered_map<string, vector<string>>& graph) {
        while (!graph[airport].empty()) {
            string next = graph[airport].back();
            graph[airport].pop_back();
            dfs(next, graph);
        }
        ans.emplace_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        for (auto& ticket: tickets) {
            graph[ticket[0]].emplace_back(ticket[1]);
        }
        for (auto& [_, destinations]: graph) {
            sort(destinations.rbegin(), destinations.rend());
        }
        string temp = "JFK";
        dfs(temp, graph);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
