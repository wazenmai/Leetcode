/**
 * Title:  Grumpy Bookstore Owner (Leetcode Medium 1052)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, June, 2024
 * Method: Sliding window to find the maximum satisfied customers.
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        // If magic use at minute 0
        for (int j = 0; j < minutes; j++) ans += customers[j];
        for (int j = minutes; j < n; j++) {
            if (grumpy[j] == 0) ans += customers[j];
        }
        int round = n - minutes; // # of timepoint we can use magic
        int satisfy = ans;
        for (int i = 1; i <= round; i++) {
            if (grumpy[i - 1] == 1) {
                satisfy -= customers[i - 1];
            }
            if (grumpy[i + minutes - 1] == 1) {
                satisfy += customers[i + minutes - 1];
            }
            ans = max(ans, satisfy);
        }
        return ans;
    }
};
