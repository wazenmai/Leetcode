/**
 * Title:  Build Array Where You Can Find The Maximum Exactly K Comparisons (Leetcode Hard 1420)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, October, 2023
 * Method: 
 * Result: Time complexity O(n * m * k), Space complexity O(n * m * k)
 */

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k > m)
            return 0;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
        vector<vector<vector<int>>> prefix(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
        int mod = 1000000007;

        // Set base case
        for (int i = 1; i <= m; i++) {
            dp[1][i][1] = 1;
            prefix[1][i][1] = prefix[1][i - 1][1] + 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) { // maxNum
                for (int cost = 1; cost <= k; cost++) {
                    // cout << i << "," << j << "," << cost << "\n";
                    long long ans = ((long long)j * dp[i - 1][j][cost]) % mod;
                    ans = (ans + prefix[i - 1][j - 1][cost - 1]) % mod;
                    dp[i][j][cost] = (int)(dp[i][j][cost] + ans) % mod;
                    prefix[i][j][cost] = (prefix[i][j - 1][cost] + dp[i][j][cost]) % mod;
                }
            }
        }
        return prefix[n][m][k];
    }
};

// N: array 裡的數字個數，數字可以重複
// M: 數字範圍為 1 ~ m
// K: 遇到最大的數字所需花費的 cost

// (i, maxSoFar, remain)
// i:        we have placed i elements so far
// maxSoFar: the maximum element we placed so far
// remain:   we must place `remain` more new maximums.

// i: the array of length i
// maxNum: the maximum element in this array is maxNum
// cost: we will encounter `cost` new maximums

// New Dp[i][j][l] = 已經填入 i 個數字，最大值為 j，還需要再碰到 l 個 maximum，這樣的組合數有多少
// condition 1. 上一次加入的數字沒有更新 maximum (1 ~ j), 這樣的組合數有 j * dp[i - 1][j][l] 種
// condition 2. 上一次加入的數字是一個新的 maximum (也就是現在的 j), 而上一個 maximum 有可能是 (1 ~ j - 1) 之間的任何一個數字 (num),
//              我們可能從 dp[i - 1][1 ~ j - 1][l - 1] 這些狀態中的任一個轉移到這裡，因此目前的組合數會有
//              dp[i - 1][1][l - 1] + dp[i - 1][2][l - 1] + ... + dp[i - 1][j - 1][l - 1] 種
// 針對 condition 2, 我們可以先算好 prefix[i - 1][j][l - 1] = dp[i - 1][1 ~ j][l - 1] 的 prefix sum，