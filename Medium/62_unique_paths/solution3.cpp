/**
 * Title:  Unique Paths (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, August, 2023
 * Method: Combinatorics. Time Complexity O(n), Space Complexity O(1)
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int mod = 2e9;
        int N = m + n - 2;
        int r = (m - 1 < n - 1) ? m - 1 : n - 1;
        double res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};

// ans = (m-1 + n-1)! / (m-1)! (n-1)!
