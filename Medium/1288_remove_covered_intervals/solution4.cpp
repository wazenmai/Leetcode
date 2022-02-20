/**
 * Title:  Remove Covered Intervals (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, Feb, 2022
 * Method: O(nlogn) time for sorting, O(1) memory
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = (int)intervals.size();
        int l = intervals[0][0];
        int r = intervals[0][1];
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] > l && intervals[i][1] > r)
                res++;
            if (intervals[i][1] > r) {
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        return res;
    }
};
