/**
 * Title:  Non-Overlapping Intervals (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, July, 2023
 * Method: Sort and choose the non-overlapping one. Time complexity O(nlogn)
 */

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    void printInterval(vector<vector<int>>& v) {
        for (auto i: v) {
            cout << "(" << i[0] << "," << i[1] << "), ";
        }
        cout << "\n";
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        // printInterval(intervals);
        int end = -60000;
        int remove = 0;
        for (auto interval: intervals) {
            if (interval[0] >= end) {
                end = interval[1];
            } else {
                remove++;
            }
        }
        return remove;
    }
};
