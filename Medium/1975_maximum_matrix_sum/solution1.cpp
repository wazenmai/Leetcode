/**
 * Title:  Maximum Matrix Sum (Leetcode Medium 1975)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, November, 2024
 * Method: Since we can flip the sign of any two adjacent elements, if there are odd number of negative sign, we will left the only one negative number in the matrix, and we can left the smallest absolute number be the negative.
 *         If there are even number of negative sign, we can flip all the number to positive.
 * Result: Time complexity is O(nm). Space complexity O(1).
 */

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negative = 0;
        int min_num = 1e5;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) negative--;
                min_num = min(min_num, abs(matrix[i][j]));
            }
        }
        if (negative & 1) {
            return sum - min_num - min_num;
        }
        return sum;
    }
};
