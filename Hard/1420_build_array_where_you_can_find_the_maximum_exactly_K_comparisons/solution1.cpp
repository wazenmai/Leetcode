/**
 * Title:  Build Array Where You Can Find The Maximum Exactly K Comparisons (Leetcode Hard 1420)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, October, 2023
 * Method: Top-down DP
 * Result: Time complexity O(n * m^2 * k), Space complexity O(n * m * k)
 */

class Solution {
public:
    int dp(int i, int maxSoFar, int remain, vector<vector<vector<int>>>& memo, int n, int m) {
        // i:        the index we are going to fill in
        // maxSoFar: the maximum of the arr (0 ~ i - 1)
        // remain:   the number to fill in new maximum
        if (i == n) {
            if (remain == 0)
                return 1;
            return 0;
        }
        if (remain < 0)
            return 0;
        if (memo[i][maxSoFar][remain] != -1)
            return memo[i][maxSoFar][remain];
        
        long ans = (long)maxSoFar * dp(i + 1, maxSoFar, remain, memo, n, m);
        
        for (int num = maxSoFar + 1; num <= m; num++) {
            ans += dp(i + 1, num, remain - 1, memo, n, m);
        }
        ans %= 1000000007;
        // cout << "dp(" << i << "," << maxSoFar << "," << remain << "): " << ans << "\n";
        return memo[i][maxSoFar][remain] = (int)ans;
    }
    int numOfArrays(int n, int m, int k) {
        if (k > m)
            return 0;
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        return dp(0, 0, k, memo, n, m);
    }
};

// N: array 裡的數字個數，數字可以重複
// M: 數字範圍為 1 ~ m
// K: 遇到最大的數字所需花費的 cost

// DP[i][j][l]: 已經填了 i 個數字，最大的數字為 j，還需要再碰到 l 個 maximum
// i == n: 已經填了 n 個數字，如果 l == 0，表示已經碰到 l 個 maximum，return 1，否則 return 0
// l < 0: 表示已經碰到超過 k 個 maximum，但還沒填完 n 個數字，return 0
// 現在我們要填第 i 個數字，
    // 如果我們要填的數字不會超過目前的 maximum j, 我們有 j 個選擇 (1 ~ j)，可能有的組合則有 j * dp(i + 1, j, l) 種
    // 如果我們要填的數字超過 maximum j, 我們有 (j + 1 ~ m) 種選擇，假設我們填了 num, 那麼這選擇可能的組合會有 dp(i + 1, num, l - 1) 種
        // 因此我們還有 dp(i + 1, j + 1, l - 1) + dp(i + 1, j + 2, l - 1) + ... + dp(i + 1, m, l - 1) 種組合 
