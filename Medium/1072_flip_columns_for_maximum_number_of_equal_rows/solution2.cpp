/**
 * Title:  Flip Columns For Maximum Number of Equal Rows (Leetcode Medium 1072)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, November, 2024
 * Method: Record the flip bit by bitset<> and use unordered_map to store the frequency of the flip.
 * Result: Time complexity O(nm), Space complexity O(n). // n = # of rows, m = # of columns
 */

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<bitset<300>, int> freq;
        int ans = 1;
        for (int i = 0; i < m; i++) {
            bitset<300> flip_op;
            flip_op.set(0);
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] != matrix[i][j]) {
                    flip_op.flip(j);
                }
            }
            freq[flip_op]++;
            ans = max(ans, freq[flip_op]);
        }
        return ans;
    }
};
