/**
 * Title:  Largest Submatrix with Rearrangements (Leetcode Medium 1727)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, November, 2023
 * Method: Use curRow and prevRow to store the consecutive 1s in each column, so that we do not need to modify the input.
 * Result: Time complexity: O(nmlogm), Space complexity: O(m).
 */

class Solution {
public:
    void print(vector<vector<int>>& m) {
        for (auto& v: m) {
            for (auto& e: v) {
                cout << e << " ";
            }
            cout << "\n";
        }
    }
    void print(vector<int>& v) {
        for (auto& e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // cols

        int ans = 0;
        vector<int> prevRow(m, 0);
        vector<int> curRow(m, 0);
        for (int i = 0; i < n; i++) {
            cout << "row " << i << "\n";
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]) {
                    curRow[j] = prevRow[j] + 1;
                } else {
                    curRow[j] = 0;
                }
            }
            prevRow = curRow;
            // print(curRow);
            vector<int> temp = curRow;
            sort(temp.begin(), temp.end(), greater<int>());
            int height = 1e5;
            for (int j = 0; j < m; j++) {
                if (temp[j] == 0) {
                    break;
                } else {
                    height = min(height, temp[j]);
                    ans = max((j + 1) * height, ans);
                    // cout << j << ", " << height << ", " << ans << "\n";
                }
            }
            // cout << ans << "\n";
        }
        return ans;
    }
};
