/**
 * Title:  Difference Between Ones and Zeros in Row and Column (Leetcode Medium 2482)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, December, 2023
 * Method: Naive solution
 * Result: Time complexity O(mn), Space complexity O(n + m)
 */

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> onesRow(n, 0);
        vector<int> onesCol(m, 0);
        vector<int> zerosRow(n, 0);
        vector<int> zerosCol(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    onesRow[i]++;
                    onesCol[j]++;
                } else {
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        return ans;
    }
};
