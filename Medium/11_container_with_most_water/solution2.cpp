/**
 * Title:  Container with Most Water (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, April, 2022
 * Method: Fix height and fine the width, O(n)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = (int)height.size() - 1;
        int h = 0;
        int ans = 0;
        while (i < j) {
            h++;
            while (height[i] < h && i < j)
                i++;
            while (height[j] < h && i < j)
                j--;
            ans = max(ans, h * (j - i));
        }
        return ans;
    }
};
