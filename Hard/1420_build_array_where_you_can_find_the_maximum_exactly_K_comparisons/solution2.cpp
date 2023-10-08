/**
 * Title:  Build Array Where You Can Find The Maximum Exactly K Comparisons (Leetcode Hard 1420)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, October, 2023
 * Method: Bottom-up DP
 * Result: Time complexity O(n * m^2 * k), Space complexity O(n * m * k)
 */

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k > m)
            return 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
        for (int i = 1; i <= m; i++) {
            dp[n][i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) { // the index we are going to fill in
            for (int j = m; j >= 0; j--) { // maximum so far
                for (int remain = 0; remain <= k; remain++) { // the number to fill in new maximum
                    long long ans = (long long) j * dp[i + 1][j][remain];
                    if (remain > 0) {
                        for (int num = j + 1; num <= m; num++) {
                            ans += dp[i + 1][num][remain - 1];
                        }
                    }
                    ans %= 1000000007;
                    // cout << i << "," << j << "," << remain << ": " << ans << "\n";
                    dp[i][j][remain] = (int)ans;
                }
            }
        }
        return dp[0][0][k];
    }
};

// N: array 裡的數字個數，數字可以重複
// M: 數字範圍為 1 ~ m
// K: 遇到最大的數字所需花費的 cost
// Time complexity: O(nm^2k)

// dp[i][j][l]: 從後面開始填，填到第 i 個數字，最大的數字為 j，還需要再碰到 l 個 maximum