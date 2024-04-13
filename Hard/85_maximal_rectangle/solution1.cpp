/**
 * Title:  Maximum Rectangle (Leetcode Hard 85)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, April, 2024
 * Method: Use an array to record the height of the rectangle. Iterate from the left to right and calculate the maximum rectangle size.
 * Result: Time complexitty is O(nm^2), space complexity is O(m). n = matrix.size(), m = matrix[0].size().
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[j] = (matrix[i][j] == '1') ? dp[j] + 1 : 0;
            }

            for (int bar = 0; bar < m; bar++) { // as leftmost side
                int minHeight = INT_MAX;
                for (int j = bar; j < m; j++) { // extend to the right
                    minHeight = min(dp[j], minHeight);
                    ans = max(minHeight * (j - bar + 1), ans);
                }
            }
        }
        return ans;
    }
};
