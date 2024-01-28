/**
 * Title:  K Inverse Pairs Array (Leetcode Hard 629)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, Janurary, 2024
 * Method: DP. dp[i][j] = there are i numbsers with j inverse pairs.
    *      dp[i][j] = (take smallest number at first position) dp[i - 1][j] + (take 2nd smallest number at first position) dp[i - 1][j - 1] + ... + (take i-th smallest number at first position) dp[i - 1][j - i + 1]
    *      dp[i][j - 1] = dp[i - 1][j - 1] + dp[i - 1][j - 2] + ... + dp[i - 1][j - i]
    *      dp[i][j] = dp[i][j - 1] (check j > 0) + dp[i - 1][j] - dp[i - 1][j - i] (check j >= i)
 * Result: Time complexity O(NK). Space complexity O(NK)
 */

class Solution {
private:
    const int mod = 1e9+7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        //base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j] + (j > 0 ? dp[i][j - 1] : 0)) % mod;
                dp[i][j] = (dp[i][j] + mod - (j >= i ? dp[i - 1][j - i] : 0)) % mod;
            }
        }
        return dp[n][k];
    }
};

// dp[i][j]: number 1 ~ i, inverse_pair = j
// dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + ... + dp[i - 1][j - i + 1] (put least, put 2nd least)
// dp[i][j - 1] = dp[i - 1][j - 1] + dp[i - 1][j - 2] + dp[i - 1][j - i]
// dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - i]
// dp[1][0] = 1, dp[2][0]= 1, dp[3][0] = 1..., dp[n][0] = 1
//               dp[2][1]= 1, dp[3][1] = 2, dp[4][1]= 3
//                            dp[3][2] = 1, dp[4][2]= 2

// 0: 12
// 1; 21


// 0: 123,
// 1: 213, 132, 
// 2: 312, 231, 
// 3: 321

// 0: 1234
// 1: 2134, 1324,  1243
// 2: 2314, 3124,  1423, 1342, 2143, 
// 3: 3214, 4123,  1432, 2413, 1342, 3142
// 4: 4132, 4213,  2431, 3412, 3241
// 5: 4231, 4312,  3421
// 6: 4321

// 0: 12345
// 10: 54321
