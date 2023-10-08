/**
 * Title:  Build Array Where You Can Find The Maximum Exactly K Comparisons (Leetcode Hard 1420)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, October, 2023
 * Method: Bottom-up DP with memory optimization
 * Result: Time complexity O(n * m^2 * k), Space complexity O(m * k)
 */

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k > m)
            return 0;
        vector<vector<int>> dp(m+1, vector<int>(k+1, 0));
        vector<vector<int>> prev(m+1, vector<int>(k+1, 0));
        for (int i = 1; i <= m; i++) {
            prev[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) { // the index we are going to fill in
            dp = vector(m+1, vector<int>(k+1, 0));
            for (int j = m; j >= 0; j--) { // maximum so far
                for (int remain = 0; remain <= k; remain++) { // the number to fill in new maximum
                    long long ans = (long long) j * prev[j][remain];
                    if (remain > 0) {
                        for (int num = j + 1; num <= m; num++) {
                            ans += prev[num][remain - 1];
                        }
                    }
                    ans %= 1000000007;
                    // cout << i << "," << j << "," << remain << ": " << ans << "\n";
                    dp[j][remain] = (int)ans;
                }
            }
            prev = dp;
        }
        return dp[0][k];
    }
};

// N: array 裡的數字個數，數字可以重複
// M: 數字範圍為 1 ~ m
// K: 遇到最大的數字所需花費的 cost
