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
        int j = 1;
        for (int i = 0; i < n; i++) {
            visit[s[i]] = true;
            j = i + 1;
            length = 1;
            while (true) {
                if (j >= n)
                    break;
                while (visit[s[j]]) {
                    max_length = max(length, max_length);
                    length -= 1;
                    if (s[i] == s[j]) {
                        i++;
                        break;
                    } else {
                        visit[s[i]] = false;
                        i++;
                    }
                }
                visit[s[j]] = true;
                length += 1;
                j++;
            }
            max_length = max(length, max_length);
            visit[s[i]] = false;
        }
        return max_length;
    }
};