/**
 * Title:  Get Equal Substrings Within Budget (Leetcode Medium 1208)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, May, 2024
 * Method: Tidy the code.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> cost(n+1, 0);
        cost[1] = abs(s[0] - t[0]);
        for (int i = 1; i < n; i++) {
            cost[i + 1] = abs(s[i] - t[i]) + cost[i];
        }
        int l = 0;
        for (int i = 1; i <= n; i++) {
            l += 1;
            while (i - l >= 0) {
                int c = cost[i] - cost[i - l];
                if (c > maxCost) {
                    break;
                }
                l++;
            }
            l -= 1;
        }
        return l;
    }
};
