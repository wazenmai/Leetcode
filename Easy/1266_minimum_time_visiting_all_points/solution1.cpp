/**
 * Title:  Minimum Time Visiting All Pointws (Leetcode Easy 1266)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, December, 2023
 */

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int x = points[0][0], y = points[0][1];
        int n = points.size();
        for (int i = 1; i < n; i++) {
            ans += max(abs(points[i][0] - x), abs(points[i][1] - y));
            x = points[i][0];
            y = points[i][1];
        }
        return ans;
    }
};
