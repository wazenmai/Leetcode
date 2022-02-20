/**
 * Title:  Remove Covered Intervals (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, Feb, 2022
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        unordered_set<int> del_list;
        int n = (int)intervals.size();
        int del = 0;
        int tg = 0;
        while (tg < n) {
            for (int i = 0; i < n; i++) {
                if (i == tg)
                    continue;
                if (del_list.count(i))
                    continue;
                if (intervals[i][0] >= intervals[tg][0] && intervals[i][1] <= intervals[tg][1]) {
                    del_list.insert(i);
                    del++;
                }
            }
            tg++;
        }
        return n - del;
    }
};
