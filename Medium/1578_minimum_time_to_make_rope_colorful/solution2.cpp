/**
 * Title:  Minimum Time To Make Rope Colorful (Leetcode Medium 1578)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, December, 2023
 * Method: prev is the index of the last different color with max neededTime. If neededTime[i] > neededTime[prev], we add neededTime[prev] to the answer and set prev = i.
    *      Otherwise, we add neededTime[i] to the answer.
 * Result: Time complexity O(n), space complexity O(1)
 */

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans = 0;
        int prev = 0;
        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[prev]) {
                prev = i;
            } else {
                if (neededTime[i] > neededTime[prev]) {
                    ans += neededTime[prev];
                    prev = i;
                } else {
                    ans += neededTime[i];
                }
            }
        }
        return ans;
    }
};
