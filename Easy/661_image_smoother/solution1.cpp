/**
 * Title:  Image Smoother (Leetcode Easy 661)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, December, 2023
 * Method: Deal with different special cases.
 */

class Solution {
public:
    void print(int y, int x, int val) {
        cout << "(" << y << "," << x << "): " << val << "\n";
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        // Special case 1: (1, 1)
        if (n == 1 && m == 1) return img;
        // Special case 2: (1, m) or (n, 1)
        if (n == 1) { // one row
            ans[0][0] = floor((img[0][0] + img[0][1]) / 2);
            ans[0][m - 1] = floor((img[0][m - 1] + img[0][m - 2]) / 2);
            for (int j = 1; j < m - 1; j++) {
                ans[0][j] = floor((img[0][j - 1] + img[0][j] + img[0][j + 1]) / 3);
            }
            return ans;
        }
        if (m == 1) { // one column
            ans[0][0] = floor((img[0][0] + img[1][0]) / 2);
            ans[n - 1][0] = floor((img[n - 1][0] + img[n - 2][0]) / 2);
            for (int i = 1; i < n - 1; i++) {
                ans[i][0] = floor((img[i - 1][0] + img[i][0] + img[i + 1][0]) / 3);
            }
            return ans;
        }
        // 4 corner (0, 0) (0, m - 1) (n - 1, 0) (n - 1, m - 1)
        ans[0][0] = floor((img[0][0] + img[0][1] + img[1][0] + img[1][1]) / 4);
        ans[0][m - 1] = floor((img[0][m - 1] + img[0][m - 2] + img[1][m - 1] + img[1][m - 2]) / 4);
        ans[n - 1][0] = floor((img[n - 1][0] + img[n - 2][0] + img[n - 1][1] + img[n - 2][1]) / 4);
        ans[n - 1][m - 1] = floor((img[n - 1][m - 1] + img[n - 1][m - 2] + img[n - 2][m - 1] + img[n - 2][m - 2]) / 4);

        // 4 side (i = 0) (i = n - 1) (j = 0) (j = m - 1)
        for (int j = 1; j < m - 1; j++) {
            ans[0][j] = floor((img[0][j - 1] + img[0][j] + img[0][j + 1] + img[1][j - 1] + img[1][j] + img[1][j + 1]) / 6);
            ans[n - 1][j] = floor((img[n - 1][j - 1] + img[n - 1][j] + img[n - 1][j + 1] + img[n - 2][j - 1] + img[n - 2][j] + img[n - 2][j + 1]) / 6);
        }
        for (int i = 1; i < n - 1; i++) {
            ans[i][0] = floor((img[i - 1][0] + img[i][0] + img[i + 1][0] + img[i - 1][1] + img[i][1] + img[i + 1][1]) / 6);
            ans[i][m - 1] = floor((img[i - 1][m - 1] + img[i][m - 1] + img[i + 1][m - 1] + img[i - 1][m - 2] + img[i][m - 2] + img[i + 1][m - 2]) / 6);
        }
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                ans[i][j] = floor((img[i - 1][j - 1] + img[i - 1][j] + img[i - 1][j + 1] + img[i][j - 1] + img[i][j] + img[i][j + 1] + img[i + 1][j - 1] + img[i + 1][j] + img[i + 1][j + 1]) / 9);
            }
        }
        return ans;
    }
};
