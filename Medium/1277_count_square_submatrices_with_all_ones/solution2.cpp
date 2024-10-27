/**
 * Title:  Count Square Submatrices with All Ones (Leetcode Medium 1277)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, October, 2024
 * Method: DP optimization. Optimzie to only use two vectors to store the current and previous row.
 * Result: Time complexity O(nm). Space complexity O(m).
 */

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int> cur(m + 1, 0);
        vector<int> pre(m + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    cur[j + 1] = min(min(pre[j], pre[j + 1]), cur[j]) + 1;
                    ans += cur[j + 1];
                } else {
                    cur[j + 1] = 0;
                }
            }
            pre = cur;
        }
        return ans;
    }
};
