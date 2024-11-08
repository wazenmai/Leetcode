/**
 * Title:  Find the Longest Valid Obstacle Course at Each Position (Leetcode Hard 1964)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, November, 2024
 * Method: Implement binary search by hand.
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

        function<int(int)> bs = [&](int val) {
            int l = 0, r = lis.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (lis[mid] > val) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };

        for (int i = 1; i < n; i++) {
            if (obstacles[i] >= lis.back()) {
                lis.emplace_back(obstacles[i]);
                ans[i] = (int)lis.size();
            } else {
                int it = bs(obstacles[i]);
                ans[i] = it + 1;
                lis[it] = obstacles[i];
            }
        }
        return ans;
    }
};
