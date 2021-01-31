/**
 * Title:  Longest Substring Without Repeating Characters (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, Jan, 2021
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int max_length = 0;
        int n = s.length();
        bool visit[128] = {false};
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            visit[s[i]] = true;
            length = 1;
            while (true) {
                if (j >= n)
                    break;
                if (visit[s[j]]) {
                    break;
                }
                visit[s[j]] = true;
                length += 1;
                j++;
            }
            max_length = max(length, max_length);
            for (j = 0; j < 128; j++)
                visit[j] = false;
        }
        return max_length;
    }
};