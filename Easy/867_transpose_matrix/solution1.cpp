/**
 * Title:  Transpose Matrix (Leetcode Easy 867)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, December, 2023
 */

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int j = 0; j < m; j++) {
            vector<int> v(n);
            for (int i = 0; i < n; i++) {
                v[i] = matrix[i][j];
            }
            ans.emplace_back(v);
        }
        return ans;
    }
};
