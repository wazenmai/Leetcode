/**
 * Title:  Image Smoother (Leetcode Easy 661)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, December, 2023
 * Method: Tidy the code and check inside the loop
 */

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                int cnt = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int ny = i + dy;
                        int nx = j + dx;
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                            continue;
                        sum += img[ny][nx];
                        cnt++;
                    }
                }
                ans[i][j] = floor(sum / cnt);
            }
        }
        return ans;
    }
};
