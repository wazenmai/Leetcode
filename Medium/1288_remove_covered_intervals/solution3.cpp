/**
 * Title:  Remove Covered Intervals (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, Feb, 2022
 */

class Solution {
private:
    void print_vec(vector<int>& nums) {
        cout << "[";
        for (auto& x : nums)
            cout << x << " ";
        cout << "], ";
    }
public:
    static bool cmp(vector<int>& a, vector<int> b) {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = (int)intervals.size();
        vector<bool> del_list(n, false);
        int del = 0;
        int tg = 0;
        while (tg < n) {
            for (int i = tg + 1; i < n; i++) {
                if (del_list[i])
                    continue;
                if (intervals[i][0] >= intervals[tg][0]) {
                    del_list[i] = true;
                    del++;
                }
            }
            tg++;
        }
        return n - del;
    }
};
