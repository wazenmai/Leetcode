/**
 * Title:  Maximum Total Importance of Roads (Leetcode Medium 2285)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, June, 2024
 * Result: Time complexity is O(nlogn), space complexity is O(n).
 */

class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int> b) {
        return a.first > b.first;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Count the # of road connected by node
        vector<int> degree(n);
        for (auto& road: roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        // Insert them in pair (# of road, index) and sort them large to small
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = make_pair(degree[i], i);
        }
        sort(p.begin(), p.end(), compare);
        // Reuse array to store assigned value of each node
        for (int i = 0; i < n; i++) {
            degree[p[i].second] = n - i;
        }
        // Compute ans
        long long ans = 0;
        for (auto& road: roads) {
            ans += (long long)(degree[road[0]] + degree[road[1]]);
        }
        return ans;
    }
};
