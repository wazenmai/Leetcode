/**
 * Title:  Rotating the Box (Leetcode Medium 1861)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, November, 2024
 * Method: First rotate the box 90 degrees clockwise, then simulate the falling of stones.
 * Result: Time complexity O(n * m), Space complexity O(n * m).
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = box[n - 1  - j][i];
            }
        }
        for (int j = 0; j < n; j++) { // iterate through column
            int pos = m - 1;
            for (int i = m - 1; i >= 0; i--) {
                if (ans[i][j] == '*') {
                    pos = i - 1;
                } else if (ans[i][j] == '#') {
                    if (pos >= i) {
                        ans[i][j] = '.';
                        ans[pos][j] = '#';
                        pos--;
                    }
                    while (pos >= 0 && ans[pos][j] == '*') {
                        pos--;
                    }
                }
            }
        }
        return ans;
    }
};

// 0123. [0,0] -> [0, m], [0, 1] -> [1, m], [0, m] -> [m, n]
// 4567. [n, 0] -> [0, 0], [n, 1] -> [1, 0], [n, m] -> [n, 0]
// xoei

// x40
// o51
// e62
// o73

// (0,0) = (2,0), (1,0)=(2,1), (2,0)=(2,2), (3,0)=(2,3)
// (0,1) = (1,0)
// (0,2) = (0,0)