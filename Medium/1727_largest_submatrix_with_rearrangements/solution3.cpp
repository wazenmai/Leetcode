/**
 * Title:  Largest Submatrix with Rearrangements (Leetcode Medium 1727)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, November, 2023
 * Method: Use (height, col) pairs to store the consecutive 1s in each column, so that we do not need to sort the row everytime.
 * Result: Time complexity: O(nm), Space complexity: O(m).
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
        vector<pair<int, int>> prevHeights;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // cout << "row " << i << "\n";
            vector<pair<int, int>> heights;
            vector<bool> seen(m, false);
            
            for (auto [height, col]: prevHeights) {
                if (matrix[i][col] == 1) {
                    heights.emplace_back(make_pair(height + 1, col));
                    seen[col] = true;
                }
            }

            for (int j = 0; j < m; j++) {
                if (!seen[j] && matrix[i][j]) {
                    heights.emplace_back(make_pair(1, j));
                }
            }

            for (int k = 0; k < heights.size(); k++) {
                ans = max(ans, heights[k].first * (k + 1));
            }

            prevHeights = heights;
        }
        return ans;
    }
};
