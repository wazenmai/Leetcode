/**
 * Title:  Find Longest Special Substring That Occurs Thrice I (Leetcode Medium 2981)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, December, 2024
 * Method: Use unordered_map to record the occurance of string, if occurance >= 3, update the answer.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> m;
        int n = s.length();
        int rep = 1;
        m[s.substr(0, 1)]++;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                rep++;
                string temp = "";
                for (int j = 1; j <= rep; j++) {
                    temp += s[i];
                    m[temp]++;
                    if (m[temp] >= 3) {
                        ans = max(ans, j);
                    }
                }
            } else {
                rep = 1;
                string c = s.substr(i, 1);
                m[c]++;
                if (m[c] >= 3) {
                    ans = max(ans, 1);
                }
            }
        }
        return (ans == 0) ? -1 : ans;
    }
};
