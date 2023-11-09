/**
 * Title:  Count Number of Homogeneous Substrings (Leetcode Medium 1759)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, November, 2023
 */

class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        char last = 0;
        int last_count = 0;
        int mod = 1e9 + 7;
        for (const char& c: s) {
            if (c == last) {
                last_count++;
                ans = (ans + last_count) % mod;
            } else {
                ans += 1;
                last = c;
                last_count = 1;
            }
        }
        return ans;
    }
};

// a -> aa : + 2
// aa -> aaa : +3
// aaa -> aaaa: + 4
// aaaa -> aaaaa: + 5
