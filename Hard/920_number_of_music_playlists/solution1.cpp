/**
 * Title:  Number of Music Playlists (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, August, 2023
 * Method: Bottom-Up DP, Time Complexity: O(goal * n), Space Complexity: O(goal * n)
 */

class Solution {
private:
    const int modulo = 1000000007;
public:
    int numMusicPlaylists(int n, int goal, int k) {
        long long int ans = 1;
        if (n == goal || k == n - 1) {
            ans = 1;
            while (n != 1) {
                ans = (ans * n) % modulo;
                n--;
            }
            return ans;
        }

        vector<vector<int>> dp(goal+1, vector<int>(n+1, 0));
        dp[0][0] = 1; // empty list
        for (int i = 1; i <= goal; i++) { // current length of playlist
            for (int j = 1; j <= min(i, n); j++) {
                // add song
                dp[i][j] = (int)(dp[i][j] + dp[i-1][j-1] * (long long)(n - j + 1) % modulo) % modulo;
                // replay old song
                if (j > k) {
                    dp[i][j] = (int)(dp[i][j] + dp[i-1][j] * (long long)(j - k) % modulo) % modulo;
                }
            }
        }

        return dp[goal][n];
    }
};

// State: dp[i][j]: # possible playlists of length i containing j unique songs
// Goal: dp[goal][n]
// Base case: dp[0][0] = 1 (empty list), for i < j, dp[i][j] = 0
// Transition: 
    // Add a song: dp[i][j] <- dp[i-1][j-1] # we have n - (j - 1) songs to add, so we have dp[i-1][j-1]*(n-j+1) choice to add
    // Replay an old song: dp[i][j] <- dp[i-1][j] # we have j unique songs, and we can't choose last k played songs, so we have j - k (if j > k) choices, so we can add dp[i-1][j] * (j-k)
// Time complexity: O(goal * n)
// Sapce complexity: O(goal * n)


// n = 2, goal = 3, k = 0
// [1,2,1] [1,2,2] [2,1,1] [2,1,2] + [1,1,2], [2,2,1]
// n = 2, goal = 4, k = 0
// 上面的 6 * 2(n) + [1,1,1,2], [2,2,2,1]
// n = 2, goal = 5, k = 0
// 上面的 14*2 = 28 + [1,1,1,1,2], [2,2,2,2,1]

// ---
// n = 3, goal = 3, k = 1, ans = 6
// [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
// n = 3, goal = 4, k = 1, ans = 6*2 + 6
// 6 * 2 + 6 (1取代3補3, 1取代2補2) = 18 [1,2,1,3] [1,3,1,2] [2,1,2,3] [2,3,2,1]
// [3,1,3,2] [3,2,3,1]
// n = 3, goal = 5, k = 1
// 18*2 [1,2,1,2] [2,1,2,1] +6, ans = 18*3 + 6

// n = 4, goal = 4, k = 2, ans = 24
// n = 4, goal = 5, k = 2, 24*3+24 = 72
// n = 4, goal = 6, k = 2, 72*3 + 24 
