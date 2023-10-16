/**
 * Title:  Pascal's Triangle II (Leetcode Easy 119)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, October, 2023
 */

class Solution {
public:
    void printvec(vector<int> v) {
        for (int& e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        vector<int> pre(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            // cout << i << ": ";
            for (int j = 1; j < i; j++) {
                row[j] = pre[j - 1] + pre[j];
            }
            pre = row;
            // printvec(row);
        }
        return row;
    }
};
