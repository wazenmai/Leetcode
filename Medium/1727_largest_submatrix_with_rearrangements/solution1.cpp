/**
 * Title:  Largest Submatrix with Rearrangements (Leetcode Medium 1727)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, November, 2023
 * Method: Count the consecutive 1s in each column, then iterate each row, sort the consecutive 1s in descending order, and calculate the area.
 * Result: Time complexity: O(nmlogm), Space complexity: O(1) or O(nm) since we modify the input.
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
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // cols
        // preprocess the cols
        for (int j = 0; j < m; j++) {
            int temp = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == 0) {
                    temp = 0;
                } else {
                    temp += 1;
                    matrix[i][j] = temp;
                }
            }
        }
        // print(matrix);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> temp = matrix[i];
            sort(temp.begin(), temp.end(), greater<int>());
            int height = 1e5;
            for (int j = 0; j < m; j++) {
                if (temp[j] == 0) {
                    break;
                } else {
                    height = min(height, temp[j]);
                    ans = max((j + 1) * height, ans);
                }
            }
        }
        return ans;
    }
};
