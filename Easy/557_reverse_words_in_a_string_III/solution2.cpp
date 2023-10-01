/**
 * Title:  Reverse Words In A String III (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, October, 2023
 * Method: Reverse word from start to end. Time O(N), Space O(1).
 */

class Solution {
public:
    string reverseWords(string s) {
        string news = "";
        int n = s.length();
        int start = -1;
        int end = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ' && start == -1) {
                start = i;
            } else if (s[i] == ' ') {
                end = i - 1;
                while (start < end) {
                    char temp = s[start];
                    s[start] = s[end];
                    s[end] = temp;
                    start++;
                    end--;
                }
                start = end = -1;
            }
        }
        if (start != -1) {
            end = n - 1;
            while (start < end) {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
        }
        return s;
    }
};
