/**
 * Title:  Magic Squares In Grid (Leetcode Medium 840)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, August, 2024
 * Result: Time complexity O(nm), Space complexity O(1).
 */

class Solution {
private:
    int n;
    int m;
public:
    bool checkNum(vector<vector<int>>& grid, int row, int col) {
        vector<int> cnt(10, 0);
        if (row + 3 > n || col + 3 > m) return false;
        for (int ii = row; ii < row + 3; ii++) {
            for (int jj = col; jj < col + 3; jj++) {
                int num = grid[ii][jj];
                if (num > 9 || num == 0) return false;
                cnt[num]++;
                if (cnt[num] > 1) return false;
            }
        }
        return true;
    }
    bool checkSum(vector<vector<int>>& grid, int i, int j) {
        int row1 = 0, row2 = 0, row3 = 0;
        int col1 = 0, col2 = 0, col3 = 0;
        int diag1 = 0, diag2 = 0;
        for (int k = 0; k < 3; k++) {
            row1 += grid[i][j + k];
            row2 += grid[i + 1][j + k];
            row3 += grid[i + 2][j + k];
            col1 += grid[i + k][j];
            col2 += grid[i + k][j + 1];
            col3 += grid[i + k][j + 2];
            diag1 += grid[i + k][j + k];
            diag2 += grid[i + 2 - k][j + 2 - k];
        }
        if ((row1 == row2) && (row2 == row3) && (row3 == col1) && (col1 == col2) && (col2 == col3) && (col3 == diag1) && (diag1 == diag2))
            return true;
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (n < 3 || m < 3) return 0;
        
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (!checkNum(grid, i, j))
                    continue;
                if (checkSum(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};
