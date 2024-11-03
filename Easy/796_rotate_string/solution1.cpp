/**
 * Title:  Rotate String (Leetcode Easy 796)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, November, 2024
 * Result: Time complexity O(n^2), space complexity O(1).
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if (n != goal.length()) return false;
        for (int i = 0; i < n; i++) {
            if (s[i] == goal[0]) {
                bool flag = true;
                for (int j = i; j < n; j++) {
                    if (s[j] != goal[j - i]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                for (int j = 0; j < i; j++) {
                    if (s[j] != goal[n - i + j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};
