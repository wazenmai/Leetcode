/**
 * Title:  Convert 1D Array Into 2D Array (Leetcode Easy 2022)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, September, 2024
 */

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = original[i * n + j];
            }
        }
        return ans;
    }
};
