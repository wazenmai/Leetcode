/**
 * Title:  Minimum Window Substring (Leetcode Hard 76)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, February, 2024
 * Method: Sliding window, two pointers. Increase r until the window satisfies the condition, then increase l until the window doesn't satisfy the condition.
 * Result: Time complexity O(n + m), space complexity O(1)
 */

class Solution {
public:
    bool isUpper(char c) {
        if (c >= 'A' && c <= 'Z') return true;
        return false;
    }
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (m > n) return "";

        vector<int> target(52, 0); // A ~ Z & a ~ z
        for (char& c: t) {
            if (c >= 'A' && c <= 'Z') {
                target[c - 'A']++;
            } else {
                target[c - 'a' + 26]++;
            }
        } 

        int l = 0, r = -1; // s[l ~ r]
        vector<int> cnt(52, 0);
        int formed = 0; // # of characters satisfying t
        int ans[2] = {0, -1}; // left, length
        while (++r < n) {
            int id = isUpper(s[r]) ? s[r] - 'A' : s[r] - 'a' + 26;
            cnt[id]++;
            if (target[id] > 0 && target[id] >= cnt[id]) {
                formed++;
            }

            while (l <= r && formed == m) {
                if (ans[1] == -1 || r - l + 1 < ans[1]) {
                    ans[0] = l;
                    ans[1] = r - l + 1;
                }
                id = isUpper(s[l]) ? s[l] - 'A' : s[l] - 'a' + 26;
                cnt[id]--;
                if (target[id] > 0 && cnt[id] < target[id]) {
                    formed--;
                }
                l++;
            }
        }
        return (ans[1] == -1) ? "" : s.substr(ans[0], ans[1]);
    }
};
