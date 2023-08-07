/**
 * Title:  Search A 2D Matrix (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, August, 2023
 * Method: Binary search to search row, then the value (loop version)
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = matrix.size();
        int row = -1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target && matrix[mid][m - 1] >= target) {
                row = mid;
                break;
            }else if (matrix[mid][0] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (row == -1)
           row = (l == 0) ? 0 : l - 1;
        // cout << "search row: " << row << "\n";
        l = 0;
        r = matrix[0].size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
