/**
 * Title:  Trapping Rain Water (Leetcode Hard 42)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, April, 2024
 * Method: Use stack to record the left walls and calculate the trapped water.
 * Result: Time complexity is O(n), space complexity is O(n). n = height.size().
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        stack<pair<int, int>> wall; // pos, height
        int prev_wall = 0;
        for (int i = 0; i < n; i++) {
            // Jump only floor
            if (wall.empty() && height[i] == 0) continue;
            
            // Count for trapping
            if (!wall.empty() && height[i] > wall.top().second) {
                while (!wall.empty() && height[i] >= wall.top().second) {
                    if (wall.top().second != prev_wall) {
                        ans += (wall.top().second - prev_wall) * (i - wall.top().first - 1);
                    }
                    prev_wall = wall.top().second;
                    wall.pop();
                }
                if (!wall.empty() && wall.top().second > height[i]) {
                    ans += (height[i] - prev_wall) * (i - wall.top().first - 1);
                }
            }

            // Add possible left walls
            if (wall.empty() || height[i] <= wall.top().second) {
                wall.push(make_pair(i, height[i]));
                prev_wall = height[i];
            }
        }
        return ans;
    }
};
// wall: (0,4) , height=(3,3), prev_wall=2, ans=2
// 4 2 0 3 2 5
//      *
// *....*
// *..*.*
// **.***
// **.***