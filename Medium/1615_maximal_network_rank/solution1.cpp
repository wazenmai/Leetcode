/**
 * Title:    Maximal Network Rank (Leetcode Medium)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     18, August, 2023
 * Analysis: Time Complexity O(n^2), Space Complexity O(n^2)
 */

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> rank(n, 0);
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (auto road: roads) {
            rank[road[0]]++;
            rank[road[1]]++;
            graph[road[0]][road[1]] = 1;
            graph[road[1]][road[0]] = 1;
        }
        int max_rank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int network_rank = rank[i] + rank[j];
                if (graph[i][j])
                    network_rank -= 1;
                max_rank = max(network_rank, max_rank);
            }
        }
        return max_rank;
    }
};
