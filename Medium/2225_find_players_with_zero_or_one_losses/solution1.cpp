/**
 * Title:  Find Players With Zero or One LOsses (Leetcode Medium 2225)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Janurary, 2024
 * Method: Use map to record the number of wins and losses of each player with sorted order.
 * Result: Time complexity O(nlogn). Space complexity O(n). Runtime 588 ms, Memory 169.75 MB.
 */

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> lose; // lose[i] = 1 means player i lose 1 matches
        map<int, int> win; // win[i] = 1 means player i win 1 matches
        for (auto& match : matches) {
            win[match[0]]++;
            lose[match[1]]++;
        }
        for (auto it = win.begin(); it != win.end(); it++) {
            if (lose.find(it->first) == lose.end()) {
                ans[0].emplace_back(it->first);
            }
        }
        for (auto it = lose.begin(); it != lose.end(); it++) {
            if (it->second == 1)
                ans[1].emplace_back(it->first);
        }
        return ans;
    }
};
