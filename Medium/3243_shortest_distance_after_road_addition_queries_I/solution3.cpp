/**
 * Title:  Shortest Distance After Road Addition Queries I (Leetcode Medium 3243)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, November, 2024
 * Method: Use dp array, where dp[i] = distance from node i to n - 1. dp[i] = min(dp[i], dp[j] + 1) for all j in graph[i].
 * Result: Time complexity O(m * (n + m)). Space complexity O(n + m).
 */


class Solution {
public:
    int find_distance(vector<vector<int>>& graph, vector<int>& dp, int n, int cur) {
        if (cur == n - 1) return 0;
        if (dp[cur] != -1) return dp[cur];
        int dist = n;
        for (auto& v: graph[cur]) {
            dist = min(dist, 1 + find_distance(graph, dp, n, v));
        }
        return dp[cur] = dist;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph[i].emplace_back(i + 1);
        }
        vector<int> ans;
        for (auto& q: queries) {
            graph[q[0]].emplace_back(q[1]);
            vector<int> dp(n, -1);
            ans.emplace_back(find_distance(graph, dp, n, 0));
        }
        return ans;
    }
};

// dist(v, n - 1) = min_j(dist(v, j) + dist(j, n - 1))
