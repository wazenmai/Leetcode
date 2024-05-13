/**
 * Title:  Score After Flipping Matrix (Leetcode Medium 861)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, May, 2024
 * Result: Time complexity O(nm), Space complexity O(1)
 */

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 1. Flip row if the first element is not 1
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) { // flip row
                for (int j = 0; j < m; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        // 2. Flip column if # of zero > half
        for (int j = 0; j < m; j++) {
            // conut column zero
            int zeros = 0;
            for (int i = 0; i < n; i++) {
                zeros += (grid[i][j] == 0);
            }
            if (zeros > n / 2) { // flip column
                for (int i = 0; i < n; i++) {
                    grid[i][j] ^= 1; // 1^1=0, 0^1=1
                }
            }
        }
        
        // 3. Sum the answer
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int base = 1;
            for (int j = m - 1; j >= 0; j--) {
                ans += grid[i][j] * base;
                base *= 2;
            }
        }
        return ans;
    }
};
