/**
 * Title:  Find the Length of the Longest Common Prefix (Leetcode Medium 3043)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, September, 2024
 * Result: TLE. Time complexity O(nmd), d is the maximum length of the number in the array.
 */

class Solution {
public:
    string findCommonPrefix(int& x, int& y) {
        string sx = to_string(x);
        string sy = to_string(y);
        string common = "";
        int nx = sx.length();
        int ny = sy.length();
        for (int k = 0; k < nx, k < ny; k++) {
            if (sx[k] != sy[k]) break;
            common += sx[k];
        }
        return common;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        int n = arr1.size();
        int m = arr2.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string common = findCommonPrefix(arr1[i], arr2[j]);
                ans = max(ans, (int)common.length());
            }
        }
        return ans;
    }
};
