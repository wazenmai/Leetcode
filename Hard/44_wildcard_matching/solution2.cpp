/**
 * Title:  Wildcard Matching (Leetcode Hard 44)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, December, 2024
 * Method: Use i, j to record the current position of s and p. Use star to record the position of the last star in p. Use p1 to record the position of the current string in s when we meet the star. If the current character is '?', we can match any character. If the current character is '*', we can match any string.  If we meet a mismatch, we can use the star to replace one character and try the process again.
 * Result: Time complexity O(n*m), Space complexity O(1).
 */

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        int n = s.length(), m = p.length();
        int i = 0, j = 0;
        int star = -1;
        int p1 = -1;
        while (i < n) {
            // cout << i << "," << j << "," << star << "," << p1 << "\n";
            if (j < m && (p[j] == '?' || p[j] == s[i])) { // match char
                i++;
                j++;
                continue;
            }
            if (j < m && (p[j] == '*')) { // record p's star pos and the current string pos
                star = j;
                j++;
                p1 = i;
                continue;
            }
            // cur not match
            if (star >= 0 && star < m) { // if we have met star before, we could use * to replace one chracter and try the process again
                j = star + 1;
                p1++;
                i = p1;
                continue;
            }
            // cur p is not at * + mismatch
            return false;
        }
        while (j < m && p[j] == '*') j++;
        return (j == m);
    }
};

// 01234567890
// abcabczzzde

// 0123456789
// *abc???de* 

// (0, 0) (a, *) -1, -1
// (0, 1, 0, 0) (a, a)
// (1, 2, 0, 0) (b, b)
// (2, 3, 0, 0) (c, c)
// 3,4,0,0
// 4,5,0,0
// 5,6,0,0
// 6,7,0,0 (z, d) -> 1, 1, 0, 1 
// 1,1,0,1 (b, a) -> 2,1,0,2 
// 2,1,0,2 (c, a) -> 3,1,0,3
// 3,1,0,3 (a, a)
// 
