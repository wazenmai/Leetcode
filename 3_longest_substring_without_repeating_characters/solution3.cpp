/**
 * Title:  Longest Substring Without Repeating Characters (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, Jan, 2021
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int n = s.length();
        int j = -1;
        vector<bool> visit(128, false); // use 16 char (16 * 8 bits), bool vector is faster than bool array
        for (int i = 0; i < n; i++) {
            // j will stop infront of repeating character
            while(j < n - 1 && !visit[s[j + 1]]) {
                visit[s[j + 1]] = true;
                j++;
            }
            // encounter repeating character or run to the end
            max_length = max(max_length, j - i + 1);
            visit[s[i]] = false;
        }
        return max_length;
    }
};