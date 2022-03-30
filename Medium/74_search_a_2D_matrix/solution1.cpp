/**
 * Title:  Search a 2D Matrix (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, Mar, 2022
 * Method: Binary search to search row, then the value
 */


class Solution {
public:
    int bs_row(vector<vector<int>>& matrix, int target, int l, int r, int last) {
        // cout << "bs_row: " << l << " " << r << "\n";
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (matrix[mid][0] <= target && matrix[mid][last] >= target)
            return mid;
        if (matrix[mid][0] <= target)
            return bs_row(matrix, target, mid + 1, r, last);
        return bs_row(matrix, target, l, mid, last);
    }
    
    bool bs_value(vector<int>& row, int target, int l, int r) {
        if (l >= r)
            return false;
        int mid = (l + r) / 2;
        if (target == row[mid])
            return true;
        if (target < row[mid])
            return bs_value(row, target, l, mid);
        return bs_value(row, target, mid + 1, r);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int r = bs_row(matrix, target, 0, m, n - 1);
        if (r >= m)
            r = m - 1;
        if (r < 0)
            r = 0;
        // cout << "row: " << r << "\n";
        return bs_value(matrix[r], target, 0, n);
    }
};
