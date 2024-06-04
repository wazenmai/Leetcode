/**
 * Title:  Longest Palindrome (Leetcode Easy 409)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, June, 2024
 */

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(52, 0); // a-z, A-Z
        for (auto& c: s) {
            if (c >= 'a' && c <= 'z') {
                cnt[c - 'a']++;
            } else {
                cnt[c - 'A' + 26]++;
            }
        }
        int ans = 0;
        int center = 0;
        for (int i = 0; i < 52; i++) {
            if (cnt[i] & 1) {
                center = 1;
                ans += (cnt[i] - 1);
            } else {
                ans += cnt[i];
            }
        }
        return ans + center;
    }
};
