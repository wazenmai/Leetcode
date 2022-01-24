/**
 * Title:  Minimum Number of Arrows to Burst Balloons (Leetcode Medium 452)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Jan, 2022
 * Method: sort the end, then use the end as arrow.
 */

class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        // if (a[1] == b[1])
        //     return a[0] < b[0];
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), Solution::cmp);
        
        int ans = 1;
        int balloons = points.size();
        int arrow = points[0][1];
        
        for (int i = 1; i < balloons; i++) {
            if (points[i][0] <= arrow && arrow <= points[i][1])
                continue;
            ans += 1;
            arrow = points[i][1];
        }
        return ans;
    }
};