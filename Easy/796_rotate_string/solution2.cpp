/**
 * Title:  Rotate String (Leetcode Easy 796)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, November, 2024
 * Method: KMP. Find goal in s + s.
 * Result: Time complexity O(n), space complexity O(n).
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        // Step 1. Concat s + s
        string ss = s + s;
        int n = ss.length();
        int m = goal.length();
        if (n != m * 2) return false;

        // Step 2. Compute lps of goal - longest proper prefix which is also a suffix
        vector<int> lps(m, 0);
        int len = 0; // length of lps
        for (int i = 1; i < m; i++) {
            while (len > 0 && goal[i] != goal[len]) {
                len = lps[len - 1];
            }
            if (goal[i] == goal[len]) {
                len++;
            }
            lps[i] = len;
        }
        // Step 3. Check whether goal in ss
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && ss[i] != goal[j]) {
                j = lps[j - 1];
            }
            if (ss[i] == goal[j]) {
                j++;
            }
            if (j == m) return true;
        }
        return false;
    }
};
