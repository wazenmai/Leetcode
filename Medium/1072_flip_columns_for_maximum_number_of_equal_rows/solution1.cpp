/**
 * Title:  Flip Columns For Maximum Number of Equal Rows (Leetcode Medium 1072)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, November, 2024
 * Method: Check whether other row is the same or completely opposite to the current row using xor operation.
 * Result: Time complexity O(n^2 * m), Space complexity O(n^2). // n = # of rows, m = # of columns
 */

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (n == 1) return m;
        vector<vector<int>> xor_check(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) { // iterate through every row
            for (int j = i + 1; j < m; j++) { // iterate through it partner row
                int all_one = 1; // xor all = 1
                int all_zero = 1;
                for (int k = 0; k < n; k++) { // iterate through every element
                    if ((matrix[i][k] ^ matrix[j][k]) != 1) {
                        all_one = 0;
                    }
                    if ((matrix[i][k] ^ matrix[j][k]) != 0) {
                        all_zero = 0;
                    }
                }
                xor_check[i][j] = xor_check[j][i] = all_one + all_zero;
            }
        }
        int ans = 1;
        for (int i = 0; i < m; i++) {
            int cnt = 1;
            for (int j = 0; j < m; j++) {
                cnt += xor_check[i][j];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// 000 ->110
// 001 ->111
// 110 ->000

// 01
// 11

// 01
// 10


// 0101000
// 1010111
// 1001100
// [[1,0,0,0,1,1,1,0,1,1,1],
//. [1,0,0,0,1,0,0,0,1,0,0],
//. [1,0,0,0,1,1,1,0,1,1,1],
//. [1,0,0,0,1,0,0,0,1,0,0],
//. [1,1,1,0,1,1,1,0,1,1,1]]

// [[1,1],
//. [0,1],
//. [1,0],
//. [0,0],
//. [1,0],
//. [1,0],
//. [0,1],
//. [1,0],
//. [0,0],
//. [1,0]]