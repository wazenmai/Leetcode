/**
 * Title:  Special Positions In A Binary Matrix (Leetcode Easy 1582)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, December, 2023
 * Method: Brute Force
 * Result: Time complexity O(mn(m+n)), Space complexity O(1)
 */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    bool pass = true;
                    for (int k = 0; k < m; k++) {
                        if (k != j && mat[i][k] == 1) {
                            pass = false;
                            break;
                        }
                    }
                    if (pass) {
                        for (int k = 0; k < n; k++) {
                            if (k != i && mat[k][j] == 1) {
                                pass = false;
                                break;
                            }
                        }
                    }
                    if (pass)
                        ans++;
                }
            }
        }
        return ans;
    }
};
