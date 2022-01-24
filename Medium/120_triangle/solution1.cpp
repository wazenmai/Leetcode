/**
 * Title:  Triangle (Leetcode Medium 120)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   3, May, 2021
 */

class Solution {
private:
    vector<vector<long long>> dp;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<long long> temp;
        int height = triangle.size();
        int width, min_value;
        temp.emplace_back(triangle[0][0]);
        dp.emplace_back(temp);
        for (int i = 1; i < height; i++) {
            temp.clear();
            width = triangle[i].size();
            for (int j = 0; j < width; j++) {
                if (j == 0) {
                    temp.emplace_back(triangle[i][j] + dp[i-1][0]);
                } else if (j == width - 1) {
                    temp.emplace_back(triangle[i][j] + dp[i-1][j-1]);
                } else {
                    temp.emplace_back(triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]));
                }
            }
            dp.emplace_back(temp);
        }
        int ans = 1e9;
        for (auto& num : temp) {
            if (num < ans)
                ans = num;
        }
        return (height == 1) ? triangle[0][0] : ans;
    }
};
