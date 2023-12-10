/**
 * Title:  Transpose Matrix (Leetcode Easy 867)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, December, 2023
 */

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
               ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};