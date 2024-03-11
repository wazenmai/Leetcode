/**
 * Title:  Custom Sort String (Leetcode Medium 791)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, March, 2024
 * Method: Use vector to store the freq. of each char in s since it would only have 26 chars.
 */

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26, 0);
        for (char c: s) {
            cnt[c-'a']++;
        }
        string ans = "";
        for (char c: order) {
            while (cnt[c - 'a'] > 0) {
                ans += c;
                cnt[c - 'a']--;
            } 
        }
        for (int i = 0; i < 26; i++) {
            while (cnt[i] > 0) {
                char c = 'a' + i;
                ans += c;
                cnt[i]--;
            }
        }
        return ans;
    }
};
