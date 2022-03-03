/**
 * Title:  Is Subsequence (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Mar, 2022
 * Method: Time O(N^2)
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = (int)t.length();
        int m = (int)s.length();
        if (m == 0)
            return true;
        if (n == 0)
            return false;
        
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (t[i] == s[0])
                q.push(i);
        
        while (!q.empty()) {
            int i = q.front();
            int j = 0;
            q.pop();
            while (i < n) {
                if (s[j] == t[i])
                    j++;
                i++;
                if (j == m)
                    return true;
            }
        }
        return false;
    }
};
