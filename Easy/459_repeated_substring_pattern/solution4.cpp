/**
 * Title:    Repeated Substring Pattern (Leetcode Easy)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     21, August, 2023
 * Method:   Here I implement the KMP algorithm to find whether t contains s.
 *           We need to first compute s's longest proper prefix suffix array (LPS), then when matching t and s, if t[i] != s[j], we can jump to s's LPS[j-1] to continue matching.
 * Analysis: O(N)
 */

class Solution {
public:
    void computeLPS(string p, int M, int* lps) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M) {
            if (p[i] == p[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    len = lps[len - 1];
                }
            }
        }
    }
    int KMP(string s, string p) {
        int n = s.length();
        int m = p.length();
        int lps[m];
        computeLPS(p, m, lps);

        int i = 0, j = 0;
        while ((n - i) >= (m - j) && j < m) {
            // cout << "cmp (" << i << "," << s[i] << ") and (" << j << "," << p[j] << ")\n";
            if (s[i] == p[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        if (j >= m)
            return i;
        return -1;
    }
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if (KMP(t.substr(1, t.size() - 2), s) != -1)
            return true;
        return false;
    }
};
