/**
 * Title:  Find the Longest Valid Obstacle Course at Each Position (Leetcode Hard 1964)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, November, 2024
 * Method: LIS. Use built_in function `upper_bound` to find the pointer of the first element that is greater than the current element.
 * Result: Time complexity is O(nlogn), space complexity is O(n).
 */

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> lis;
        lis.emplace_back(obstacles[0]);
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            if (obstacles[i] >= lis.back()) {
                lis.emplace_back(obstacles[i]);
                ans[i] = (int)lis.size();
            } else {
                auto it = upper_bound(lis.begin(), lis.end(), obstacles[i]);
                ans[i] = (it - lis.begin()) + 1;
                *it = obstacles[i];
            }
        }
        return ans;
    }
};
