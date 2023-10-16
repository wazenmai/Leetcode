/**
 * Title:  Pascal's Triangle II (Leetcode Easy 119)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, October, 2023
 * Method: Bottom-up Dp with memory optimization, only save 1 number instead of a vector.
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        int pre = 1;
        for (int i = 2; i <= rowIndex; i++) {
            pre = row[1];
            row[1] = row[0] + row[1];
            for (int j = 2; j < i; j++) {
                int temp = row[j];
                row[j] = pre + row[j];
                pre = temp;
            }
        }
        return row;
    }
};
