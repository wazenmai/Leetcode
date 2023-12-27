/**
 * Title:  Minimum Time To Make Rope Colorful (Leetcode Medium 1578)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, December, 2023
 * Method: We do not want to remove balloon with maximum time, so when we meet the same color, we record the maxtime and the accumulative time.
    *          When we meet a different color, we add the accumulative time minus the maxtime to the answer.
 * Result: Time complexity O(n), space complexity O(1)
 */

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        char last = colors[0];
        int ans = 0;
        int time = neededTime[0];
        int maxtime = time;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                time += neededTime[i];
                maxtime = max(maxtime, neededTime[i]);
                cnt++;
            } else {
                if (cnt > 1) {
                    ans += time - maxtime;
                }
                time = maxtime = neededTime[i];
                cnt = 1;
            }
        }
        if (cnt > 1) {
            ans += time - maxtime;
        }
        return ans;
    }
};
