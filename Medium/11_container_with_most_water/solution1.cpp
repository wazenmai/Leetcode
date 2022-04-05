/**
 * Title:  Container with Most Water (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, April, 2022
 * Result: TLE (O(n^2))
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size();
        int width = n - 1;
        int ans = min(height[0], height[width]) * width;
        while (--width) {
            for (int i = 0; i + width <= n - 1; i++) {
                int area = min(height[i], height[i + width]) * width;
                ans = max(area, ans);
            }
        }
        return ans;
    }
};
