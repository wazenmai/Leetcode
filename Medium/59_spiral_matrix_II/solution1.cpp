/**
 * Title:  Spiral Matrix II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, April, 2022
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int num = 0, dir = 0; // 0r 1d 2l 3u
        while (num < n * n) {
            num++;
            v[i][j] = num;
            if (dir == 0) {
                if (j == n - 1 || v[i][j + 1] != 0) {
                    i++;
                    dir = 1;
                } else {
                    j++;
                }
            } else if (dir == 1) {
                if (i == n - 1 || v[i + 1][j] != 0) {
                    j--;
                    dir = 2;
                } else {
                    i++;
                }
            } else if (dir == 2) {
                if (j == 0 || v[i][j - 1] != 0) {
                    i--;
                    dir = 3;
                } else {
                    j--;
                }
            } else {
                if (v[i - 1][j] != 0) {
                    j++;
                    dir = 0;
                } else {
                    i--;
                }
            }
        }
        return v;
    }
};
