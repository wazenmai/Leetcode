/**
 * Title:  Get Equal Substrings Within Budget (Leetcode Medium 1208)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, May, 2024
 * Method: Use prefix sum to calculate the cost of each substring.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    void print(vector<int>& v) {
        for (auto& num: v) {
            cout << num << " ";
        }
        cout << "\n";
    }
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> cost(n+1, 0);
        cost[1] = abs(s[0] - t[0]);
        for (int i = 1; i < n; i++) {
            cost[i + 1] = abs(s[i] - t[i]) + cost[i];
        }
        // print(cost);
        int l = 0;
        for (int i = 1; i <= n; i++) {
            while (++l) {
                if (i - l < 0) {
                    l -= 1;
                    break;
                }
                int c = cost[i] - cost[i - l];
                if (c > maxCost) {
                    l -= 1;
                    break;
                }
            }
        }
        return l;
    }
};
