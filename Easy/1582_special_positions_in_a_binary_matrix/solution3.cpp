/**
 * Title:  Special Positions In A Binary Matrix (Leetcode Easy 1582)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, December, 2023
 * Method: Precompute ones in each row and column, and reuse it to compute the answer
 * Result: Time complexity O(mn), Space complexity O(n + m)
 */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (row[i] == 1) {
                for (int j = 0; j < m; j++) {
                    if (col[j] == 1 && mat[i][j] == 1) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
