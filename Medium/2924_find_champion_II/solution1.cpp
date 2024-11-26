/**
 * Title:  Find Champion II (Leetcode Medium 2924)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, November, 2024
 * Result: Time complexity O(n), space complexity O(n).
 */

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto& e: edges) {
            indegree[e[1]]++;
        }
        int zeros = 0, id = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                zeros++;
                id = i;
            }
        }
        return (zeros == 1) ? id : -1;
    }
};
