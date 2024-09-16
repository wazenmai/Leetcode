/**
 * Title:  Find the Longest Substring Containing Vowels in Even Counts (Leetcode Medium 1371)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, September, 2024
 * Method: Use bitmask to represent the state of vowels. If the number of vowels is even, the state is 0. Then find the maximum length that start and end at same state.
 */

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m; // bitmask: id
        m[0] = -1;
        int bitmask = 0;
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                bitmask ^= (1 << 4);
            } else if (s[i] == 'e') {
                bitmask ^= (1 << 3);
            } else if (s[i] == 'i') {
                bitmask ^= (1 << 2);
            } else if (s[i] == 'o') {
                bitmask ^= (1 << 1);
            } else if (s[i] == 'u') {
                bitmask ^= 1;
            }
            if (m.find(bitmask) == m.end()) {
                m[bitmask] = i;
            } else {
                ans = max(ans, i - m[bitmask]);
            }
        }
        return ans;
    }
};
// eleetminic  oworoep, 17
// 0123456789. 0123456

// - 00000
// 0 01000
// 1 01000
// 2 00000
// 3 01000
// 4 01000
// 5 01000
// 6 01100
// 7 01100
// 8 01000
// 9 01000

