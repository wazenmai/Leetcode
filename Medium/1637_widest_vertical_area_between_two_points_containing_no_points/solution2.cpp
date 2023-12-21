/**
 * Title:  Widest Vertical Area Between Two Points Containing No Points (Leetcode Medium 1637)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, December, 2023
 * Method: Vector sorting.
 * Result: Time complexity O(nlogn), Space complexity O(1)
 */

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int diff = 0;
        int n = points.size();
        for (int i = 1; i < n; i++) {
            diff = max(diff, points[i][0] - points[i - 1][0]);
        }
        return diff;
    }
};
