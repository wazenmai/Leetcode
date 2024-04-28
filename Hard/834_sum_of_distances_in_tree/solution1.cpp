/**
 * Title:  Sum of Distances in Tree (Leetcode Hard 834)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, April, 2024
 * Method: First dfs to find the root's children's sum and res, then dfs to find the other node's res. 
 * Result: Time complexity is O(n), space complexity is O(n). (Use Folyd-Warshall to solve this problem is O(n^3) - TLE)
 */

class Solution {
public:
    void helper(vector<vector<int>>& graph, int cur, int pre, vector<int>& cnt, vector<int>& res) {
        for (int i : graph[cur]) {
            if (i == pre) continue;
            helper(graph, i, cur, cnt, res);
            cnt[cur] += cnt[i];
            res[cur] += res[i] + cnt[i];
        }
        cnt[cur]++;
    }
    void helper2(vector<vector<int>>& graph, int cur, int pre, vector<int>& cnt, vector<int>& res) {
        for (int i : graph[cur]) {
            if (i == pre) continue;
            res[i] = res[cur] - cnt[i] + cnt.size() - cnt[i]; // i's children:- cnt[i], the other node for i: +(N - cnt[i])
            helper2(graph, i, cur, cnt, res);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> res(n);
        vector<int> cnt(n);
        vector<vector<int>> graph(n);
        for (auto& e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        
        helper(graph, 0, -1, cnt, res);
        helper2(graph, 0, -1, cnt, res);
        return res;
    }
};
