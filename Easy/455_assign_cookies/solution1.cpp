/**
 * Title:  Assign Cookies (Leetcode Easy 455)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, Janurary, 2024
 * Result: Time complexity O(nlogn + mlogm), Space complexity O(1)
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(); // children
        int m = s.size(); // cookie
        int i = 0;
        int j = 0;
        int ans = 0; // content children
        while (i < n && j < m) {
            if (s[j] >= g[i]) {
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};
