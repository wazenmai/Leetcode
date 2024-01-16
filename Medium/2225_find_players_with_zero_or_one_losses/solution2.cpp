/**
 * Title:  Find Players With Zero or One LOsses (Leetcode Medium 2225)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Janurary, 2024
 * Method: Use one unordered_map to record the number of losses of each player, then sort them in vector.
 * Result: Time complexity O(nlogn). Space complexity O(n). Runtime 434 ms, Memory 161.67 MB.
 */

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int, int> lose;
        for (auto& match: matches) {
            lose[match[1]]++;
        }
        for (auto& match: matches) {
            if (lose.find(match[0]) == lose.end()) {
                ans[0].emplace_back(match[0]);
                lose[match[0]] = 2; // avoid to add winnder in ans[0] again
            }
            if (lose[match[1]] == 1) {
                ans[1].emplace_back(match[1]);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
